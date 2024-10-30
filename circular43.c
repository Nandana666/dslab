// C Program to implement the circular queue in c using arrays
#include <stdio.h>
#include <stdlib.h>
// Define the maximum size of the queue
#define MAX_SIZE 5

    // Declare the queue array and front, rear variables
    int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull()
{
    // If the next position is the front, the queue is full
    return (rear + 1) % MAX_SIZE == front;
}

// Function to check if the queue is empty
int isEmpty()
{
    // If the front hasn't been set, the queue is empty
    return front == -1;
}

// Function to enqueue (insert) an element
void enqueue(int data)
{
    // If the queue is full, print an error message and
    // return
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }
    // If the queue is empty, set the front to the first
ear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}

// Function to dequeue (remove) an element
int dequeue()
{
    // If the queue is empty, print an error message and
    // return -1
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    // Get the data from the front of the queue
    int data = queue[front];
    // If the front and rear pointers are at the same
    // position, reset them
    if (front == rear) {
        front = rear = -1;
    }
    else {
        // Otherwise, move the front pointer to the next
        // position
        front = (front + 1) % MAX_SIZE;
    }
    // Return the dequeued data
return data;
}

// Function to display the queue elements
void display()
{
    // If the queue is empty, print a message and return
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    // Print the elements in the queue
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    // Print the last element
    printf("%d\n", queue[rear]);
}
void search()
{
    int s,f=0;
    int i=front;
    printf("\n enter element to be search:");
    scanf("%d",&s);
    while(i!=rear+1){
        if(s==queue[i])
            f=1;

 i = (i + 1) % MAX_SIZE;
    }
    if(f==0){
        printf("\n element not found");
    }
    else{
        printf("\n element found");
    }
}

// Main function
int main()
{
    // Enqueue some elements
    int data,ch;
    do{
            printf("\n MENU \n 1.insert \n 2.delete \n 3.display \n 4.search \n 5.exit");

            printf("\n enter your choice:");
            scanf("%d",&ch);

            switch(ch){

                case 1: printf("\n enter element to be inserted:");
                        scanf("%d",&data);
                        enqueue(data);
                        display();
                        break;
                case 2: printf("Dequeued element: %d\n", dequeue());
                        display();
                        break;
                case 3: display();
                        break;
                case 4: search();
                        break;
                case 5: printf("\n EXIT");
                        exit(0);
                        break;
                default:printf("\n invalid entry...try again");
            }
            //enqueue(10);
            //enqueue(20);
            //enqueue(30);
            // Display the queue


            // Dequeue an element and print it

            // Display the queue again

    }while(ch!=5);
    // End of main function
    return 0;
}

