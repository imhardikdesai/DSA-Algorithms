#include "iostream"
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */
    
    Node* merge(Node* left , Node* right){

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* temp;

    if(left -> data < right -> data){
        temp = left;
        temp -> bottom = merge(left -> bottom , right);
    }
    else{
        temp = right;
        temp -> bottom = merge(left, right -> bottom);
    }
    
    temp -> next = NULL;
    return temp;

}

Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root -> next == NULL){
       return root;
   }
   
   Node* result = merge(root, flatten(root -> next));
   return result;
}

