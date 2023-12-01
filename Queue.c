#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = queue->rear = 0;
        }
        else
        {
            queue->rear++;
        }
        queue->items[queue->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue(struct Queue *queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else
    {
        item = queue->items[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front++;
        }
        printf("%d dequeued from the queue.\n", item);
        return item;
    }
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->items[queue->front];
}

void display(struct Queue *queue)
{
    int i;
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front: %d, Rear: %d\n", front(queue), queue->items[queue->rear]);
        printf("Queue items: ");
        for (i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue *queue = createQueue();

    int choice, item;

    while (1)
    {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
