/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    map<int,int> ma;
    vector<int> ans;
    queue< pair<TreeNode<int> *, int> > q;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            pair<TreeNode<int> *,int> top = q.front();
            q.pop();
            if(!ma[top.second]){
                ma[top.second] = top.first -> data;
            }
            if(top.first -> left){
                q.push(make_pair(top.first -> left, top.second - 1));
            }
            if(top.first -> right){
                q.push(make_pair(top.first -> right, top.second + 1));
            }
        }
    }
    for(auto it:ma){
        ans.push_back(it.second);
    }
    return ans;
}
