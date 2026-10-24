Student Data Management Using Linked List Data Structure
Mini Project | C Programming

1. Project Description
The Student Record Management System is a menu-driven application developed in C. It uses a singly linked list to store and manage student records dynamically.

2. Student Record Structure
Each student record contains:
* Roll Number
* Student Name
* Percentage
* Pointer to the next student node

3. Project Modules
* stud_main.c – Main function and menu.
* stud_add.c – Add a new student record.
* stud_del.c – Delete a record by roll number or name.
* stud_show.c – Display and sort student records.
* stud_mod.c – Modify an existing student record.
* stud_save.c – Save/load records, delete all records, reverse the list, and release memory.
* student.h – Structure definition and function declarations.

4. Features
* Add student records with the smallest available positive roll number.
* Delete records by roll number or name.
* Display all student records.
* Modify records by roll number, name, or percentage.
* Sort records alphabetically by name or by percentage in descending order.
* Save and load records using student.dat.
* Delete all records from memory.
* Reverse the singly linked list.
* Free dynamically allocated memory before exiting.

5. Compilation
Open the terminal in the project directory and execute:

gcc stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student

6. Execution
Run the program using:
./student

7. File Handling
Student records are stored in the binary file student.dat. Existing records are loaded when the program starts. The user can save records using the v/V menu option or choose Save and Exit.

8. Concepts Used
* Structures
* Pointers
* Singly linked lists
* Dynamic memory allocation (malloc)
* Memory deallocation (free)
* String handling
* Searching and sorting
* File handling
* Modular programming

9. Conclusion
This project demonstrates how linked lists, dynamic memory allocation, searching, sorting, and file handling can be used to manage student records efficiently in C.
