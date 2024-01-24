/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int N = 10;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digits(N);
        dfs(root, digits);
        return ans;
    }
    void dfs(TreeNode* root, vector<int> digits){
        if(root == NULL)return;

        digits[root->val]++;

        if(root->left == NULL && root->right == NULL){
            if(check(digits)){
                ans++;
            }
            return;
        }
        dfs(root->left, digits);
        dfs(root->right, digits);

        digits[root->val]--;
    }
    bool check(vector<int> &digits){
        int odd = 0;
        for(int i=0;i<10;i++){
            if(digits[i] % 2 != 0){
                odd++;
            }
        }
        if(odd > 1)return false;
        else return true;
    }
};