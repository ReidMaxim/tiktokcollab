# 🧱 Flipper Zero Build Template (Simple Guide)

This repository is **NOT just a normal app** — it is a **build template**.

Its main purpose is:

➡️ **Compile (build) Flipper Zero apps automatically using GitHub.**

This means you can turn Flipper app source code into a working `.fap` file **without installing anything** on your computer.

It works great for:

* Chromebook users
* Beginners
* People who don’t want to install build tools
* Anyone learning Flipper app development

---

# 🧠 What this repo actually does

Normally, building a Flipper app requires:

* Installing tools
* Using command lines
* Setting up a development environment

This repo removes all that.

When you push code to GitHub:

1️⃣ GitHub builds the app for you
2️⃣ A `.fap` file is created automatically
3️⃣ You download it and put it on your Flipper

Think of it like:

> GitHub = your free build computer

---

# 🔄 How to Fork (Make Your Own Copy)

## Step 1 — Fork the repo

1. Open this repository on GitHub.
2. Click the **Fork** button (top right).

GitHub will create your own copy:

```id="mha6ez"
github.com/YOUR_USERNAME/REPO_NAME
```

You now control your own version.

---

# ✏️ Step 2 — Edit files

Inside your fork:

* Change code
* Add files
* Modify the app however you want

When you are ready:

Commit and push your changes.

---

# ⚙️ Step 3 — Automatic Build

After you push:

1. Go to the **Actions** tab.
2. Click the latest build.
3. Wait for the green check ✅

GitHub is now building your app automatically.

You do NOT need to install anything.

---

# 📦 Step 4 — Download the Built App

Inside the finished Action:

Scroll down to **Artifacts**.

Download the zip file.

Inside will be:

```id="vfhj4u"
your_app.fap
```

This is the finished Flipper app.

---

# 📲 Step 5 — Put it on your Flipper

1. Open **qFlipper**
2. Go to:

```id="hxozrb"
File Manager → SD Card → /apps/
```

3. Copy the `.fap` file there.

Run it on your Flipper.

---

# 🧠 Simple Summary

Fork → Edit → Push → GitHub Builds → Download `.fap`

That’s it.

---

# ❓ Why use this?

Because you don’t need to:

* Install build tools
* Learn complicated setup
* Use Linux commands

GitHub handles the hard part for you.

---

# 👍 Final Tip

If something doesn’t work:

* Check the **Actions** tab
* Red ❌ = build failed
* Green ✅ = ready to download
