# Avengers Battle Simulation

## 📌 Overview

Avengers Battle Simulation is a command-driven **C++** project that models tactical battles between Avengers and their enemies using custom-designed combat suits. The project practically demonstrates core **Object-Oriented Programming (OOP)** principles, including encapsulation, class interactions, operator overloading, and the utilization of standard template library (STL) containers.

Each character is equipped with a specialized suit possessing dynamic attributes such as Power, Durability, Energy, and Heat. Through an event-driven command system, users can direct real-time combat actions, execute emergency repairs, install equipment upgrades, and track full tactical logs.

---

## 🚀 Features

* **Hero vs Enemy Simulation:** Models interactive, turn-based or real-time tactical engagements between teams.
* **Custom Suit Management:** Tracks vital weapon, armor, and power-core statistics dynamically during combat.
* **Complex Damage Mechanics:** Implements localized structural damage and energy depletion based on attack types.
* **Upgrades & Power Boosts:** Features scalable performance modifiers to enhance suit attributes mid-battle.
* **Repair & Cooldown Operations:** Incorporates strategic recovery windows to prevent terminal hardware failures.
* **Overheating & Destruction Conditions:** Triggers structural destruction or system lockdowns when thresholds are breached.
* **Battle Activity Logging:** Maintains an event-driven queue to print detailed sequential history of combat logs.

---

## 🛠️ Technical Concepts

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (Encapsulation, Interaction, Component Architecture)
* **Operator Overloading:** Custom behavior definitions for suit comparisons, structural additions, and output streaming.
* **STL Containers:**
  * `std::vector` for sequential character and team tracking.
  * `std::queue` for chronological execution of battle log events.
  * `std::unordered_map` for fast command parsing and attribute lookups.
* **System Design:** Command-driven processing and state machine management.

---

## 📊 Suit Attributes

Each active combat suit strictly manages four interdependent parameters:

* **Power (P):** Governs the raw damage output dealt to an opponent during an attack command.
* **Durability (D):** Represents structural integrity. The suit becomes **Destroyed** if durability drops to `0`.
* **Energy (E):** The fuel source consumed by executing high-tier attacks and system boosts.
* **Heat (H):** Increases with aggressive weapon usage. The suit becomes **Overheated** if heat breaches its maximum safety threshold, requiring dedicated cooldown cycles.

---

## 🎮 Supported Commands

The simulation processes an array of text-based console inputs to control execution flow:
* `Attack` — Executes a combat strike against a target enemy, modifying health and heat metrics.
* `Repair` — Restores structural durability while reducing active heat levels.
* `BoostPower` / `BoostPowerByFactor` — Temporarily or permanently amplifies attack values.
* `Upgrade` — Permanently scales the base attributes of a selected Avenger's suit.
* `AvengerStatus` / `BattleStatus` — Prints real-time individual or map-wide attribute statistics.
* `PrintBattleLog` — Outputs the sequential history of all events handled by the queue tracker.
* `End` — Gracefully terminates the simulation evaluation matrix.

---

## 📘 Learning Outcomes

This project was built to explore and master:
* Clean **Class Design** and loose component coupling.
* Safe implementations of memory-efficient **Operator Overloading**.
* Practical application of **Data Structures** to handle chronological timeline events.
* State management patterns inside continuous **Simulation Programming** environments.

---

## 🧑‍💻 Author

**RISHI GOUTHAM** C++ | Advanced Algorithms | Computer Science Student

*Developed as a C++ Object-Oriented Programming project inspired by the architectural and computational logic of the Avengers universe.*
