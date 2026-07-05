#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
//Discription:This file mainly consist of operations of a singly-linked list over statically allocated linked list.

int main(){
    int n;
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* new;
    
  //started with static implementation from here --->
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node)); 
    third=(struct node*)malloc(sizeof(struct node));
   
  
    head->data=25;
    second->data=22;
    third->data=28;
    
    
    head->next=second;
    second->next=third;
    third->next=NULL;

    // printf("%d\t",head->data);
    // printf("%d",second->data);
    // printf("%d",head->next->data);



//     if (head->next->data != NULL) {
//     printf("Node points to address: %p\n", (void*)head->next);
//     printf("Value of the next node: %d\n", head->next->data);
// } else {
//     printf("Node points to NULL (This is the end of the list).\n");
// }
 


    printf("1.Insert a NODE(at Beginning)\n2.Insert a NODE(at the END)\n3.Insert a Node(anywhere)\n4.Delete a Node(from beginning)\n5.Delete a NODE(from the end)\n6.EXIT\n");
    scanf("%d",&n);

    // if (n==0) 
    // {
    //     struct node *temp = head;

    // if (head == NULL) {
    //     printf("List is empty\n");
        
    // }else{

    // printf("Linked List: ");
    // while (temp != NULL) {
    //     printf("%d -> ", temp->data);
    //     temp = temp->next;
    // }
    // printf("NULL\n");
    // }
    // }
    

    if (n==1) //Insert a NODE(at Beginning)
    {
        new=(struct node*)malloc(sizeof(struct node));
        if (new==NULL)
        {
            printf("Memory underflow.");
        } else{
            // new->next=head->next;
            printf("Enter the data to be inserted:");
            scanf("%d",&new->data);
            // head->next=new;
            new->next=head;
           head=new;
        }
        printf("value of the new node is:%d",new->data);
    }

    if (n==2) //Insert a NODE(at the END)
    {   
        struct node* temp=head;//initialy set it to head rather than giving it its own malloc memory.
        // temp=(struct node*)malloc(sizeof(struct node)); unnecessary.
        new=(struct node*)malloc(sizeof(struct node));
       
        if (new==NULL)
        {
            printf("Insufficient memory!");
            
        }else{
            printf("Enter the data to be inserted:");
                scanf("%d",&new->data);


            // temp=head;   //changed here from temp->next=head,second change--on a better note we could do it while making structure.
            while(temp->next!=NULL){
             temp=temp->next;
            }
             temp->next=new;
            

       }
       
       printf("Inserted %d at the END!",new->data);
    }

    if (n == 3) //Insert a Node(anywhere)
{
    int key;
    struct node *temp;

    new = (struct node *)malloc(sizeof(struct node));

    if (new == NULL)
    {
        printf("Memory is insufficient!");
    }
    else
    {
        printf("Enter the value after which you want to insert: ");
        scanf("%d", &key);

        printf("Enter the data to be inserted: ");
        scanf("%d", &new->data);

        temp = head;

        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Key not found.\n");
            free(new);
        }
        else
        {
            new->next = temp->next;
            temp->next = new;

            printf("Inserted %d after %d.\n", new->data, key);
        }
    }
}

   if (n==4) //Delete a Node(from beginning)
   {    
     struct node*temp;
       
    if (head==NULL)
    {
        printf("The list is empty : No Deletion");
    }
    else{
            temp=head;
            head=temp->next;
            printf("Deleted Data from beginning: %d",temp->data);
            free(temp);
    }
    
   }
   if(n==5) //Delete a NODE(from the end)
   {
    struct node*temp;
    temp=head;
    if (temp->next==NULL)
    {
        printf("The linked list is empty:NOTHING TO DELETE!");
    }else{
        while (temp->next!=NULL)
        {
            temp=temp->next;

        }
        printf("Deleted the END element:%d",temp->data); 


    }
    
   }
   if (n==6) //EXIT....
   {
    printf("Exiting...");
    return 0;
   }
    return 0;

}
