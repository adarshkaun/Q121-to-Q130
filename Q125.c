#include <stdio.h>

int main() {
    FILE *fp;
    char filename[50];
    char line[200];

    printf("Enter filename to open in append mode: ");
    scanf("%s", filename);
    getchar();  // clear newline left by scanf

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter a new line to append: ");
    fgets(line, sizeof(line), stdin);

    fputs(line, fp);

    fclose(fp);

    printf("Text appended successfully.\n");

    return 0;
}
