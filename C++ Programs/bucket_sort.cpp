#include<bits/stdc++.h>
using namespace std;
class DNode
{
        public :
                double info;
                DNode *next;
                DNode *prev;
                DNode()
                {
                        next=0;
                        prev=0;
                }
                DNode(double x , DNode *n=0,DNode *p=0)
                {
                        info = x;
                        next = n;
                        prev=p;
                }
};
class Dlist
{
        private :
        DNode *head,*tail;
        public :
                Dlist()
                {
                        head=tail=0;
                }
                int isempty();
                void addtotail(double x);
                void display();
                void insertionsort();

};
void Dlist::addtotail(double x){
        DNode *p=new DNode(x);
        if(isempty())
        {
                head=tail=p;
        }
        else
        {
                tail->next=p;
                p->prev=tail;
                tail=p;
        }
}
 int Dlist::isempty()
 {
        if(head==0 )
        {
                return 1;
         }
         else
         return 0;
 }
 void Dlist::display(){
    DNode *temp=head;
        while(temp!=0)
        {
          cout<<temp->info<<"  ";
          temp=temp->next;
    }
 }
void Dlist::insertionsort()
{
        DNode *temp1=head->next;
        DNode *temp2;
        DNode *temp3;
        while(temp1!=0)
        {
                double x=temp1->info;
                temp2=temp1->prev;
                temp3=temp2->next;
                while(temp2!=0)
                {
                        if(temp2->info>x)
                        {
                                temp2->next->info=temp2->info;
                                temp3=temp2;
                                temp2=temp2->prev;
                        }
                        else
                          break;
                }
                temp3->info=x;
            temp1=temp1->next;
        }
}
void BUCKET_SORT(double A[],int n)
{
        Dlist B[n];
        for(int i=0;i<n;i++){
                int m=floor(n*A[i]);
                B[m].addtotail(A[i]);

        }
        for(int i=0;i<n;i++){
                if(!B[i].isempty())
                {
                   B[i].insertionsort();
            }
        }
        cout<<"Sorted array is : ";
        for(int i=0;i<n;i++){
                B[i].display();
        }
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    double A[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    BUCKET_SORT(A,n);
    return 0;
}
