// All the operations of queue data structure namely Enqueue, Dequeue and Print implemented using Priority Queues

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

typedef struct PriorityQueue {
    struct Node *head;
} PriorityQueue;

PriorityQueue *createPriorityQueue() {
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

int isEmptyPriorityQueue(PriorityQueue *pq) {
    return pq->head == NULL;
}

void enqueuePriorityQueue(PriorityQueue *pq, int data, int priority) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;

    if (isEmptyPriorityQueue(pq) || pq->head->priority < priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node *temp = pq->head;
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeuePriorityQueue(PriorityQueue *pq) {
    if (isEmptyPriorityQueue(pq)) {
        return -1;
    }

    Node *temp = pq->head;
    pq->head = pq->head->next;

    int data = temp->data;
    free(temp);
    return data;
}

void printPriorityQueue(PriorityQueue *pq) {
    Node *temp = pq->head;

    if(temp == NULL)
        printf("The queue is empty\n");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    PriorityQueue *pq = createPriorityQueue();

    int choice, data, priority;

    while (1) {
        printf("\nPlease choose from the options available below:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueuePriorityQueue(pq, data, priority);
                break;
            case 2:
                data = dequeuePriorityQueue(pq);
                if (data != -1) {
                    printf("The dequeued element is %d\n", data);
                } else {
                    printf("The queue is empty\n");
                }
                break;
            case 3:
                printPriorityQueue(pq);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
