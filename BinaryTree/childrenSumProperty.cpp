/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

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