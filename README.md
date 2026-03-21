# Competitive Programming Reference Notebook

This repository contains my streamlined, battle-tested C++ templates for Competitive Programming (ICPC, Codeforces, CSES). 

Unlike a learning journal, this notebook is optimized for **speed, correctness, and quick reference during contests**. It contains zero fluff—just raw, heavily tested code and minimal necessary formulas.

## 📂 Repository Structure

The notebook is divided into standard competitive programming categories. Each template is written as a standalone `.h` header file, and a master `.tex` file compiles them into a dense, printable PDF.

```text
.
├── Makefile             # Commands to build the PDF quickly
├── config.tex           # LaTeX styling (optimized for dense printing)
├── main.tex             # The master file that pulls everything together
├── notebook.pdf         # The final compiled reference document
└── content/
    ├── data_structure/  # SegTrees, Fenwick, DSU, Sparse Table
    ├── debug/           # Custom local debugging macros
    ├── geometry/        # Primitives (Point, Line), Convex Hull
    ├── graph/           # Dijkstra, SCC, LCA, Euler Paths
    ├── math/            # Sieve, Matrix Ops, Barrett Reduction, Int128
    ├── misc/            # Coordinate Compression, etc.
    ├── setup/           # Pragmas, Fast I/O, Compiler setup
    └── string/          # KMP, Z-Algorithm
```

## 🛠️ Usage & Philosophy

1. **Bug-Free Guarantee:** Every `.h` file in this repository must be stress-tested or verified on an online judge (like Yosupo Library Checker or CSES) before being merged.
2. **Copy-Paste Ready:** Code is written to be easily typed manually (if printed for ICPC) or copy-pasted (for online rounds).
3. **Black Box:** The internal workings of these templates are documented elsewhere in my personal learning journal. This notebook assumes I already know how the algorithm works.

## 🖨️ Building the PDF

To generate the latest version of `notebook.pdf`, simply run:

```bash
make
```
*(Ensure you have a working LaTeX distribution installed on your system).*

## 🚀 Setup & Template inclusion

During an online contest, I combine the files from `setup/` with the specific algorithm needed from `content/`. The `debug/debug.h` is strictly for local testing and is optimized out during actual submissions.
