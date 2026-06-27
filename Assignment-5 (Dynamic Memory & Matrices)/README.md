<div align="center">

# 📁 Assignment-5 (OOP Assignment 1) — Dynamic Memory & 2D Arrays

**Object-Oriented Programming | FAST NUCES BS-SE**

![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![](https://img.shields.io/badge/Questions-3%20%2B%20Bonus-16a34a?style=for-the-badge)
![](https://img.shields.io/badge/Status-Completed-16a34a?style=for-the-badge)

</div>

---

## 📋 Details

| Field | Info |
|-------|------|
| **Course** | Object-Oriented Programming |
| **Instructor** | Ma'am Hina Iqbal |
| **TA** | Syed Saad Ali |
| **Section** | BSE-2B |
| **Topics** | Dynamic Memory Allocation, 2D Arrays, Pointers |

📄 [View Questions PDF](./Questions.pdf)
📄 [Sample I/O for Question 2](./Sample%20Input%20Output%20for%20Question%202.pdf)

> ⚠️ Static arrays not allowed — all data structures use dynamic memory allocation.

---

## 🗂️ Solutions

| # | File | Problem |
|---|------|---------|
| 01 | [Question-1.cpp](./Question-1.cpp) | Heisenberg's Underground Menu Management System |
| 02 | [Question-2.cpp](./Question-2.cpp) | Shopping Cart Management System |
| 03 | [Question-3.cpp](./Question-3.cpp) | The Inventory Cleanup (E-commerce) |
| 📁 | [Input File](./Input%20File%20%28Question-1%29) | Sample menu data for Q1 |
| 📁 | [Output File](./Output%20File%20%28Question-1%29) | Sorted menu output for Q1 |

---

## 💡 Concepts Practiced

```cpp
✔  Dynamic memory allocation (new/delete)
✔  Dynamic 2D arrays
✔  File handling (read/write)
✔  Multi-key sorting
✔  Search & filter algorithms
✔  Memory-safe pointer handling
✔  Matrix compaction (sparse → dense)
```

---

## 🧩 Problem Highlights

**Q1 — Menu Management System**
Reads unorganized restaurant menu data from a file, builds a
dynamic 2D string array, and sorts it by Cuisine → Restaurant →
Category → Price. Supports cuisine-based search (e.g. "Mexican"
matches Mexican, Mexican-Street, Mexican-Fusion) and exports
the organized result to an output file.

**Q2 — Shopping Cart System**
Full cart management engine — add/remove items, dynamic
attributes (price, category, etc.), sorting by any attribute,
total/average value calculation, and range-based filtering.

**Q3 — Inventory Cleanup**
Compacts a sparse warehouse stock grid into a clean "pick list" —
removes empty (0) slots and keeps only actual stock counts,
with each shelf row sized to its real item count.

**Bonus — Thesaurus Writing Assistant**
Parses a hash-separated word/synonym string into a dynamic
2D string array (`string**`) and replaces an input word with
its last listed synonym.

---
