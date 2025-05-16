# 🖥️ Mini Operating System Simulation 

**Course:** Operating Systems Lab – Spring 2025  
**Instructor:** Sir Hassen Ahmad  
**Team Members:** Numan & Tahir

---

## 🚀 Project Overview

This project simulates a basic operating system using **C/C++ and Bash scripting** on **Ubuntu Linux**. It emulates core functionalities of a real OS — including multitasking, memory management, process scheduling, and more — all from the terminal.

---

## ⚙️ Features

### 🔧 Boot & Setup
- Custom OS name display with loading animation (`sleep`)
- User-defined hardware resources:  
  - 💾 RAM (e.g., 2GB)  
  - 🖴 Hard Drive (e.g., 256GB)  
  - 🧠 CPU Cores (e.g., 8)

### 🗃️ Task Management
- 15+ built-in system tasks:
  - 📝 Notepad (auto-save)
  - 🧮 Calculator
  - 🕒 Clock & Calendar
  - 📂 File operations (Create, Move, Delete, Info)
  - 🎮 Minigame (e.g., Minesweeper)
  - 🎵 Background Music Simulation
  - 🖨️ Print File
  - 🔍 Process Viewer

- Each task runs as a **separate process** using `exec` commands.
- RAM, HDD, and core usage is checked before launching each process.
- Tasks run in separate terminal windows for **true multitasking**.
- Tasks can be **closed or minimized** manually.

### 🧠 OS Simulation Features
- 🎛️ **Multilevel Queue Scheduling** with different algorithms per queue
- 🔄 **Context Switching**
- 🔐 **User Mode vs. Kernel Mode**
  - Kernel mode allows closing/killing background processes
- 🧵 Thread Simulation with:
  - Mutex Locks  
  - Semaphores  
  - Condition Variables

### 🚨 Interrupt Handling
- Manual interrupts simulate closing or minimizing tasks.
- Tasks switch between Ready, Running, and Blocked states.

### 🗃️ Data Persistence
- Any saved data (e.g., Notepad, File tasks) is stored in the simulated hard drive.

---

## 🧪 How to Run

1. 🔧 Make sure you’re on Ubuntu/Linux.
2. Clone this repo:
   ```bash
   git clone https://github.com/your-username/mini-os-simulator.git
   cd mini-os-simulator
