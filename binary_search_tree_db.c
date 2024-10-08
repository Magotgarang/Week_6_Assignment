#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100

// Structure representing a User in the social network
struct User {
    char name[50];
    int id;
};

// Structure representing the social network graph
struct Graph {
    int numUsers;
    int adjMatrix[MAX_USERS][MAX_USERS]; // Adjacency matrix
    struct User users[MAX_USERS]; // List of users (nodes)
};

// Function to create a new user in the network
void addUser(struct Graph *graph, int id, char *name) {
    struct User newUser;
    newUser.id = id;
    strcpy(newUser.name, name);
    graph->users[graph->numUsers] = newUser;
    graph->numUsers++;
}

// Function to add a connection (edge) between two users
void addConnection(struct Graph *graph, int user1, int user2) {
    graph->adjMatrix[user1][user2] = 1;
    graph->adjMatrix[user2][user1] = 1;
}

// Depth First Search function
void DFS(struct Graph *graph, int user, bool visited[]) {
    visited[user] = true;
    printf("Visited %s\n", graph->users[user].name);
    
    for (int i = 0; i < graph->numUsers; i++) {
        if (graph->adjMatrix[user][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to recommend new connections for a user
void recommendConnections(struct Graph *graph, int user) {
    bool visited[MAX_USERS] = {false};
    DFS(graph, user, visited);

    printf("Recommendations for %s:\n", graph->users[user].name);
    for (int i = 0; i < graph->numUsers; i++) {
        if (!visited[i] && i != user) {
            printf("Consider connecting with %s\n", graph->users[i].name);
        }
    }
}

// Function to initialize the graph
void initializeGraph(struct Graph *graph) {
    graph->numUsers = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

int main() {
    struct Graph network;
    initializeGraph(&network);

    // Add users to the network
    addUser(&network, 0, "Andrew");
    addUser(&network, 1, "Samuel");
    addUser(&network, 2, "Joshua");
    addUser(&network, 3, "David");
    addUser(&network, 4, "Peter");

    // Add connections (edges) between users
    addConnection(&network, 0, 1); // Andrew <-> joshua
    addConnection(&network, 0, 2); // Andrew <-> samuel
    addConnection(&network, 1, 3); // Joshua <-> David
    addConnection(&network, 2, 4); // peter <-> james

    // Recommend connections for Andrew
    recommendConnections(&network, 0);

    return 0;
}
