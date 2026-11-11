#include <stdio.h>

#define MAX 50   // maximum number of students

// A struct groups related data together
struct Student {
    int roll;
    char name[30];
    float marks;
};

int main() {
    struct Student s[MAX];   // array of students
    int count = 0;           // how many students are stored
    int choice, i, searchRoll, found;

    while (1) {
        printf("\n===== STUDENT DATABASE =====\n");
        printf("1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Search by roll number\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count >= MAX) {
                printf("Database is full!\n");
            } else {
                printf("Enter roll number: ");
                scanf("%d", &s[count].roll);
                printf("Enter name (no spaces): ");
                scanf("%s", s[count].name);
                printf("Enter marks: ");
                scanf("%f", &s[count].marks);
                count++;
                printf("Student added!\n");
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("No students yet.\n");
            } else {
                printf("\nRoll\tName\t\tMarks\n");
                printf("----------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("%d\t%-10s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
                }
            }
        }
        else if (choice == 3) {
            printf("Enter roll number to search: ");
            scanf("%d", &searchRoll);
            found = 0;
            for (i = 0; i < count; i++) {
                if (s[i].roll == searchRoll) {
                    printf("Found: %s, Marks = %.2f\n", s[i].name, s[i].marks);
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                printf("Student not found.\n");
            }
        }
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
