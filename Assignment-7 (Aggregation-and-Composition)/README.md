<div align="center">

# 📁 Assignment-7 (OOP Assignment 3) — Aggregation & Composition

**Object-Oriented Programming | FAST NUCES BS-SE**

![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![](https://img.shields.io/badge/Questions-1-16a34a?style=for-the-badge)
![](https://img.shields.io/badge/Marks-20-dc2626?style=for-the-badge)
![](https://img.shields.io/badge/Status-Completed-16a34a?style=for-the-badge)

</div>

---

## 📋 Details

| Field | Info |
|-------|------|
| **Course** | Object-Oriented Programming |
| **Instructor** | Ma'am Hina Iqbal |
| **TA** | Syed Saad Ali |
| **Section** | BSSE-B |
| **Semester** | Spring 2026 |
| **Topics** | Aggregation · Composition · OOP Relationships |

📄 [View Question PDF](./Question.pdf)

---

## 🗂️ Solution

| File | Problem |
|------|---------|
| [Solution.cpp](./Solution.cpp) | CampusCore — University Simulation System |

---

## 🏗️ Class Architecture

```text
University
├── Department[]          ← COMPOSITION (destroyed with University)
│   ├── Course[]          ← COMPOSITION (destroyed with Department)
│   └── Professor*[]      ← AGGREGATION (survives Department)
│
└── Student*[]            ← AGGREGATION (survives University)
    ├── Address           ← COMPOSITION (destroyed with Student)
    └── Course*[]         ← AGGREGATION (survives Student)

Professor
└── Address               ← COMPOSITION (destroyed with Professor)
```

---

## 💡 Concepts Practiced

```cpp
✔  Composition  — child destroyed with parent (value members)
✔  Aggregation  — child survives parent (pointer members)
✔  Rule of Three — destructor, copy constructor, copy assignment
✔  Dynamic memory allocation — new/delete, pointer-based arrays
✔  Deep copy of char* members
✔  Pointer arithmetic — no [] operator allowed
✔  Edge case handling — duplicates, null checks, dangling pointers
```

---

## 🧩 Problem Highlight — CampusCore

A full console-based university simulation in C++ with 6 interconnected classes:

**`Address`** — Composed inside Professor and Student. No meaning without its owner.

**`Course`** — Composed inside Department. Destroyed when Department is destroyed.

**`Professor`** — Independent entity. Aggregated into Department via pointer — survives removal.

**`Student`** — Independent entity. Aggregated into University via pointer — survives University.

**`Department`** — Composed inside University. Destroyed when University is destroyed.

**`University`** — Top-level class. Owns Departments (Composition), references Students (Aggregation).

---

---

## 🔍 OOP Relationship Map

| Parent | Child | Relationship | Why |
|--------|-------|-------------|-----|
| University | Department | Composition | Dept has no meaning without University |
| Department | Course | Composition | Course has no meaning without Department |
| Professor | Address | Composition | Address has no meaning without Professor |
| Student | Address | Composition | Address has no meaning without Student |
| Department | Professor | Aggregation | Professor exists independently |
| Student | Course | Aggregation | Course exists independently |
| University | Student | Aggregation | Student exists independently |

---

## ⚠️ Constraints
✘  No built-in string functions\
✘  No [] operator — pointer arithmetic only\
✘  No global variables\
✘  No memory leaks / dangling pointers\
✘  No std::string
