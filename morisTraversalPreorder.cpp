class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        vector<int> ans;
    while(root){
        if(root->left){
            Node* prev = root->left;
            while(prev->right && prev->right != root){
                prev = prev->right;
            }
            if(!prev->right){
                prev->right = root;
                ans.push_back(root->data);
                root = root->left;
            }else{
                prev->right = nullptr;
                root = root->right;
            }
        }else{
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
    }
};