#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* create(node* root)
{
    int d;
    cout<<"enter root";
    cin>>d;
    if(d!=-1)
    {
    root=new node(d);
    cout<<"enter left root"; 
    root->left=create(root->left);
     cout<<"enter right root"; 
    root->right=create(root->right);
    return root; 

    }
    else
    return NULL;
}
void leftpart(vector<int> &ans,node* root)
{
 if(root==NULL ||(root->left==NULL && root->right==NULL))
 return;
 ans.push_back(root->data);
 if(root->left)
 leftpart(ans,root->left);
 else
 leftpart(ans,root->right);

}
void nodepart(vector<int> &ans,node* root)
{
 if(root==NULL)
 return;
 if(root->left==NULL && root->right==NULL)
 ans.push_back(root->data);
 nodepart(ans,root->left);
 nodepart(ans,root->right);
 
}
void rightpart(vector<int> &ans,node* root)
{
 if(root==NULL ||(root->left==NULL && root->right==NULL))
 return;
 if(root->right)
 rightpart(ans,root->right);
 else
 ans.push_back(root->data); 

}
int main()
{
    node* root;
    root=create(root);
    vector<int> ans;
    ans.push_back(root->data);
    leftpart(ans,root->left);
    nodepart(ans,root);
    rightpart(ans,root->right);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}