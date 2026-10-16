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
    void level(TreeNode* root, int lvl, vector<vector<int>> & ans){
        if(!root) return;

        if(lvl == ans.size()){
            ans.push_back({});
        }
       
        // vector<int> temp;
        ans[lvl].push_back(root->val);
        
        // if(root->left){
            level(root->left, lvl+1, ans);
        // }
        // if(root->right){
            level(root->right, lvl+1, ans);
        // }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        stack<TreeNode*> st;
        // st.push(root);
        // ans.push_back({root->val})

        level(root, 0, ans);

        return ans;
    }
};