<div align="center">

# 📁 DSA Assignment 1 — Linked Lists

**Data Structures | FAST NUCES BS-SE**

![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![](https://img.shields.io/badge/Parts-3-16a34a?style=for-the-badge)
![](https://img.shields.io/badge/Marks-100-dc2626?style=for-the-badge)
![](https://img.shields.io/badge/Status-Completed-16a34a?style=for-the-badge)

</div>

---

## 📋 Details

| Field | Info |
|-------|------|
| **Course** | Data Structures (CS 2001) |
| **Instructor** | Rana Waqas Ali |
| **TA** | Syed Aoun Haider Sherazi |
| **Semester** | Fall 2026 |
| **Total Marks** | 100 |

📄 [View Questions PDF](./Questions.pdf)

---

## 🗂️ Solutions

| File | Part | Problem |
|------|------|---------|
| [Question-1.cpp](./Question-1.cpp) | Part 1 — 60 marks | Recruitment Pipeline (Linked List + ArrayList) |
| [Question-2.cpp](./Question-2.cpp) | Part 2 — 20 marks | Clone Linked List with Random Pointers |
| [Question-2 Approach.pdf](./Question-2%20Approach.pdf) | Part 2 — Approach | Written explanation, pseudocode & complexity |
| [Question-3.pdf](./Question-3.pdf) | Part 3 — 20 marks | Time Complexity Problem Set |

---

## 💡 Concepts Practiced

✔ Singly Linked List — custom implementation\
✔ ArrayList / Dynamic Array — without STL vector\
✔ Linked List + ArrayList combined data structure\
✔ Cycle detection — Floyd's algorithm\
✔ Deep copy of pointer-based structures\
✔ Random pointer cloning — O(N) interleaving technique\
✔ Time complexity analysis — Θ-bounds\
✔ Nested loop analysis — geometric & non-linear

---

## 🧩 Problem Highlights

**Part 1 — Recruitment Pipeline (60 marks)**

A simplified LinkedIn recruitment system built using a **Singly Linked List** where each
node represents a recruitment stage, and each stage holds an **ArrayList of candidates**.\
Applied → Screening → Technical Interview → HR Interview → Selected\
🌐 **[Live Demo → pipelinehire.vercel.app](https://pipelinehire.vercel.app/)**

Key operations implemented:

| Function | Description |
|----------|-------------|
| `moveCandidate()` | Move candidate between stages |
| `withdrawCandidate()` | Remove candidate from pipeline |
| `promoteEligibleCandidates()` | Auto-promote based on CGPA/scores |
| `getBestCandidate()` | Weighted score formula |
| `findCandidatesBySkill()` | Skill-based search across all stages |
| `insertStage()` | Insert new stage between existing ones |
| `removeStage()` | Remove empty stage |
| `reversePipeline()` | Reverse linked list connections only |
| `hasCycle()` | Floyd's cycle detection — in-place |
| `displayStatistics()` | Dynamic per-stage stats |

---

**Part 2 — Clone Linked List with Random Pointers (20 marks)**

Deep copy of a linked list where each node has a `next` and a `random` pointer.
`random` can point to any node — including itself or NULL.

Solved using the **O(N) interleaving technique** — pure linked list manipulation:

Step 1 → Interleave cloned nodes between original nodes\
Step 2 → Set random pointers of cloned nodes\
Step 3 → Separate the two lists\

---

**Part 3 — Time Complexity Problem Set (20 marks)**

| # | Loop Structure | Tight Bound |
|---|---------------|-------------|
| Q1 | Harmonic series nested loop | Θ(N log N) |
| Q2 | Square root inner loop | Θ(N√N) |
| Q3 | Geometric loops (×2 outer, ×3 inner) | Θ(log N · log N) |
| Q4 | Super-logarithmic loop (i = i²) | Θ(log log N) |

---

## ⚠️ Restrictions

✘ No STL list or STL vector
✘ No HashMap / unordered_map for pipeline
✘ No built-in Linked List classes
✘ No global candidate storage
✅ Custom Linked List + ArrayList only

---

<div align="center">

*Part of [cpp-assignments](../README.md) — FAST NUCES BS-SE Journey*

</div>
