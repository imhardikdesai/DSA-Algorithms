void preOrderNonRecursive(struct BinaryTreeNode *root){
  struct Stack *S =createStack();
  
  while(1){
    while(root){
      cout<<root->data;
      push(S,root);
      root=root->left;
    }
    if(isEmpty(S)) break;
    root = pop(S);
    root=root->right;
  }
  deleteStack(S);
}
