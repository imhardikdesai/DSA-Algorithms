#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{

    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top, int stackSize)
{

    int i = 0;
    /*
        here we use the logic is diff than other, 
        we doing insertion and deletion of node at the head node beacause of every operation perform in order of 1
        so we need to calculate how many elements in stack, so top pointer denoting the stack top element 
        or can be null.  

        if top is not null then go for next element 
        is happend upto we dont get top pointer as null, while doing this task we also measure how elemnt 
        in stack.

    */
    while (top != NULL)
    {
        top = top->next;
        i++;
    }

    if (i >= stackSize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *Push(struct Node *top, int stackSize)
{
    if (isFull(top, stackSize))
    {
        printf("Stack is full..\n");
        return top;
    }
    else
    {
        struct Node *nnode = (struct Node *)malloc(sizeof(struct Node));
        int n;
        printf("Enter Number:");
        scanf("%d", &n);
        nnode->data = n;
        nnode->next = top;
        top = nnode;
        printf("Your Element %d is pushed into stack\n", nnode->data);
        return top;
    }
}

struct Node *Pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty u can't pop item..\n");
        return top;
    }
    else
    {
        struct Node *ptr = top;
        top = top->next;
        free(ptr);
        return top;
    }
}

void Display(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        struct Node *ptr = top;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void ValueByIndex(struct Node *top, int size)
{
    if (isEmpty(top))
    {
        printf("Stack is Empty\n\n");
    }
    else
    {
        struct Node *ptr = top;
        int i = 1;
        int position;
        printf("Enter Position: ");
        scanf("%d", &position);
        if (position <= size)
        {
            while (i != position)
            {
                ptr = ptr->next;
                i++;
            }
            printf("Element at position %d is %d..\n", position, ptr->data);
        }else{
            printf("Position greater than Stack size..\n");
        }
    }
}
void StackTop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty, push element.\n\n");
    }
    else
    {
        printf("Top Most Element is %d\n", top->data);
    }
}
void StackBottom(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty, push element.\n\n");
    }
    else
    {
        struct Node *ptr = top;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("Bottom Element is %d\n", ptr->data);
    }
}
int main(int argc, char const *argv[])
{
    /*
        when we implementing a stack using linked list that time is easy to push/pop element at start. so thats why we pop/push node from beginning/head, its doen in O(1). beacause we choose last node then we travles all node that are between.so we push last element in stack.
    */

    int choice, StackSize = 5;
    struct Node *top = NULL;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Value By Index\n5.Top Element\n6.Bottom Element\n7.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            top = Push(top, StackSize);
            break;
        case 2:
            top = Pop(top);
            break;
        case 3:
            Display(top);
            break;
        case 4:
            ValueByIndex(top, StackSize);
            break;
        case 5:
            StackTop(top);
            break;
        case 6:
            StackBottom(top);
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Enter Correct choice..\n");
            break;
        }
    }

    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);
    // top = Push(top, StackSize);
    // Display(top);

    return 0;
}