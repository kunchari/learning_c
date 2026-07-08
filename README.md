# Preparation for "Programming in C" University Course. 🇨🇿🇺🇦

This repository contains my personal learning path, code examples, and notes while preparing for the **BI-PA1** programming course at **FIT ČVUT** (Czech Technical University in Prague). 

My goal is to deeply understand system-level programming, memory management, and write robust, production-ready C code.

---

## 🛠️ Tech Stack & Tools
* **Language:** C (C99 / C11 standards)
* **Compiler:** GCC with strict flags (`-Wall -Wextra -pedantic`)
* **Environment:** Linux (Ubuntu via WSL / Kali Linux)
* **Debugging & Memory:** GDB, Valgrind, AddressSanitizer (`-fsanitize=address`)

---

## 📚 Syllabus & My Progress

- [x] **Week 1: Variables, basic Input and Output in C Language.**
- [ ] **Week 2: Expressions and conditionse. Loops and data representation.** **Functions and procedures.**
- [ ] **Week 3: Arrays & Strings.**
- [ ] **Week 4: Pointers and structures. Dynamic memory allocation.**
- [ ] **Week 5: Searching algorithms and Quadratic sorting algorithms. Problem decomposition, recursion, MergeSort. Introduction to QuickSort, linked structures.**
- [ ] **Week 6: Working with files, Tree structures.**
- [ ] **Week 7: Abstract data types (boolean, complex numbers, queue, stack), Modular programming.**

---

## 🧠 Key Rules I Learned (My Survival Guide)

1. **Check `scanf` return value:** Never trust user input. Always do `if (scanf("%d", &x) != 1) { /* error */ }`.
2. **Draw Memory:** If a pointer expression is confusing, stop coding and draw it on paper.
3. **Valgrind is my friend:** Always run code through Valgrind to ensure there are 0 memory leaks before considering the task "done".

---
*Note: In accordance with the FIT ČVUT academic integrity policy, this repository does NOT contain any Progtest homework solutions.*
