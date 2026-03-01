#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <notification/notification_messages.h>
#include <stdio.h>

typedef struct {
    uint8_t hunger;   // 0..100
    uint8_t boredom;  // 0..100
    uint32_t last_tick;
    bool running;

    NotificationApp* notifications;
} ChaosPetApp;

static uint8_t clamp_u8(int v, int lo, int hi) {
    if(v < lo) return (uint8_t)lo;
    if(v > hi) return (uint8_t)hi;
    return (uint8_t)v;
}

static void draw_callback(Canvas* canvas, void* ctx) {
    ChaosPetApp* app = ctx;

    canvas_clear(canvas);
    canvas_draw_str(canvas, 10, 10, "CHAOS PET");

    // Face based on state
    if(app->hunger == 0) {
        canvas_draw_str(canvas, 30, 30, "(X_X)");
    } else if(app->boredom > 70) {
        canvas_draw_str(canvas, 30, 30, "(>_<)");
    } else if(app->hunger < 30) {
        canvas_draw_str(canvas, 30, 30, "(ಠ_ಠ)");
    } else {
        canvas_draw_str(canvas, 30, 30, "(^_^)");
    }

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "H:%u B:%u", app->hunger, app->boredom);
    canvas_draw_str(canvas, 10, 55, buffer);

    canvas_draw_str(canvas, 10, 25, "OK=feed  LEFT=play");
    canvas_draw_str(canvas, 10, 35, "BACK=exit");
}

static void input_callback(InputEvent* event, void* ctx) {
    ChaosPetApp* app = ctx;
    if(event->type != InputTypePress) return;

    if(event->key == InputKeyBack) {
        app->running = false;
        notification_message(app->notifications, &sequence_blink_red_100);
        return;
    }

    if(event->key == InputKeyOk) {
        app->hunger = clamp_u8(app->hunger + 15, 0, 100);
        notification_message(app->notifications, &sequence_blink_green_100);
    } else if(event->key == InputKeyLeft) {
        app->boredom = clamp_u8((int)app->boredom - 20, 0, 100);
        notification_message(app->notifications, &sequence_blink_blue_100);
    }
}

int32_t chaos_pet_app(void* p) {
    UNUSED(p);

    ChaosPetApp app = {
        .hunger = 100,
        .boredom = 0,
        .last_tick = furi_get_tick(),
        .running = true,
        .notifications = furi_record_open(RECORD_NOTIFICATION),
    };

    Gui* gui = furi_record_open(RECORD_GUI);
    ViewPort* view_port = view_port_alloc();

    view_port_draw_callback_set(view_port, draw_callback, &app);
    view_port_input_callback_set(view_port, input_callback, &app);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    while(app.running) {
        if(furi_get_tick() - app.last_tick > 3000) {
            if(app.hunger > 0) app.hunger--;
            if(app.boredom < 100) app.boredom++;

            if(app.boredom > 80) {
                notification_message(app.notifications, &sequence_double_vibro);
            }

            app.last_tick = furi_get_tick();
        }

        // keeps UI responsive
        furi_delay_ms(50);
    }

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);

    furi_record_close(RECORD_GUI);
    furi_record_close(RECORD_NOTIFICATION);

    return 0;
}