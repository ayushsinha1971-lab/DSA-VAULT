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
    int ans=0;
    vector <int> dfs(TreeNode * root){
        if(root==NULL){
            return {0,0};
        }
        vector <int>  l=dfs(root->left);
        vector <int>  r=dfs(root->right);
        int count = l[0]+r[0]+1;
        int sum =l[1]+r[1]+root->val;
        int avg=sum/count;
        if(avg == root->val){
            ans++;
        }
        return {count,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        vector <int > okk =dfs(root);
        return ans;
    }
};