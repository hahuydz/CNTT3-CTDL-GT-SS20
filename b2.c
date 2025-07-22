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
//Cac ham duyet cay
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
    printf("\n");
}
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
    printf("\n");
}
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
//level order
typedef struct {
    Node*data[100];
    int front,rear;
}Queue;
void initQueue(Queue*q) {
    q->front=q->rear=0;
}
int isEmpty(Queue*q) {
    return q->front == q->rear;
}
void enqueue(Queue*q,Node*node) {
    if ((q->rear+1)%100==q->front) {
        printf("Hang doi day: ");
        return;
    }
    q->data[q->rear] = node;
    q->rear = (q->rear+1)%100;
}
Node*dequeue(Queue*q) {
    if (isEmpty(q)) {
        return NULL;
    }
    Node*node=q->data[q->front];
    q->front = (q->front+1)%100;
    return node;
}
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enqueue(&q,root);
    while(!isEmpty(&q)) {
        Node*current=dequeue(&q);
        printf("%d ",current->data);
        if (current->left!=NULL) {
            enqueue(&q,current->left);
        }
        if (current->right!=NULL) {
            enqueue(&q,current->right);
        }
    }
}
int main() {
    Node*root=createNode();
    printf("Tao nut ben trai cua goc: ");
    root->left=createNode();
    printf("Tao nut ben phai cua goc: ");
    root->right=createNode();
    printf("Duyet cay theo preoder");
    preOrder(root);
    printf("Duyet cay theo inOrder");
    inOrder(root);
    printf("Duyet cay theo postOrder");
    postOrder(root);
    printf("Duyet cay theo levelOrder");
    levelOrder(root);
    return 0;
}
