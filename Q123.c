#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("info.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        characters++;

        if (ch == '\n')
            lines++;

        if (!isspace(ch)) {
            if (inWord == 0) {
                words++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    fclose(fp);

    // If file does not end with a newline, still count the last line
    if (characters > 0 && ch == EOF)
        lines++;

    printf("Total Characters: %d\n", characters);
    printf("Total Words: %d\n", words);
    printf("Total Lines: %d\n", lines);

    return 0;
}
