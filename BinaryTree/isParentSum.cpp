bool isParentSum(Node *root){
    // Write your code here.
    if(root == NULL || (!root->left && !root->right))return true;
    if(!root->left && root->right){
        if(root->data == root->right->data){
            return isParentSum(root->right);
        }else{
            return false;
        }
    }
    if(!root->right && root->left){
        if(root->data == root->left->data){
            return isParentSum(root->left);
        }else{
            return false;
        }
    }
    if(root->data == root->left->data + root->right->data){
        return isParentSum(root->left) && isParentSum(root->right);
    }else return false;
    
}