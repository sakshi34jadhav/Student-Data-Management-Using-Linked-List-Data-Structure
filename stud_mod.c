#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_record(void)
{
    char choice, name[50];
    int roll, matches = 0;
    float percentage;
    struct student *temp, *found = NULL;

    if (head == NULL)
    {
        printf("No student records available.\n");
        return;
    }

    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
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

        temp = head;
        while (temp != NULL)
        {
            if (temp->rollno == roll)
            {
                found = temp;
                break;
            }
            temp = temp->next;
        }
    }
    else if (choice == 'n' || choice == 'N')
    {
        printf("Enter name: ");
        if (fgets(name, sizeof(name), stdin) == NULL)
            return;
        name[strcspn(name, "\n")] = '\0';

        temp = head;
        while (temp != NULL)
        {
            if (strcmp(temp->name, name) == 0)
            {
                printf("Roll: %d, Name: %s, Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = temp;
                matches++;
            }
            temp = temp->next;
        }

        if (matches > 1)
        {
            printf("Enter roll number of the record to modify: ");
            if (scanf("%d", &roll) != 1)
            {
                while (getchar() != '\n') ;
                printf("Invalid roll number.\n");
                return;
            }
            while (getchar() != '\n') ;
            found = NULL;
            temp = head;
            while (temp != NULL)
            {
                if (temp->rollno == roll && strcmp(temp->name, name) == 0)
                    found = temp;
                temp = temp->next;
            }
        }
    }
    else if (choice == 'p' || choice == 'P')
    {
        printf("Enter percentage: ");
        if (scanf("%f", &percentage) != 1)
        {
            while (getchar() != '\n') ;
            printf("Invalid percentage.\n");
            return;
        }
        while (getchar() != '\n') ;

        temp = head;
        while (temp != NULL)
        {
            if (temp->percentage == percentage)
            {
                printf("Roll: %d, Name: %s, Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = temp;
                matches++;
            }
            temp = temp->next;
        }

        if (matches > 1)
        {
            printf("Enter roll number of the record to modify: ");
            if (scanf("%d", &roll) != 1)
            {
                while (getchar() != '\n') ;
                printf("Invalid roll number.\n");
                return;
            }
            while (getchar() != '\n') ;
            found = NULL;
            temp = head;
            while (temp != NULL)
            {
                if (temp->rollno == roll && temp->percentage == percentage)
                    found = temp;
                temp = temp->next;
            }
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return;
    }

    if (found == NULL)
    {
        printf("Record not found.\n");
        return;
    }

    printf("Current: Roll=%d, Name=%s, Percentage=%.2f\n",
           found->rollno, found->name, found->percentage);
    printf("Enter new name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
        return;
    name[strcspn(name, "\n")] = '\0';

    if (name[0] == '\0')
    {
        printf("Name cannot be empty. Record unchanged.\n");
        return;
    }

    printf("Enter new percentage (0-100): ");
    if (scanf("%f", &percentage) != 1)
    {
        while (getchar() != '\n') ;
        printf("Invalid percentage. Record unchanged.\n");
        return;
    }
    while (getchar() != '\n') ;

    if (percentage < 0 || percentage > 100)
    {
        printf("Percentage must be from 0 to 100. Record unchanged.\n");
        return;
    }

    strcpy(found->name, name);
    found->percentage = percentage;
    printf("Record modified successfully.\n");
}
