# Multi-Language Puzzle Solver (Sudoku)

## Project Overview
This repository contains a recursive backtracking algorithm designed to solve a 9x9 Sudoku puzzle. To demonstrate multi-language proficiency and performance benchmarking, the algorithm has been implemented in both **Python** and **C++**.

## Algorithm
The solver uses a **Backtracking Algorithm**. It searches the grid for an empty space (represented by `0`), attempts to place a valid number (1-9), and recursively tries to solve the rest of the board. If it reaches a point where no valid number can be placed, it "backtracks" (erases the number) and tries the next available option.

## Performance Benchmark
The exact same puzzle was solved using both implementations to compare execution speeds:
*   **Python (v3):** `0.1287 seconds`
*   **C++ (v16.2.0):** `0.0110 seconds`

*C++ executes roughly 11.6x faster than Python in this test due to being a compiled language.*

## How to Run

### Prerequisites
*   Python 3 installed.
*   A C++ compiler (e.g., `g++` via MSYS2/MinGW) installed.

### 1. Running the Python Version
Open your terminal and run:
```bash
python main.py