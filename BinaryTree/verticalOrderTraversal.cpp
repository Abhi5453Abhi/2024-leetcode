#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int> *,int> > q;
    q.push(make_pair(root,0));
    map<int,vector<int> > ma;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            pair<TreeNode<int> *, int> p = q.front();
            ma[p.second].push_back(p.first->data);
            q.pop();
            if(p.first->left){
                q.push(make_pair(p.first->left,p.second-1));
            }
            if(p.first->right){
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
    }
    vector<int> ans;
    for(auto it:ma){
        for(int i=0;i<it.second.size();i++){
            ans.push_back(it.second[i]);
        }
    }
    return ans;
}