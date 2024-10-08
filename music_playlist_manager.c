#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a song
struct Song {
    char name[50];
    int duration; // song length in seconds
    struct Song *next;
};

// Function to create a new song node
struct Song* createSong(char *name, int duration) {
    struct Song *newSong = (struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->name, name);
    newSong->duration = duration;
    newSong->next = NULL;
    return newSong;
}

// Function to append a song to the playlist
void appendSong(struct Song **head, char *name, int duration) {
    struct Song *newSong = createSong(name, duration);
    if (*head == NULL) {
        *head = newSong;
    } else {
        struct Song *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}

// Function to play the playlist
void playPlaylist(struct Song *head) {
    struct Song *temp = head;
    while (temp != NULL) {
        printf("Playing: %s (%d seconds)\n", temp->name, temp->duration);
        temp = temp->next;
    }
}

int main() {
    struct Song *playlist = NULL;
    appendSong(&playlist, "Song 1", 210);
    appendSong(&playlist, "Song 2", 180);
    appendSong(&playlist, "Song 3", 200);
    
    printf("Starting Playlist:\n");
    playPlaylist(playlist);
    
    return 0;
}

