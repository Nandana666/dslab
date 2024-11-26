#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,*queue,item,size,i;
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty");
    }
    else
    {
        printf("Queue elements are:");
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[i]);
    }
}
int enqueue()
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        printf("\n Queue is empty");
        printf("\n Enter element to be inserted:");
        scanf("%d",&item);
        queue[front]=item;
    }
    else if(((rear+1)%size)==front)
    {
        printf("\n Queue is full");
    }
    else
    {
        printf("\n Enter element to be inserted:");
        scanf("%d",&item);
        rear=(rear+1)%size;
        queue[rear]=item;
    }
    display();
}
int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty...Deletion not possible");
    }
    else if(front==rear)
    {
        printf("\n Deleted element is %d",queue[front]);
        //free(queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("\n Deleted element is %d",queue[front]);
        //free(queue[front]);
        front=(front+1)%size;
    }
}
void search()
{
    int f=0;
    printf("\n Enter element to be serach:");
    scanf("%d",&item);
    for(i=front;i!=rear;i=(i+1)%size)
    {
        if(queue[i]==item)
        {
            f=1;
            break;
        }
        if(queue[i]==item)
        {
            f=1;
        }    
    }
    if(f)
    {
        printf("\n Element not found");
    }
    else
    {
        printf("\n Element found");
    }
}
int main()
{
    int ch;
    printf("\n Enter size of the queue:");
    scanf("%d",&size);
    queue=(int*)malloc(size * sizeof(int));
    if(queue==NULL)
        {
                printf("\nMemory Allocation Failed,Exiting Program\n");
                exit(1);
        }
    do
    {
        printf("\n MENU \n 1.Insert \n 2.Delete \n 3.Search \n 4.Display \n 5.Exit");
        printf("\n Enter youe choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    enqueue();
                    break;
            case 2:
                    dequeue();
                    break;
            case 3:
                    search();
                    break;
            case 4: 
                    display();
                    break;
            case 5:
                    printf("\n EXIT");
                    exit(0);
                    break;
            default:
                    printf("\n Invalid choice");       
        }
    }while(ch!=5);
    return 0;
}
