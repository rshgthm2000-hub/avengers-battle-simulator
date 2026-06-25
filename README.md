# Avengers Battle Simulation

## 📌 Overview

Avengers Battle Simulation is a command-driven **C++** project that models tactical battles between Avengers and their enemies using custom-designed combat suits. The project practically demonstrates core **Object-Oriented Programming (OOP)** principles, including encapsulation, operator overloading, and the utilization of Standard Template Library (STL) containers for state management.

Each character is equipped with a specialized suit (`qns` class) possessing dynamic attributes such as Power, Durability, Energy, and Heat. Through an event-driven command system, users can direct real-time combat actions, execute emergency repairs, install upgrades, and track full tactical logs.

---

## 🚀 Setup & Execution Flow

The simulation initializes by reading a specific sequence of inputs (`k`, `n`, `m`):
1. **Suit Inventory (`k`):** Loads a pool of available suits into a distribution queue.
2. **Hero Deployment (`n`):** Spawns heroes and assigns them the next available suit from the front of the queue. If the queue is empty, the hero is marked "out of fight."
3. **Enemy Deployment (`m`):** Spawns enemies and equips them with any remaining suits from the queue.
4. **Battle Phase:** Triggered by the `BattleBegin` command, the system processes a continuous stream of tactical commands until the `End` command is received.

---

## 📊 Suit Attributes (`qns` class)

Each active combat suit strictly manages four interdependent parameters. Suit logic is heavily driven by custom **Operator Overloading**:

* **Power (P):** Governs raw damage output. Hard-capped at a maximum of `5000`.
* **Durability (D):** Represents structural integrity. The suit evaluates as **Destroyed** (`is_destroyed()`) if durability drops to `<= 0`.
* **Energy (E):** Fluctuates based on damage taken and power boosts applied.
* **Heat (H):** Increases during attacks. The suit goes into forced **Shutdown** (`is_sd()`) if heat exceeds `500`.

---

## 🎮 Supported Commands

The system parses the following commands inside the continuous battle loop:

* `Attack [Attacker] [Target]` — Executes a combat strike using the overloaded `-` operator. Deducts durability and alters heat/energy.
* `Repair [Name] [X]` — Restores structural durability while reducing active heat levels by factor `X` using the overloaded `/` operator.
* `BoostPowerByFactor [Name] [X]` — Multiplies attack values by factor `X` using the overloaded `*` operator.
* `BoostPower [Name] [P] [D] [E] [H]` — Adds the flat stats of a secondary suit to the character using the overloaded `+` operator.
* `Upgrade [Name]` — Permanently scales the base attributes of a selected character by merging them with the next available suit in the queue.
* `AvengerStatus [Name]` — Prints real-time individual attributes (P, D, E, H).
* `BattleStatus` — Evaluates total surviving Power and Durability on both sides and declares who is currently winning.
* `PrintBattleLog` — Outputs the sequential history of all events and attacks.
* `End` — Gracefully terminates the simulation loop.
* ---

## 🛠️ Technical Concepts & Data Structures

The simulation relies on lightweight C++ STL containers to manage the combat timeline and character states efficiently:

| Container / Concept | Technical Mapping & Purpose |
| :--- | :--- |
| **`std::queue<qns>`** | Acts as the initial **Suit Inventory Pool**. Distributes suits sequentially (FIFO) to heroes and enemies upon initialization. |
| **`std::vector`** | Used for tracking active `heroes` and `enemies` dynamically. Also used to store the sequential `battleLog` strings. |
| **`std::unordered_map`** | Provides **O(1) fast lookups** (`hero_list` and `enemy_list`), mapping string character names directly to their vector index for instantaneous command targeting. |
| **Operator Overloading** | Abstracts complex attribute math. e.g., `suit / x` automatically handles durability recovery and heat reduction formulas. |

---

## 📘 Learning Outcomes

This project was built to explore and master:
* Clean **Class Design** and component coupling (connecting the `qns` suit to the `avenger` entity).
* Safe implementations of memory-efficient **Operator Overloading**.
* Practical application of **Data Structures** for fast lookup and sequential state tracking.
* State machine management inside continuous **Simulation Programming** environments.

---

## 🧑‍💻 Author Profile

### Name
**RISHI GOUTHAM**

### Technical Focus
C++ | Advanced Algorithms | Computer Science Student

### Project Context
Developed as a C++ Object-Oriented Programming project inspired by the architectural and computational logic of the Avengers universe.
