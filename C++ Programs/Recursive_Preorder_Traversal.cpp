void preOrder(struct BinaryTreeNode *root){ //recursive
  if(root){
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
  }
}

//Time Complexity: O(n)
//Space Complexity: O(n)
