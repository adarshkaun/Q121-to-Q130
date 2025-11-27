#include <stdio.h>

#define MAX 100

int main() {
    FILE *fp;
    int n, i;
    char name[50];
    int roll;
    float marks;

    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter roll number: ");
        scanf("%d", &roll);

        printf("Enter marks: ");
        scanf("%f", &marks);

        fprintf(fp, "%s %d %.2f\n", name, roll, marks);
    }

    fclose(fp);

    printf("\nRecords saved successfully!\n\n");

    // ---------- Reading Phase ----------
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("----- Student Records -----\n\n");

    while (fscanf(fp, "%s %d %f", name, &roll, &marks) == 3) {
        printf("Name  : %s\n", name);
        printf("Roll  : %d\n", roll);
        printf("Marks : %.2f\n", marks);
        printf("---------------------------\n");
    }

    fclose(fp);

    return 0;
}
