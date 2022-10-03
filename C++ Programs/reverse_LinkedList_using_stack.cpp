#include<iostream>
#include<stack>
using namespace std;


// algo to reversing the linked list using stack


struct node
{
	int data;
	node* link;
};

// inserting a node at the begning of a linked list (time complexity-->O(1))
node* insert(int a, node* head)
{

	node* temp = new node();

	temp->data = a;
	temp->link = head;

	head = temp;

	return head;
}
// print the entire linked list
void print(node* head)
{
	node* temp = head;

	for (; temp != NULL;)
	{
		cout << temp->data << " ";
		temp = temp->link;

	} cout << endl;

}


// reversing the linked list using stack
node* reverse_linked_list_using_stack(node* head)
{
	// making stack
	stack<node*> stk;
	node* temp = head;
	// taking link of every node in linked list
	for (; temp != NULL;)
	{
		stk.push(temp);
		temp = temp->link;
	}
	temp = stk.top();
	head = temp;
	stk.pop();
	// returning reversed link to every node in linked list
	for (; stk.size() != 0;)
	{
		temp->link = stk.top();
		stk.pop();
		temp = temp->link;
	}
	temp->link = NULL;
	return head;
}
int main() {
// random inputs..

	node* head = NULL;
	int n; cin >> n;

	for (int i = 0; i < n; ++i) {int a; cin >> a; head = insert(a, head);}

	// print before reversing
	print(head);
	// reversing
	head = reverse_linked_list_using_stack(head);
	// print after reversing
	print(head);

	return 0;
}


