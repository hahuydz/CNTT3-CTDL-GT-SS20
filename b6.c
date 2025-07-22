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
int findLevel(Node* root,int value,int currentLevel) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return currentLevel;
    }
    int levelLeft = findLevel(root->left,value,currentLevel+1);
    if (levelLeft != 0) {
        return levelLeft;
    }
    int levelRight = findLevel(root->right,value,currentLevel+1);
    if (levelRight != 0) {
        return levelRight;
    }
}
int main() {
    Node*root=createNode();
    root->left = createNode();
    root->right = createNode();
    printf("Da them thanh cong : ");
    int target;
    printf("Moi ban nhap gia tri can tim");
    scanf("%d",&target);
    int level = findLevel(root,target,1);
    if (level==0) {
        printf("Khong tim thay");
    }
    else {
        printf("Gia thi %d nam o tang %d",target,level);
    }
    return 0;
}
