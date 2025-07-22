# 🧱 so_long

> A simple 2D graphical game built using MiniLibX, developed in C as part of the 42 School curriculum. The player collects all items and exits the map while avoiding enemies (in bonus).

---

## 📌 Project Overview

**so_long** is a project that demonstrates the use of basic graphics in C. It involves creating a small tile-based game where the player navigates a 2D map to collect collectibles and reach the exit.

---

## 🎯 Objectives

- Render a 2D map from a `.ber` file using MiniLibX.
- Implement player movement (WASD or arrow keys).
- Collect all collectibles (`C`) before exiting.
- Handle map validation and error management.
- Display move count in terminal or window.
- Bonus: Add enemy patrols, animations, and UI improvements.

---

## 🔧 Requirements

- Unix-like system (Linux/macOS)
- `make`
- MiniLibX library
- `gcc` compiler

---

## 📥 Installation & Compilation

### Clone the Repository

```bash
git clone https://github.com/falhaimouni/so_long.git
cd so_long
make
```
## 🚀 Usage
```bash
./so_long maps/map1.ber
```
## 🎮 Controls

| Key               | Action               |
|------------------|----------------------|
| `W` / `↑`        | Move up              |
| `S` / `↓`        | Move down            |
| `A` / `←`        | Move left            |
| `D` / `→`        | Move right           |
| `ESC`            | Quit the game        |

🕹️ **Goal:** Collect all `C` (collectibles), and reach the exit `E`.
