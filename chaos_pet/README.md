# Chaos Pet — Flipper Zero App

A simple virtual pet demo for the Flipper Zero built using the official Furi SDK.

This project shows:

* Basic GUI drawing
* Button input handling
* Notifications (LED / vibration)
* Periodic game-state updates

---

## 📦 Requirements

* Windows (steps below assume Windows)
* Git installed
* Flipper Zero (official firmware recommended)
* qFlipper installed

---

## 🔗 Official Firmware Repository

Clone the **official** Flipper Zero firmware repo:

https://github.com/flipperdevices/flipperzero-firmware

⚠️ IMPORTANT:
Do **NOT** download the ZIP if you plan to build.
You must use `git clone` so the `.git` folder exists.

---

## 🧰 Setup Steps (exact workflow used)

### 1️⃣ Clone the firmware

Open Command Prompt:

```bash
cd C:\
git clone https://github.com/flipperdevices/flipperzero-firmware.git
```

This creates:

```
C:\flipperzero-firmware\
```

---

### 2️⃣ Add the app folder

Go to:

```
flipperzero-firmware/
   applications_user/
```

Create:

```
chaos_pet/
```

Final structure:

```
flipperzero-firmware/
   applications_user/
      chaos_pet/
         chaos_pet.c
         application.fam
```

---

### 3️⃣ Build environment

Open Command Prompt:

```bash
cd C:\flipperzero-firmware
```

Run:

```bash
fbt.cmd
```

This launches the Flipper build environment.

---

### 4️⃣ Build the app (.fap)

Inside the `(fbt)` terminal:

```bash
fbt fap_chaos_pet
```

If successful, a `.fap` file will be produced.

---

### 5️⃣ Locate the built app

Find the output file:

```bash
dir /s chaos_pet.fap
```

Typical location:

```
build\f7-firmware-D\.extapps\chaos_pet\chaos_pet.fap
```

---

### 6️⃣ Install on Flipper

1. Open **qFlipper**
2. Open **File Manager → SD Card**
3. Navigate to:

```
/apps/Games/
```

4. Copy:

```
chaos_pet.fap
```

into that folder.

---

### 7️⃣ Run the app

On Flipper:

```
Applications → Games → Chaos Pet
```

---

## 🎮 Controls

* **OK** → Feed pet
* **LEFT** → Reduce boredom
* **BACK** → Exit app

---

## 🧠 Notes

* The app uses the Flipper GUI viewport system.
* State updates occur every few seconds using `furi_get_tick()`.
* Notification sequences may vary between firmware versions.

---

## ⚠️ Common Build Problems

### `.git not found`

You downloaded ZIP instead of cloning with git.

### Notification sequence errors

Some firmware versions rename notification sequences. Replace unsupported ones with available alternatives like:

```
sequence_double_vibro
```

---

## 🙌 Credits

Built using the official Flipper Zero firmware SDK:

https://github.com/flipperdevices/flipperzero-firmware
