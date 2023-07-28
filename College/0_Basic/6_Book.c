/* Dynamic Memory Allocation - Structure Array: Create a structure named "Book" with members "title"
(string) and "author" (string). Prompt the user to enter the number of books and allocate memory
dynamically to store an array of "Book" structures. Prompt the user to enter details for each book and
print them. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
};

int main() {
    int numBooks;

    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    struct Book* booksArray = (struct Book*)malloc(numBooks * sizeof(struct Book));


    for (int i = 0; i < numBooks; i++) {
        printf("Enter the details for Book %d:\n", i + 1);

        printf("Title: ");
        scanf(" %[^\n]", booksArray[i].title);

        printf("Author: ");
        scanf(" %[^\n]", booksArray[i].author);

        printf("\n");
    }

    printf("Details of the entered books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Book %d\n", i + 1);
        printf("Title: %s\n", booksArray[i].title);
        printf("Author: %s\n", booksArray[i].author);
        printf("\n");
    }

    free(booksArray);

    return 0;
}
