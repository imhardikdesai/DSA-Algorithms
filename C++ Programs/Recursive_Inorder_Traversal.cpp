void inOrder(struct BinaryTreeNode *root){ //recursive
  if(root){
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
  }
}

//Time Complexity: O(n)
//Space Complexity: O(n)
