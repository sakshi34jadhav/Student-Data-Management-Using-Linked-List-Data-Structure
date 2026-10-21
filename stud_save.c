#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void save_records(void)
{
    FILE *fp = fopen("student.dat", "wb");
    struct student *temp = head;

    if (fp == NULL)
    {
        printf("Could not open student.dat for saving.\n");
        return;
    }

    while (temp != NULL)
    {
        /* Save fields only; never save the pointer value. */
        fwrite(&temp->rollno, sizeof(temp->rollno), 1, fp);
        fwrite(temp->name, sizeof(temp->name), 1, fp);
        fwrite(&temp->percentage, sizeof(temp->percentage), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
    printf("Records saved in student.dat.\n");
}

void load_records(void)
{
    FILE *fp = fopen("student.dat", "rb");
    struct student *newnode, *tail = NULL;

    if (fp == NULL)
        return; /* No saved file yet: start with an empty list. */

    while (1)
    {
        int roll;
        char name[50];
        float percentage;

        if (fread(&roll, sizeof(roll), 1, fp) != 1)
            break;
        if (fread(name, sizeof(name), 1, fp) != 1 ||
            fread(&percentage, sizeof(percentage), 1, fp) != 1)
            break;

        name[49] = '\0';
        if (roll <= 0 || percentage < 0 || percentage > 100)
            continue;

        newnode = malloc(sizeof(struct student));
        if (newnode == NULL)
        {
            printf("Memory allocation failed while loading records.\n");
            break;
        }

        newnode->rollno = roll;
        strcpy(newnode->name, name);
        newnode->percentage = percentage;
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            tail->next = newnode;
        tail = newnode;
    }

    fclose(fp);
}

void delete_all(void)
{
    struct student *temp = head;

    while (temp != NULL)
    {
        struct student *next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;
    printf("All records deleted from memory. student.dat was not changed.\n");
}

void reverse_list(void)
{
    struct student *prev = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("List reversed successfully.\n");
}

void free_list(void)
{
    struct student *temp = head;

    while (temp != NULL)
    {
        struct student *next = temp->next;
        free(temp);
        temp = next;
    }

    head = NULL;
}
