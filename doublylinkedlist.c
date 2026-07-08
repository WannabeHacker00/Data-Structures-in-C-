#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *insertbeginning(struct node *head,int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=head;
    newnode->prev=NULL;

    if (head !=NULL)
    {
        head->prev=newnode;
        
        head=newnode;
        return head;
    }else{
        newnode->next=head;
        head=newnode;
        return head;
    }
    

};

struct node *insertend(struct node *head,int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=head;
    newnode->data=value;
    newnode->next=NULL;

    if (head==NULL)
    {
        newnode->prev=head;
        return newnode;
    }
    

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

    printf("Value entered:%d\n",value);

    return head;
};


struct node *insertatposition(struct node *head,int key,int value){
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   struct node *temp=head;
   newnode->data=value;
    if (head==NULL)
    {
        newnode->prev=head;
        return newnode;
    }

    while ( temp!=NULL && temp->data!=key )
    {
        temp=temp->next;
    }
        if (temp==NULL)
        {
        printf("Described key is not available in the list.");
        }else{
             newnode->next=temp->next;
             temp->next->prev=newnode;
                newnode->prev=temp;
                temp->next=newnode;
    }
    printf("Value entered after %d is:%d",key,newnode->data);
    return head;
};

struct node *deletefrombeginning(struct node *head){
    struct node *temp= head;
    
    if (head==NULL)
    {
        printf("Enpty lists:Nothing to Delete!");
        return NULL;
    }
    else{
        
        head=head->next;
        if (head!=NULL)
        {
            head->prev=NULL;    
        }
         printf("Deleted element is: %d\n", temp->data); 

        free(temp);
        return head;
    }   
};


struct node *deletefromend(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("Linked List is Empty!");
    return head;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    if (temp->prev==NULL)
    {
        printf("The list is empty now!");
        return head;
    }
    else{
        temp->prev->next=NULL;
    }
    
    printf("Deleting from the end:%d",temp->data);

    free(temp);
    
    return head;
};

struct node *deletebyvalue(struct node *head,int value){
    struct node *temp=head;

    if (head==NULL)
    {
        printf("The linked list is empty!");
        return head;
    }
    else{
        while (temp!=NULL && temp->data!=value)
        {
            temp=temp->next;
        }
        if (temp==NULL)
        {
            printf("The given data doesnt exist!");
            return head;
        }else{
                if(temp->prev==NULL){
                     head=temp->next;
                         if(head!=NULL)
                             head->prev=NULL;
                 }
                else
                    {
                    temp->prev->next=temp->next;
                        if(temp->next!=NULL)
                             temp->next->prev=temp->prev;
                }
        }
        
        
        printf("The removed number is:%d\n",temp->data);

        free(temp);
        return head;
        
        
    }
    
};


struct node *traverseforward(struct node *head){
    struct node *temp=head;
    if(head==NULL){
        printf("Linked list is empty!");
        return head;
    }
    else{
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        return head;
    }

};
  

struct node *traversebackwards(struct node *head){
  struct node *temp = head;

    if(head == NULL)
    {
        printf("Linked List is empty!");
        return head;
    }

    // Move temp to the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("DLL (Backward): ");

    // Traverse using prev pointer
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
};
    
    
void display(struct node* head) {
    struct node* temp = head;

    printf("DLL (Forward): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
};


int main(){
    struct node *head=NULL;
    int choice, key,value;
   

while(1){
     printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Traverse Forward\n");
        printf("8. Traverse Backward\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        printf("Enter the value:");
            scanf("%d",&value);
        head=insertbeginning(head, value);
        break;
    case 2:
        printf("Enter the value:");
            scanf("%d",&value);
        head=insertend(head, value);
        break;
    case 3:
        printf("Enter the position of insertion:");
             scanf("%d",&key);
        printf("Enter the value:");
            scanf("%d",&value);
        head=insertatposition(head,key, value);
        break;


    case 4:
        printf("Deleting from the beginning!");
       head= deletefrombeginning(head);
         break;
    
     case 5:
        head= deletefromend(head);
         break;   


     case 6:
       printf("Enter the value to be removed!");
       scanf("%d",&value);
       head= deletebyvalue(head,value);
         break;   
     
         

     case 7:
        printf("\n\t---Forward Traversed---\n");
        head=traverseforward(head);
        break;

    case 8:
        printf("\n\t---Backward Traversed---\n");
        traversebackwards(head);
        break;
    case 9:
         display(head);
         break;
    case 10:
          exit(0);
    

      default:
          printf("Invalid choice!\n");
        }

    }
 }


