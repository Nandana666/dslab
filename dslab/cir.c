#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1,*queue,size,i;
int isFull()
{

    return (rear + 1) % size == front;
}


int isEmpty()
{

    return front == -1;
}


void enqueue(int data)
{

    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if(front==-1){
    	front=0;
    	}
    rear = (rear + 1) % size;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}


int dequeue()
{

    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else {

        front = (front + 1) % size;
    }

return data;
}

void display()
{

    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % size;
    }

    printf("%d\n", queue[rear]);
}
void search()
{
    int s,f=0;
   // int i=front;
    printf("\n enter element to be search:");
    scanf("%d",&s);
    for(i=front;i!=rear;i=(i+1)%size){
        if(s==queue[i]){
            f=1;
		break;
	}	
// i = (i + 1) % size;
    }
    if(queue[i]==s){
		f=1;
    }
    if(!f){
        printf("\n element not found");
    }
    else{
        printf("\n element found");
    }
}


int main()
{

    int data,ch;
	 printf("\n Enter maxsize:");
        scanf("%d",&size);
	queue=(int*)malloc(size* sizeof(int));
	if(queue==NULL){
		printf("Memory  allocate failed");
		exit(1);
	}

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
    	}while(ch!=5);
    return 0;
}


