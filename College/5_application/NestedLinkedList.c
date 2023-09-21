
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book{
    char title[50];
    char author[50];
    int publicationYear;
    struct Book* nextBook;
};

struct Genre{
    char genreName[10];
    struct Book* books;
    struct Genre* nextGenre;    
};

struct Book* createBook(char title[], char author[], int publicationYear) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook != NULL) {
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        newBook->publicationYear = publicationYear;
        newBook->nextBook = NULL;
    }
    return newBook;
}

struct Genre* createGenre(char genreName[]) {
    struct Genre* newGenre = (struct Genre*)malloc(sizeof(struct Genre));
    if (newGenre != NULL) {
        strcpy(newGenre->genreName, genreName);
        newGenre->books = NULL;     // Initialize the book list to empty
        newGenre->nextGenre = NULL;
    }
    return newGenre;
}

void insertBookAtFront(struct Book** book, char title[], char author[], int publicationYear){
    struct Book* newBook = createBook(title, author, publicationYear);
    newBook->nextBook = *book;
    *book = newBook;
}

void deleteBookFromFront(struct Book** book){
    struct Book* freeBook = *book;
    *book = freeBook->nextBook;
    free(freeBook);
}

void displayBook(struct Book* book){
    struct Book* temp = book;
    printf("\n");
    while(temp != NULL){
        printf("%d ", temp->publicationYear);
        temp = temp->nextBook;
    }
    printf("\n");
}

void insertGenreAtFront(struct Genre** genre, char genreName[]){
    struct Genre* newGenre = createGenre(genreName);
    newGenre->nextGenre = *genre;
    *genre = newGenre;
}

void deleteGenreFromFront(struct Genre** genre){
    struct Genre* freeGenre = *genre;
    *genre = freeGenre->nextGenre;
    while((*genre)->books != NULL){
        deleteBookFromFront((*genre)->books);
        (*genre)->books = (*genre)->books->nextBook;
    }
    free(freeGenre);
}

void displayGenre(struct Genre* genre){
    struct Genre* tmp = genre;
    while(tmp != NULL){
        printf("%s ", tmp->genreName);
        tmp = tmp->nextGenre;
    }
    printf("\n");
}

void displayGenreBook(struct Genre* genre){
    struct Genre* tmp = genre;
    while(tmp != NULL){
        printf("\n%s-->", tmp->genreName);
        while(tmp->books != NULL){
            printf(" %s", tmp->books->title);
            tmp->books = tmp->books->nextBook;
        }
        tmp = tmp->nextGenre;
    }
    printf("\n");
}

void bindGenreAndBooks(struct Genre** genre, struct Book** book){
    if((*genre)->books == NULL){
        (*genre)->books = *book;
    }
    insertBookAtFront(book, (*book)->title, (*book)->author, (*book)->publicationYear);
}

int main(){

    struct Book* book = createBook("HarryPotter", "JKRolling", 2001);
    struct Genre* adventure = createGenre("adventure");

    insertBookAtFront(&book, "HP", "JK", 2002);
    insertBookAtFront(&book, "HP", "JK", 2003);
    insertBookAtFront(&book, "HP", "JK", 2004);

    bindGenreAndBooks

    return 0;
}