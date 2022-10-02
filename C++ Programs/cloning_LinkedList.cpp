#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* next; 
    Node* arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }
};

class Solution
{
    private:
    void insertAtEnd(Node* &head, Node* &end, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            end = newNode;
            return;
        }
        else{
            end -> next = newNode;
            end = newNode;
        }
        
        // return head;
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneEnd = NULL;
        
        Node* temp = head;
        
        //step1 cloning a given list with next ptr
        while(temp != NULL){
            insertAtEnd(cloneHead, cloneEnd, temp -> data);
            temp = temp -> next;
        }
        
        //step2 adding clone list nodes between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        //step3 add random pointers to the cloned list nodes
        temp = head;
        while(temp != NULL){
            if(temp -> next!= NULL){
                if(temp -> arb != NULL){
                    temp -> next -> arb = temp -> arb -> next;
                }
                else{
                    temp -> next -> arb = temp -> arb;
                }
            }
            temp = temp -> next -> next;
        }
        
        //step4 revert the step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        //step5 return the cloneHead
        return cloneHead;
        
    }

};