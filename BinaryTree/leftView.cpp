void solve(Node* root, int level, vector<int> &ans, map<int,int> &ma){
    if(root == NULL)return;
    if(ma[abs(level)] == 0){
        ans.push_back(root->data);
        ma[abs(level)]++;
    }
    solve(root->left,level+1,ans,ma);
    solve(root->right,level+1,ans,ma);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   map<int,int> ma;
   solve(root,0,ans,ma);
   return ans;
}