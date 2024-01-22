// https://www.geeksforgeeks.org/problems/symmetric-tree/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool solve(struct Node* root1, struct Node* root2){
        if(!root1 && !root2)return true;
        if((!root1 && root2) || (root1 && !root2))return false;
        if(root1->data == root2->data){
            return solve(root1->left,root2->right) && solve(root1->right,root2->left);
        }else return false;
    }
    bool isSymmetric(struct Node* root)
    {
        if(root == NULL)return true;
	    else return solve(root->left,root->right);
    }
};