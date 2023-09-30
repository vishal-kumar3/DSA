
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct Book Book;
typedef struct Genre Genre;

Book* createBook(char title[], char author[], int publicationYear) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook != NULL) {
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        newBook->publicationYear = publicationYear;
        newBook->nextBook = NULL;
    }
    return newBook;
}

Genre* createGenre(char genreName[]) {
    Genre* newGenre = (Genre*)malloc(sizeof(Genre));
    if (newGenre != NULL) {
        strcpy(newGenre->genreName, genreName);
        newGenre->books = NULL;     // Initialize the book list to empty
        newGenre->nextGenre = NULL;
    }
    return newGenre;
}

void insertBookAtFront(Book** book, char title[], char author[], int publicationYear){
    Book* newBook = createBook(title, author, publicationYear);
    newBook->nextBook = *book;
    *book = newBook;
}

void insertGenreAtFront(Genre** genre, char genreName[]){
    Genre* newGenre = createGenre(genreName);
    newGenre->nextGenre = *genre;
    *genre = newGenre;
    printf("\n[+] %s is added to Genre List!!!", genreName);
}

void insertBookToGenre(Genre* genre){
    Genre* currentGenre = genre;
    char genreName[50];
    printf("\nEnter Genre Name:- ");
    scanf(" %[^\n]", genreName); 

    while(currentGenre != NULL){
        if(strcmp(currentGenre->genreName, genreName)==0){
            Book** currentBook = &(currentGenre->books);
            char bookName[50], author[50];
            int year;
            printf("Enter Book's Title:- ");
            scanf(" %[^\n]", &bookName); 
            printf("Enter Book's Author Name:- "); 
            scanf(" %[^\n]", &author); 
            printf("Enter Book's Publication Year:- "); 
            scanf("%d", &year);
            insertBookAtFront(currentBook, bookName, author, year);
            printf("\n[+] %s is added to Genre %s", bookName, genreName);
        }
        currentGenre = currentGenre->nextGenre;
    }
}

// void deleteGenreFromFront(Genre** genre){
//     Genre* freeGenre = *genre;
//     *genre = freeGenre->nextGenre;
//     while((*genre)->books != NULL){
//         deleteBookFromFront((*genre)->books);
//         (*genre)->books = (*genre)->books->nextBook;
//     }
//     free(freeGenre);
// }



// void deleteBookFromFront(Book* book){
//     Book* freeBook = book;
//     book = book->nextBook;

//     free(freeBook);
// }

void displayBook(Book* book){
    Book* temp = book;
    printf("\n");
    while(temp != NULL){
        printf("%s ", temp->title);
        temp = temp->nextBook;
    }
    printf("\n");
}


// void displayGenre(Genre* genre){
//     Genre* tmp = genre;
//     while(tmp != NULL){
//         printf("%s ", tmp->genreName);
//         tmp = tmp->nextGenre;
//     }
//     printf("\n");
// }

void displayGenreBook(Genre* genre){
    Genre* tmp = genre;
    while(tmp != NULL){
        printf("\n%s-->", tmp->genreName);
        Book* tmpBook = tmp->books;
        while(tmpBook != NULL){
            printf(" %s", tmpBook->title);
            tmpBook = tmpBook->nextBook;
        }
        tmp = tmp->nextGenre;
    }
    printf("\n");
}

void bindGenreAndBooks(Genre** genre, Book** book){
    if((*genre)->books == NULL){
        (*genre)->books = *book;
    }
}


Book* search(Genre* genre, char genreName[], char bookName[]){
    Genre* tmpGenre = genre;
    while(tmpGenre != NULL){
        if(strcmp(tmpGenre->genreName, genreName)==0){
            Book* tmpBook = genre->books;
            while(tmpBook != NULL){
                if(strcmp(tmpBook->title, bookName)==0){
                    return tmpBook;
                }
            }
        }
        tmpGenre = tmpGenre->nextGenre;
    }
    return NULL;
}

void updateBook(Genre** genre, char bookName[]){
    Book* tmpBook = (*genre)->books;
    while(tmpBook != NULL){
        if(strcmp(tmpBook->title, bookName)==0){
            char* updateBookName = (char*)malloc(20*sizeof(char));
            char* updateBookAuthor = (char*)malloc(20*sizeof(char));
            int* updateBookPublicationYear = (int*)malloc(20*sizeof(int));

            printf("\nUpdate Book Name: ");
            scanf(" %[^\n]", updateBookName);
            printf("Update Book Author: ");
            scanf(" %[^\n]", updateBookAuthor);
            printf("Update Book PublicationYear: ");
            scanf("%d", updateBookPublicationYear);

            strcpy(tmpBook->title, updateBookName);
            strcpy(tmpBook->author, updateBookAuthor);
            tmpBook->publicationYear = *updateBookPublicationYear;
            displayGenreBook(*genre);
            return;
        }
        tmpBook = tmpBook->nextBook;
    }
}

void updateGenre(Genre** genre, char genreName[], char bookName[]){
    Genre* tmpGenre = *genre;
    while(tmpGenre != NULL){
        if(strcmp(tmpGenre->genreName, genreName)==0){
            char boolUpdateGenre;
            printf("\nIf you want to update Genre Name? (y/n) ");
            scanf("%s", &boolUpdateGenre);
            if(strcmp(boolUpdateGenre, "y")==0){
                char* updateGenreName = (char*)malloc(20*sizeof(char));
                printf("\nUpdate Genre Name: ");
                scanf(" %[^\n]", updateGenreName);
                strcpy(tmpGenre->genreName, updateGenreName);
            }
            updateBook(&tmpGenre, bookName);
            return;
        }
        tmpGenre = tmpGenre->nextGenre;
    }

}

void deleteSpecificBook(Genre** head){
    char genreNameDelete[50], bookNameDelete[50];
    printf("\nEnter Genre Name:- ");
    scanf(" %[^\n]", genreNameDelete);
    printf("Enter Book Name:- ");
    scanf(" %[^\n]", bookNameDelete);

    Genre* currentGenre = *head;
    while(currentGenre != NULL){
        if(strcmp(currentGenre->genreName, genreNameDelete)==0){
            // Always remember to store head so that you can change when needed.
            Book** books = &(currentGenre->books);
            Book* currentBook = *books;
            Book* prev = NULL;
            while(currentBook != NULL){
                if(strcmp(currentBook->title, bookNameDelete)==0){
                    if(prev==NULL){
                        *books = currentBook->nextBook;
                    }
                    else{
                        prev->nextBook = currentBook->nextBook;
                    }
                    free(currentBook);
                    return;
                }
                prev = currentBook;
                currentBook = currentBook->nextBook;
            }
        }
        currentGenre = currentGenre->nextGenre;
    }
}


void deleteGenre(Genre** head){
    char genreNameDelete[50];
    printf("\nEnter Genre Name:- ");
    scanf(" %[^\n]", genreNameDelete);

    Genre* currentGenre = *head;
    Genre* prevGenre = NULL;

    while(currentGenre != NULL){
        if(strcmp(currentGenre->genreName, genreNameDelete)==0){
            Book** deleteBooks = &(currentGenre->books);
            while(*deleteBooks!=NULL){
                Book* tmp = *deleteBooks;
                *deleteBooks = (*deleteBooks)->nextBook;
                free(tmp);
            }
            if(prevGenre==NULL){
                *head = currentGenre->nextGenre;
            }
            else{
                prevGenre->nextGenre = currentGenre->nextGenre;
                free(currentGenre);
                return;
            }
        }
        prevGenre = currentGenre;
        currentGenre = currentGenre->nextGenre;
    }
}

int main(){

    Genre* genres = NULL;

    while(1){

        printf("\n\n1.Add new Genre."
        "\n2.Add new book to specific Genre"
        "\n3.Display All Genres and Books"
        "\n4.Delete Complete Genre with all Books under it"
        "\n5.Delete specific Book"
        "\n6.Update Genre/Book Details");

        int choice;
        char genreName[50];
        char bookName[50];
        printf("\n\nChoice> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nGenre Title> ");
            scanf(" %[^\n]", genreName);
            insertGenreAtFront(&genres, genreName);
            break;

        case 2:
            insertBookToGenre(genres);
            break;
        
        case 3:
            displayGenreBook(genres);
            break;

        case 4:
            deleteGenre(&genres);
            break;

        case 5:
            deleteSpecificBook(&genres);
            break;

        case 6:
            printf("\nUpdate Genre...\nSelect Genre> ");
            scanf(" %[^\n]", &genreName);
            printf("Select Book> ");
            scanf(" %[^\n]", &bookName);
            updateGenre(&genres, genreName, bookName);
            break;

        default:
            return 0;
        }
    }


    return 0;
}
