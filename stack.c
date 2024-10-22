 #include<stdio.h>
#include<stdlib.h>
struct node
{
         int data;
         struct node *next;
}
*top=NULL;
int isEmpty()
{
         if(top==NULL)
                 return 1;
         else
                 return 0;
}
void push(int data)
{
         struct node *newnode=(struct node*)malloc(sizeof(struct node));
         if(newnode==NULL)
         {
                 printf("Stack Overflow");
                 exit(1);
         }
         newnode->data=data;
         newnode->next=NULL;
         newnode->next=top;
         top=newnode;
         print();

}
int pop()
{
         struct node *temp;
         int val;
         if(isEmpty())
         {
printf("Stack Underflow");
                exit(1);
         }
         temp=top;
         val=temp->data;
         top=temp->next;
         free(temp);
         temp=NULL;
         return val;

}

void print()
{
         struct node *temp;
         temp=top;
         if(isEmpty())
         {
                printf("Stack Underflow");
                exit(1);
         }
         printf("Stack elements are:");
         while(temp!=NULL)
         {
         printf("%d\t",temp->data);
                temp=temp->next;
         }
}
void search()
{
         struct node *temp;
         temp=top;
         int s,f=0;
         printf("\n Enter an element to be search:");
         scanf("%d",&s);
         while(temp!=NULL)
         {
                if(temp->data==s)
                {
                        f=1;
                        printf("\n element %d found ",s);
                }
                temp=temp->next;
        }
        if(f==0)
                printf("\n element %d is not found",s);
}
int main()
{
         int ch,data;
         while(1)
         {
printf("\n");
                printf("1.Push \n 2.Pop \n 3.Display \n 4.Search \n 5.Exit");
                printf("\n Enter your choice:");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("\nEnter the element to be pushed:");
                                scanf("%d",&data);
                                push(data);
                                break;
                        case 2: data=pop();
                                printf("\n Deleted element is %d \n",data);
                                print();
                                break;
                        case 3: print();
                                break;
                        case 4: search();
                                break;
                        case 5: printf("\n Exit");
                                exit(0);
                        default:printf("\n Invalid Choice");
                }


          }
         return 0;
}



