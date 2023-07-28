#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    FILE *destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        printf("Error opening the destination file.\n");
        fclose(source_file);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");
    return 0;
}
