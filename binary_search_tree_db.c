#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Product *left, *right;
};

// Function to create a new product node
struct Product* createProduct(int id, char *name, float price, int quantity) {
    struct Product *newProduct = (struct Product*)malloc(sizeof(struct Product));
    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->left = newProduct->right = NULL;
    return newProduct;
}

// Insert product into the BST
struct Product* insertProduct(struct Product* root, int id, char *name, float price, int quantity) {
    if (root == NULL) return createProduct(id, name, price, quantity);
    if (id < root->id) root->left = insertProduct(root->left, id, name, price, quantity);
    else if (id > root->id) root->right = insertProduct(root->right, id, name, price, quantity);
    return root;
}

// In-order traversal to display products in ascending order
void displayProducts(struct Product *root) {
    if (root != NULL) {
        displayProducts(root->left);
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", root->id, root->name, root->price, root->quantity);
        displayProducts(root->right);
    }
}

// Search product by name
struct Product* searchProduct(struct Product* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
        return searchProduct(root->left, name);
    return searchProduct(root->right, name);
}

// Main function
int main() {
    struct Product *root = NULL;
    root = insertProduct(root, 101, "Laptop", 899.99, 10);
    root = insertProduct(root, 102, "Mouse", 19.99, 50);
    root = insertProduct(root, 103, "Keyboard", 49.99, 20);

    printf("Product List:\n");
    displayProducts(root);

    char searchName[50] = "Mouse";
    struct Product *foundProduct = searchProduct(root, searchName);
    if (foundProduct != NULL)
        printf("\nFound Product: %s, Price: %.2f\n", foundProduct->name, foundProduct->price);
    else
        printf("\nProduct not found.\n");

    return 0;
}

