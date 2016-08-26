//
//  Queue.h
//  Queue
//
//  Created by Junroot on 2016. 8. 26..
//  Copyright © 2016년 ROOT. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

int QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    return 0;
}

int Enqueue(Queue *pq, int value)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    newnode->next = NULL;
    
    if(pq->front == NULL)
    {
        pq -> front = newnode;
        pq -> rear = newnode;
    }
    else
    {
        pq -> rear -> next = newnode;
        pq -> rear = newnode;
    }
    return 0;
}

int Dequeue(Queue *pq)
{
    Node *delnode;
    int value;
    
    if (pq->front == NULL)   exit(-1);
    delnode = pq->front;
    value = pq->front->value;
    pq->front = pq->front->next;
    
    free(delnode);
    return value;
}

int Freequeue(Queue *pq)
{
    Node *pointnode = pq->front;
    Node *nextnode;
    while(pointnode != NULL)
    {
        nextnode = pointnode->next;
        free(pointnode);
        pointnode = nextnode;
    }
    return 0;
}

#endif /* Queue_h */
