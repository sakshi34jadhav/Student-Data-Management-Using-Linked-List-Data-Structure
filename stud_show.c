#include <stdio.h>
#include <string.h>
#include "student.h"

void show_records(void)
{
    struct student *temp = head;

    if (temp == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("\n--------------------------------------------------\n");
    printf("%-10s %-25s %-10s\n", "Roll No.", "Name", "Percentage");
    printf("--------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%-10d %-25s %-10.2f\n",
               temp->rollno, temp->name, temp->percentage);
        temp = temp->next;
    }
    printf("--------------------------------------------------\n");
}

void sort_records(void)
{
    char choice;
    struct student *i, *j;
    int roll;
    char name[50];
    float percentage;

    if (head == NULL || head->next == NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }

    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage (highest first)\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    while (getchar() != '\n') ;

    if (choice != 'n' && choice != 'N' &&
        choice != 'p' && choice != 'P')
    {
        printf("Invalid choice.\n");
        return;
    }

    /* Simple bubble sort: swap data fields, keeping list links unchanged. */
    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            int swap = 0;

            if ((choice == 'n' || choice == 'N') &&
                strcmp(i->name, j->name) > 0)
                swap = 1;

            if ((choice == 'p' || choice == 'P') &&
                i->percentage < j->percentage)
                swap = 1;

            if (swap)
            {
                roll = i->rollno;
                i->rollno = j->rollno;
                j->rollno = roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage = i->percentage;
                i->percentage = j->percentage;
                j->percentage = percentage;
            }
        }
    }

    printf("Records sorted successfully.\n");
}

