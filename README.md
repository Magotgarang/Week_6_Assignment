# Week 6 Assignment

This repository contains solutions to the Week 6 assignment tasks for the music playlist, binary search tree, social network recommendation system, and emergency room management system.

## Table of Contents
1. [Music Playlist Manager](#1-music-playlist-manager)
2. [Binary Search Tree Database](#2-binary-search-tree-database)
3. [Social Network Recommendation System](#3-social-network-recommendation-system)
4. [Emergency Room Patient Management](#4-emergency-room-patient-management)

---

## 1. Music Playlist Manager

### Description:
This program manages a music playlist using a linked list. Each node is a song containing the song's name and time length. 
- Users can add new songs (appended to the end of the playlist).
- Play songs starting from the first one and continue until the last song is played.

### How to Run:
1. Compile the program:
    ```bash
    gcc -o playlist_manager music_playlist_manager.c
    ```
2. Run the program:
    ```bash
    ./playlist_manager
    ```

---

## 2. Binary Search Tree Database

### Description:
This program implements a database using a Binary Search Tree (BST) for products. Each node stores product details (ID, name, price, quantity).
- Users can insert products, search for products by name, update product details, and display products in sorted order.
- Track and display out-of-stock products.

### How to Run:
1. Compile the program:
    ```bash
    gcc -o bst_db binary_search_tree_db.c
    ```
2. Run the program:
    ```bash
    ./bst_db
    ```

---

## 3. Social Network Recommendation System

### Description:
This recommendation system uses Depth-First Search (DFS) to suggest new friends in a social network. Users are nodes, and their connections are represented by edges. The system explores connections and recommends friends who are not directly connected to the user.

### How to Run:
1. Compile the program:
    ```bash
    gcc -o recommendation_system recommendation_system_graph.c
    ```
2. Run the program:
    ```bash
    ./recommendation_system
    ```

---

## 4. Emergency Room Patient Management

### Description:
This program manages an emergency room queue using a max-heap. Patients are prioritized based on the severity of their condition. 
- The most severe cases are treated first. 
- Users can add patients, update severity, and display the current queue.

### How to Run:
1. Compile the program:
    ```bash
    gcc -o er_manager emergency_room_manager.c
    ```
2. Run the program:
    ```bash
    ./er_manager
    ```

---

## Notes
- Ensure `gcc` is installed to compile and run the programs.
- The programs are designed to run in the command-line interface (CLI).

---
