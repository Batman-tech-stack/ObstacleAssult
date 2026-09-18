# OBSTACLE ASSAULT

A 3-level obstacle course game developed in **Unreal Engine 5 using C++**.

The project was created to improve my understanding of Unreal Engine C++ gameplay programming, UI systems, level management, timers, persistent data, and game flow.

---

## 🎮 Game Overview

**Obstacle Assault** is a time-based obstacle course where the player must navigate through challenging environments and complete each level as quickly as possible.

The game features multiple levels, a timer system, best-time tracking, level completion screens, pause functionality, countdowns, and persistent save data.

The main objective is simple:

> **Complete the obstacle course as fast as possible and beat your best time.**

---

## ✨ Features

- 🏃 3 playable obstacle-course levels
- ⏱️ Real-time level timer
- 🏆 Best-time / high-score system
- 💾 Persistent SaveGame system
- 🎯 Level completion system
- ⏸️ Pause menu
- 🔢 Countdown system before gameplay
- 🖥️ C++ powered UMG UI
- 🔄 Level selection system
- 🎬 Loading screen system
- 🎮 Main menu
- 🔊 Gameplay audio
- 🌧️ Environmental effects and sound
- 🎥 Third-person gameplay
- ⚙️ Unreal Engine C++ gameplay architecture

---

## 🛠️ Technologies Used

| Technology | Usage |
|------------|-------|
| Unreal Engine 5 | Game Engine |
| C++ | Gameplay Programming |
| UMG | User Interface |
| Visual Studio | C++ Development |
| Git | Version Control |
| Git LFS | Large Unreal Assets |

---

## 🧠 C++ Systems Implemented

### Timer System

A custom gameplay timer tracks how long the player takes to complete each level.

The timer is displayed through a custom C++ UMG widget.

### Best Time System

The game records the player's best completion time for each level.

Best times are maintained using a custom `GameInstance` and saved using Unreal Engine's `SaveGame` system.

### Level Completion System

When the player reaches the level completion trigger:

1. The current time is recorded.
2. The best time is checked.
3. The SaveGame data is updated if necessary.
4. The Level Completed UI is displayed.
5. The player can continue to the next level or return to the menu.

### Countdown System

Before gameplay begins, a countdown prevents the player from moving until the countdown has finished.

The system also handles player input and game pausing during the countdown.

### Pause System

The game includes a custom pause menu implemented using C++ and UMG.

The player can:

- Resume the game
- Return to the main menu
- Navigate through the pause interface

### Loading Screen

A custom loading-screen system was implemented to provide feedback while transitioning between levels.

---

## 🖥️ UI Systems

The project contains several custom C++ UMG widgets:

- `TimerWidget`
- `LevelCompleted`
- `PauseMenu`
- `MainMenuWidget`
- `ConfirmationDialog`
- `LoadingScreenWidget`
- `CountDown`

These widgets communicate with gameplay systems such as the GameMode, GameInstance, and SaveGame system.

---

## 📁 Project Structure

```text
ObstacleAssult/
│
├── Config/
│
├── Content/
│   ├── Characters/
│   ├── UI/
│   ├── Maps/
│   ├── Audio/
│   └── ...
│
├── Plugins/
│
├── Source/
│   └── ObstacleAssult/
│       ├── GameModes/
│       ├── UI/
│       ├── GameInstance/
│       └── ...
│
├── ObstacleAssult.uproject
└── README.md
