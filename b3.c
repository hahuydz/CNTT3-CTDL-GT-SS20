#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX_QUEUE 100

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));\
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preorder(Node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
typedef struct {
    Node*data[MAX_QUEUE];
    int front;
    int rear;
}Queue;
void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}
bool isQueueEmpty(Queue *queue) {
    return queue->rear == queue->front;
}
void enQueue(Queue *queue, Node* node) {
    if ((queue->rear+1)% MAX_QUEUE==queue->front) {
        printf("Queue is full\n");
        return;
    }
    queue->data[queue->rear] = node;
    queue->rear = (queue->rear+1)% MAX_QUEUE;
}
Node*deQueue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    Node*temp = queue->data[queue->front];
    queue->front = (queue->front+1)% MAX_QUEUE;
    return temp;
}
void insertNode(Node*root,int value) {
    if (root==NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q,root);
    while(!isQueueEmpty(&q)) {
        Node*current=deQueue(&q);
        if (current->left==NULL) {
            current->left=createNode(value);
            return;
        }else {
            enQueue(&q,current->left);
        }
        if (current->right==NULL) {
            current->right=createNode(value);
            return;
        }else {
            enQueue(&q,current->right);
        }
    }
}
int main() {
    Node*root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    int newValue;
    printf("Moi ban nhap gia tri moi vao ds: ");
    scanf("%d",&newValue);
    insertNode(root,newValue);
    printf("Cay duyet theo sau khi them: ");
    preorder(root);
    printf("\n");
    return 0;
}
