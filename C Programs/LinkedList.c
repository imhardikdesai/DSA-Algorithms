#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node * next;

};

void llTraversal(struct node * head){
    struct node * p = head;
    printf("%d\n", p->data);
    p = p->next;
    while(p != head){
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct node * circularHeadInsertion(struct node * head, int ele){
    struct node * ptr = (struct node *)malloc(sizeof(struct node ));
    ptr->data = ele;
    struct node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return(head);
}

int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node ));
    struct node * second = (struct node *)malloc(sizeof(struct node ));
    struct node * third = (struct node *)malloc(sizeof(struct node ));
    int ele;

    head->data = 10;
    head->next = second;
    
    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = head;

    printf("Enter the element : \n");
    scanf("%d", &ele);

    printf("linked list before insertion is : \n");
    llTraversal(head);

    printf("linked list after insertion : \n");
    head = circularHeadInsertion(head, ele);
    llTraversal(head);

    return 0;
}