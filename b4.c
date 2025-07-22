#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node*createNode() {
    int data;
    printf("Enter Data: ");
    scanf("%d", &data);
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right) + 1;
}
int main() {
    Node*root=createNode();
    root->left = createNode();
    root->right = createNode();
    int numleaves = countLeaves(root);
    printf("\nNumber of leaves: %d\n", numleaves);
    return 0;
}
