#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

extern void read_text(char text[], int size);

void add_record(void)
{
    struct student *newnode, *temp;
    int roll = 1;
    char name[50];
    float percentage;

    /* Find the smallest positive roll number not already used. */
    while (1)
    {
        temp = head;
        while (temp != NULL && temp->rollno != roll)
            temp = temp->next;

        if (temp == NULL)
            break;
        roll++;
    }

    newnode = malloc(sizeof(struct student));
    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Assigned roll number: %d\n", roll);
    printf("Enter student name: ");
    read_text(name, sizeof(name));

    if (name[0] == '\0')
    {
        printf("Name cannot be empty. Record not added.\n");
        free(newnode);
        return;
    }

    printf("Enter percentage (0-100): ");
    if (scanf("%f", &percentage) != 1)
    {
        while (getchar() != '\n') ;
        printf("Invalid percentage. Record not added.\n");
        free(newnode);
        return;
    }
    while (getchar() != '\n') ;

    if (percentage < 0 || percentage > 100)
    {
        printf("Percentage must be from 0 to 100.\n");
        free(newnode);
        return;
    }

    newnode->rollno = roll;
    strcpy(newnode->name, name);
    newnode->percentage = percentage;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Record added successfully.\n");
}
