#include <stdio.h>
#define MAX 10 // maximum size of the queue

// global variables
int queue[MAX]; // array to store the queue elements
int front = -1; // index of the front element
int rear = -1; // index of the rear element

// function prototypes
void enqueue(int x); // to insert an element at the rear of the queue
int dequeue(); // to remove and return the front element of the queue
void display(); // to display the queue elements

int main()
{
    int choice, x;
    printf("Simple Queue Implementation in C\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // enqueue operation
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2: // dequeue operation
                x = dequeue();
                if(x != -1)
                    printf("The dequeued element is %d\n", x);
                break;
            case 3: // display operation
                display();
                break;
            case 4: // exit operation
                printf("Thank you for using my program.\n");
                return 0;
            default: // invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// function to insert an element at the rear of the queue
void enqueue(int x)
{
    if(rear == MAX - 1) // queue is full
    {
        printf("Queue overflow. Cannot enqueue.\n");
        return;
    }
    else if(front == -1 && rear == -1) // queue is empty
    {
        front = rear = 0; // set both front and rear to 0
    }
    else // queue is not empty
    {
        rear++; // increment rear by 1
    }
    queue[rear] = x; // insert the element at the rear index
    printf("%d is enqueued.\n", x);
}

// function to remove and return the front element of the queue
int dequeue()
{
    int x;
    if(front == -1 && rear == -1) // queue is empty
    {
        printf("Queue underflow. Cannot dequeue.\n");
        return -1;
    }
    else if(front == rear) // queue has only one element
    {
        x = queue[front]; // store the front element in x
        front = rear = -1; // set both front and rear to -1
        return x; // return the dequeued element
    }
    else // queue has more than one element
    {
        x = queue[front]; // store the front element in x
        front++; // increment front by 1
        return x; // return the dequeued element
    }
}

// function to display the queue elements
void display()
{
    int i;
    if(front == -1 && rear == -1) // queue is empty
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    else // queue is not empty
    {
        printf("The queue elements are:\n");
        for(i = front; i <= rear; i++) // loop from front to rear index
        {
            printf("%d ", queue[i]); // print the element at index i
        }
        printf("\n");
    }
}
