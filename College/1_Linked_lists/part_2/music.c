#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SongNode {
    char title[100];
    char artist[100];
    struct SongNode* nextSong;
};

void displayPlaylist(struct SongNode* song) {
    struct SongNode* currentSong = song;
    while (currentSong != NULL) {
        printf("Title: %s | Artist: %s\n", currentSong->title, currentSong->artist);
        currentSong = currentSong->nextSong;
    }
}

void addSong(struct SongNode** playlist, const char* title, const char* artist) {
    struct SongNode* newSong = (struct SongNode*)malloc(sizeof(struct SongNode));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->nextSong = NULL;

    if (*playlist == NULL) {
        *playlist = newSong;
    } else {
        struct SongNode* currentSong = *playlist;
        while (currentSong->nextSong != NULL) {
            currentSong = currentSong->nextSong;
        }
        currentSong->nextSong = newSong;
    }
}

void removeSong(struct SongNode** playlist, const char* title) {
    struct SongNode* currentSong = *playlist;
    struct SongNode* previousSong = NULL;

    while (currentSong != NULL) {
        if (strcmp(currentSong->title, title) == 0) {
            if (previousSong == NULL) {
                *playlist = currentSong->nextSong;
            } else {
                previousSong->nextSong = currentSong->nextSong;
            }
            free(currentSong);
            printf("[+] Song '%s' is removed!\n", title);
            return;
        }
        previousSong = currentSong;
        currentSong = currentSong->nextSong;
    }
    printf("[-] Song '%s' not found!\n", title);
}

void reversePlaylist(struct SongNode** playlist) {
    struct SongNode* currentSong = *playlist;
    struct SongNode* previousSong = NULL;

    while (currentSong != NULL) {
        struct SongNode* currNextSong = currentSong->nextSong;
        currentSong->nextSong = previousSong;
        previousSong = currentSong;
        currentSong = currNextSong;
    }

    *playlist = previousSong;
}

int playlistLength(struct SongNode** playlist) {
    struct SongNode* currentSong = *playlist;
    int size = 0;

    while (currentSong != NULL) {
        size++;
        currentSong = currentSong->nextSong;
    }

    return size;
}

int searchSong(struct SongNode** playlist, const char* targetTitle) {
    struct SongNode* currentSong = *playlist;
    int pos = 0;

    while (currentSong != NULL) {
        if (strcmp(currentSong->title, targetTitle) == 0) {
            return pos;
        }
        currentSong = currentSong->nextSong;
        pos++;
    }
    return -1;
}

int main() {
    struct SongNode* playlist = NULL;

    printf("\nOperations for Music Playlist:\n");
    printf(" 1.Add a song to the playlist\n");
    printf(" 2.Remove a song by title\n");
    printf(" 3.Display the playlist\n");
    printf(" 4.Reverse the playlist\n");
    printf(" 5.Search for a song\n");
    printf(" 6.Exit the program\n");

    while (1) {
        int choice;
        printf("\nChoice> ");
        scanf("%d", &choice);

        char title[100];
        char artist[100];

        if (choice != 3 && choice < 6 && choice != 4) {
            printf("Title> ");
            scanf("%s", title);
            printf("Artist> ");
            scanf("%s", artist);
        }

        switch (choice) {
            case 1:
                addSong(&playlist, title, artist);
                printf("[+] Song '%s' by %s is added!\n", title, artist);
                break;

            case 2:
                removeSong(&playlist, title);
                break;

            case 3:
                displayPlaylist(playlist);
                printf("\n");
                break;

            case 4:
                reversePlaylist(&playlist);
                printf("[+] Playlist is reversed!\n");
                break;

            case 5:
                printf("[+] Song '%s' found at position %d!\n", title, searchSong(&playlist, title));
                break;

            case 6:
                printf("\nEXITING THE PROGRAM!\n");
                return 0;
                break;

            default:
                printf("[-] Please choose a valid option!\n");
                break;
        }
    }

    return 0;
}
