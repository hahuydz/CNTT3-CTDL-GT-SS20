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
int findMax(Node* root) {
    if (root == NULL) {
        return -1000000000000;
    }
    int maxLeft = findMax(root->left);
    int maxRight = findMax(root->right);
    int max=root->data;
    if (maxLeft > maxRight) {
        max=maxLeft;
    }
    if (maxRight > max) {
        max=maxRight;
    }
    return max;
}
int main() {
    Node*root=createNode();
    root->left = createNode();
    root->right = createNode();
    int maxvalue=findMax(root);
    printf("Max value: %d\n", maxvalue);
    printf("Da them thanh cong : ");
    return 0;
}
