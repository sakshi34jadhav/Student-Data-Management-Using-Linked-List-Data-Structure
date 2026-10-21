STUDENT RECORD MANAGEMENT SYSTEM - MINI PROJECT

Files:
  student.h    Structure and function declarations
  stud_main.c  Menu and program flow
  stud_add.c   Add a record and assign smallest unused positive roll number
  stud_del.c   Delete by roll number or name
  stud_show.c  Display and sort records
  stud_mod.c   Modify by roll number, name, or percentage
  stud_save.c  Save/load file, delete all, reverse list, free memory

Compile:
  gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student

Run:
  ./student

The program loads student.dat at startup. Choose v/V to save. On exit, choose
S/s to save and exit or E/e to exit without saving. Deleting all records only
changes the in-memory list until the user explicitly saves.
