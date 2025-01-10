# 2024/11/22

# Binary Expression Tree Parser and Evaluator

This project implements a **Binary Expression Tree** that parses mathematical expressions, constructs a tree, and evaluates the result. It supports operations such as addition, subtraction, multiplication, and division, and allows users to traverse the tree in different orders.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Features](#features)
3. [Program Structure](#program-structure)
   - [Main Program](#main-program)
   - [Core Functionalities](#core-functionalities)
4. [How to Run](#how-to-run)
5. [Usage](#usage)
6. [Implementation Details](#implementation-details)
   - [Expression Parsing](#expression-parsing)
   - [Tree Traversal](#tree-traversal)
   - [Evaluation](#evaluation)

---

## Introduction

The **Binary Expression Tree Parser and Evaluator** reads a mathematical expression, constructs a binary tree representing the expression, and evaluates the result. It supports:
- Arithmetic operations: addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
- Variables with user-defined values.
- Parentheses for specifying operation precedence.

---

## Features

1. **Expression Parsing**:
   - Parses mathematical expressions into a binary expression tree.
   - Handles parentheses to ensure proper operator precedence.

2. **Tree Traversals**:
   - Preorder, Inorder (fully parenthesized), and Postorder traversal options.

3. **Variable Handling**:
   - Prompts the user to input values for variables used in the expression.

4. **Calculation**:
   - Evaluates the expression represented by the tree.
   - Handles division by zero gracefully.

---

## Program Structure

### Main Program

- **`a3q1_main.c`**:
  - Entry point for the program.
  - Manages user interaction through a menu.
  - Accepts the mathematical expression as a command-line argument.

### Core Functionalities

- **`a3q1_header.h`**:
  - Defines the `Node` structure for the binary tree and `Variable` structure for variable management.
  - Declares all functions for parsing, traversing, and evaluating the tree.

- **`a3q1_functions.c`**:
  - Implements:
    - Expression parsing and tree construction.
    - Preorder, Inorder, and Postorder traversals.
    - Expression evaluation with variable handling.

---

## How to Run

### Prerequisites

- A C compiler (e.g., GCC or Clang).

### Compilation and Execution

1. Compile the program:
   ```bash
   gcc a3q1_main.c a3q1_functions.c -o expression_tree
   ```
2. Run the program:
   ```bash
   ./expression_tree "(a+b)*(c/d)"
   ```

---

## Usage

1. Start the program by providing a mathematical expression as an argument:
   ```bash
   ./expression_tree "(x+y)*z"
   ```
   - Replace `x`, `y`, and `z` with your variable names or values.
   
2. Navigate the menu:
   - `1`: Preorder traversal (prefix notation).
   - `2`: Inorder traversal (fully parenthesized infix notation).
   - `3`: Postorder traversal (postfix notation).
   - `4`: Evaluate the expression.
   - `5`: Exit the program.

---

## Implementation Details

### Expression Parsing

- **Tree Nodes**:
  - Each node represents an operator, operand, or variable.
  - Leaf nodes contain operands or variables.
  - Internal nodes contain operators (`+`, `-`, `*`, `/`).

- **Recursive Parsing**:
  - Recursively constructs the binary expression tree by:
    - Parsing the left operand.
    - Parsing the operator.
    - Parsing the right operand.
  - Handles parentheses for proper precedence.

### Tree Traversal

- **Preorder Traversal**:
  - Visits the root, then the left and right subtrees.
  - Outputs the expression in prefix notation.

- **Inorder Traversal**:
  - Visits the left subtree, root, and then the right subtree.
  - Outputs the expression in fully parenthesized infix notation.

- **Postorder Traversal**:
  - Visits the left and right subtrees, then the root.
  - Outputs the expression in postfix notation.

### Evaluation

- **Variable Handling**:
  - Prompts the user to enter values for variables encountered in the expression.
  - Stores variable names and values for reuse.

- **Operator Handling**:
  - Supports `+`, `-`, `*`, and `/`.
  - Checks for division by zero and displays an error if detected.
