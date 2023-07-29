#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    struct Song* next;
};

void displayPlaylist(struct Song* playlist) {
    struct Song* current = playlist;
    while (current != NULL) {
        printf("%s - %s\n", current->title, current->artist);
        current = current->next;
    }
}

void addSongToPlaylist(const char* title, const char* artist, struct Song* playlist) {
    struct Song* current = playlist;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (struct Song*)malloc(sizeof(struct Song));
    current = current->next;
    strcpy(current->title, title);
    strcpy(current->artist, artist);
    current->next = NULL;
}

void removeSongFromPlaylist(const char* title, struct Song** playlist) {
    struct Song* current = *playlist;
    struct Song* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                *playlist = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int playlistLength(struct Song* playlist) {
    struct Song* current = playlist;
    int size = 0;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

int searchSongInPlaylist(const char* title, struct Song* playlist) {
    struct Song* current = playlist;
    int pos = 0;

    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return pos;
        }
        current = current->next;
        pos++;
    }
    return -1;
}

int main() {
    struct Song* playlist;
    struct Song* song1 = (struct Song*)malloc(sizeof(struct Song));
    strcpy(song1->title, "Song Title 1");
    strcpy(song1->artist, "Artist 1");
    song1->next = NULL;
    playlist = song1;

    addSongToPlaylist("Song Title 2", "Artist 2", playlist);
    addSongToPlaylist("Song Title 3", "Artist 3", playlist);

    printf("\nPosition of Song Title 2 in the playlist: %d\n", searchSongInPlaylist("Song Title 2", playlist));

    printf("\nPlaylist:\n");
    displayPlaylist(playlist);

    printf("\n");

    // Remove "Song Title 1" from the playlist
    removeSongFromPlaylist("Song Title 1", &playlist);

    // Display updated playlist
    printf("\nUpdated Playlist:\n");
    displayPlaylist(playlist);

    printf("\n");

    // Free allocated memory for the songs in the playlist
    struct Song* current = playlist;
    while (current != NULL) {
        struct Song* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
