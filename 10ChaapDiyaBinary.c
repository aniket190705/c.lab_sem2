#include <stdio.h>

int copyBinaryFile(FILE *source, FILE *destination) {
    const size_t BUFFER_SIZE = 1024;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (fwrite(buffer, 1, bytesRead, destination) != bytesRead) {
            return 0; // Write error
        }
    }

    if (ferror(source) || ferror(destination)) {
        return 0; // Read or write error
    }

    return 1; // Success
}

int main() {
    char sourceFileName[100], destinationFileName[100];
    FILE *sourceFile, *destinationFile;

    printf("Enter source file name: ");
    scanf("%s", sourceFileName);

    printf("Enter destination file name: ");
    scanf("%s", destinationFileName);

    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL) {
        printf("Error opening destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (copyBinaryFile(sourceFile, destinationFile)) {
        printf("File copied successfully.\n");
    } else {
        printf("Error copying file.\n");
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
