#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char ch;

    // Open source file in read mode
    srcFile = fopen(source, "r");
    if (srcFile == NULL) {
        printf("Cannot open source file %s\n", source);
        exit(EXIT_FAILURE);
    }

    // Open destination file in write mode
    destFile = fopen(destination, "w");
    if (destFile == NULL) {
        printf("Cannot open destination file %s\n", destination);
        fclose(srcFile);
        exit(EXIT_FAILURE);
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(srcFile);
    fclose(destFile);
}

void createFile(const char *filename) {
    FILE *file;
    char line[256];

    // Open file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter content to write into the file (type 'END' on a new line to finish):\n");

    // Write user input to file until "END" is entered
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0 && (line[3] == '\n' || line[3] == '\0')) {
            break;
        }
        fputs(line, file);
    }

    printf("File created successfully.\n");

    // Close file
    fclose(file);
}

void appendToFile(const char *filename) {
    FILE *file;
    char line[256];

    // Open file in append mode
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    printf("Enter content to append to the file (type 'END' on a new line to finish):\n");

    // Write user input to file until "END" is entered
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strncmp(line, "END", 3) == 0 && (line[3] == '\n' || line[3] == '\0')) {
            break;
        }
        fputs(line, file);
    }

    printf("File appended successfully.\n");

    // Close file
    fclose(file);
}

void viewFileContent(const char *filename) {
    FILE *file;
    char ch;

    // Open file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    printf("Content of %s:\n", filename);

    // Read and display file content
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    printf("\n");

    // Close file
    fclose(file);
}

void deleteFile(const char *filename) {
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        printf("Cannot delete file %s\n", filename);
    }
}

void renameFile(const char *oldName, const char *newName) {
    if (rename(oldName, newName) == 0) {
        printf("File renamed successfully from %s to %s.\n", oldName, newName);
    } else {
        printf("Cannot rename file %s to %s\n", oldName, newName);
    }
}

int main() {
    int choice;
    char source[100], destination[100], filename[100], newFilename[100];

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Copy file\n");
        printf("2. Create file\n");
        printf("3. View file content\n");
        printf("4. Delete file\n");
        printf("5. Append to file\n");
        printf("6. Rename file\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the source file name: ");
                scanf("%s", source);
                printf("Enter the destination file name: ");
                scanf("%s", destination);
                copyFile(source, destination);
                break;
            case 2:
                printf("Enter the new file name: ");
                scanf("%s", filename);
                getchar(); // to consume the newline character left by scanf
                createFile(filename);
                break;
            case 3:
                printf("Enter the file name to view: ");
                scanf("%s", filename);
                viewFileContent(filename);
                break;
            case 4:
                printf("Enter the file name to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 5:
                printf("Enter the file name to append to: ");
                scanf("%s", filename);
                getchar(); // to consume the newline character left by scanf
                appendToFile(filename);
                break;
            case 6:
                printf("Enter the current file name: ");
                scanf("%s", filename);
                printf("Enter the new file name: ");
                scanf("%s", newFilename);
                renameFile(filename, newFilename);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}