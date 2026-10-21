# STUDENT RECORD MANAGEMENT SYSTEM — MINI PROJECT

## Project Overview
The Student Record Management System is a menu-driven application developed in C to manage student records efficiently. It supports adding, deleting, modifying, displaying, sorting, and storing student information using structures, pointers, dynamic memory allocation, and file handling.

## Developer Details
- **Developer Name:** Sakshi Jadhav.
- **Project Title:** Student Record Management System
- **Project Type:** Mini Project
- **Programming Language:** C
- **Development Environment:** GCC Compiler
- **Platform:** Linux / Windows (with GCC)
- **Project Category:** File Handling and Data Structures

## Key Features
- Add new student records.
- Automatically assign the smallest unused positive roll number.
- Delete student records by roll number or name.
- Modify records using roll number, name, or percentage.
- Display and sort student records.
- Save records to a file and load them at startup.
- Delete all records from the in-memory list.
- Reverse the student list.
- Dynamically allocate and free memory.
- Choose whether to save changes before exiting.

## Project File Structure
- `student.h` — Contains the student structure and function declarations.
- `stud_main.c` — Handles the menu and main program flow.
- `stud_add.c` — Adds student records and assigns roll numbers.
- `stud_del.c` — Deletes records by roll number or name.
- `stud_show.c` — Displays and sorts student records.
- `stud_mod.c` — Modifies records by roll number, name, or percentage.
- `stud_save.c` — Handles file operations, saving/loading records, deleting all records, reversing the list, and freeing memory.

## Compilation
Compile all source files using GCC:

```bash
gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student
```

## Execution

On Linux:

```bash
./student
```

On Windows Command Prompt:

```bash
student.exe
```

## Data Storage and Save Mechanism
- The program loads existing student records from `student.dat` at startup.
- Choose `V/v` to save records during program execution.
- On exit, choose `S/s` to save and exit, or `E/e` to exit without saving.
- Deleting all records affects only the in-memory list until the user explicitly saves the changes.

## Concepts Used
- Structures and user-defined data types
- Pointers and linked-list operations (if implemented using a linked list)
- Dynamic memory allocation and deallocation
- File handling in C
- Modular programming using multiple source files
- Functions and header files
- Searching, sorting, insertion, and deletion
- Menu-driven programming

## Learning Outcomes
This project demonstrates practical knowledge of C programming, memory management, modular code organization, and file persistence. It also illustrates how student information can be managed through a simple command-line interface.

## Author
**Sakshi Jadhav**

*Student Record Management System — Developed as a C programming mini project.*
