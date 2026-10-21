#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void delete_record(void)
{
    char choice, name[50];
    int roll;
    struct student *temp, *prev;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("R/r : Delete by roll number\n");
    printf("N/n : Delete by name\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    while (getchar() != '\n') ;

    if (choice == 'r' || choice == 'R')
    {
        printf("Enter roll number: ");
        if (scanf("%d", &roll) != 1)
        {
            while (getchar() != '\n') ;
            printf("Invalid roll number.\n");
            return;
        }
        while (getchar() != '\n') ;
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter name: ");
        if (fgets(name, sizeof(name), stdin) == NULL)
            return;
        name[strcspn(name, "\n")] = '\0';

        temp = head;
        printf("Matching records:\n");
        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
                printf("Roll: %d, Name: %s, Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
            temp = temp->next;
        }

        printf("Enter roll number of the record to delete: ");
        if (scanf("%d", &roll) != 1)
        {
            while (getchar() != '\n') ;
            printf("Invalid roll number.\n");
            return;
        }
        while (getchar() != '\n') ;
    }
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    temp = head;
    prev = NULL;
    while (temp != NULL && temp->rollno != roll)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Record not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Record deleted successfully.\n");
}
