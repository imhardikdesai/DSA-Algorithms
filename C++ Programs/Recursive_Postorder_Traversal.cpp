void postOrder(struct BinaryTreeNode *root){ //recursive
  if(root){
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
  }
}

//Time Complexity: O(n)
//Space Complexity: O(n)
