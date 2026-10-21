#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct student *head = NULL;

/* Simple input helper: read one line and remove newline */
void read_text(char text[], int size)
{
    if (fgets(text, size, stdin) != NULL)
        text[strcspn(text, "\n")] = '\0';
}

int main(void)
{
    char choice, exit_choice;

    load_records();

    while (1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");

        if (scanf(" %c", &choice) != 1)
            break;
        while (getchar() != '\n')
            ;

        switch (choice)
        {
            case 'a': case 'A': add_record(); break;
            case 'd': case 'D': delete_record(); break;
            case 's': case 'S': show_records(); break;
            case 'm': case 'M': modify_record(); break;
            case 'v': case 'V':
                save_records();
                break;
            case 't': case 'T': sort_records(); break;
            case 'l': case 'L': delete_all(); break;
            case 'r': case 'R': reverse_list(); break;

            case 'e': case 'E':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");
                if (scanf(" %c", &exit_choice) != 1)
                    exit_choice = 'e';
                while (getchar() != '\n')
                    ;

                if (exit_choice == 's' || exit_choice == 'S')
                    save_records();
                else if (exit_choice != 'e' && exit_choice != 'E')
                {
                    printf("Invalid choice. Returning to menu.\n");
                    break;
                }

                free_list();
                printf("All allocated memory released. Goodbye.\n");
                return 0;

            default:
                printf("Invalid menu choice. Try again.\n");
        }
    }

    free_list();
    return 0;
}
