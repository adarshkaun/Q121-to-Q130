#include <stdio.h>

int main() {
    FILE *src, *dest;
    char srcFile[50], destFile[50];
    int ch;

    printf("Enter source filename: ");
    scanf("%s", srcFile);

    printf("Enter destination filename: ");
    scanf("%s", destFile);

    src = fopen(srcFile, "r");
    if (src == NULL) {
        printf("Error: Cannot open source file.\n");
        return 1;
    }

    dest = fopen(destFile, "w");
    if (dest == NULL) {
        printf("Error: Cannot open destination file.\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully from %s to %s\n", srcFile, destFile);

    return 0;
}
