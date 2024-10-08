#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int friend;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numUsers;
    struct Node** adjList;
    int* visited;
};

// Function to create a graph
struct Graph* createGraph(int users) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numUsers = users;
    graph->adjList = (struct Node**)malloc(users * sizeof(struct Node*));
    graph->visited = (int*)malloc(users * sizeof(int));
    
    for (int i = 0; i < users; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    
    return graph;
}

// Add friend to graph
void addFriend(struct Graph* graph, int user, int friend) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->friend = friend;
    newNode->next = graph->adjList[user];
    graph->adjList[user] = newNode;
}

// DFS to recommend friends
void recommendFriends(struct Graph* graph, int user) {
    struct Node* temp = graph->adjList[user];
    printf("Recommended friends for user %d:\n", user);
    while (temp) {
        if (!graph->visited[temp->friend]) {
            printf("User %d\n", temp->friend);
            graph->visited[temp->friend] = 1;
            recommendFriends(graph, temp->friend);
        }
        temp = temp->next;
    }
}

// Main function
int main() {
    int users = 5;
    struct Graph* graph = createGraph(users);

    addFriend(graph, 0, 1);
    addFriend(graph, 0, 2);
    addFriend(graph, 1, 3);
    addFriend(graph, 2, 4);
    
    recommendFriends(graph, 0);

    return 0;
}
