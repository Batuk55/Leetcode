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
    bool check(TreeNode* root, long long least, long long most){
        if(!root) return true;
        if(root->val >= most || root->val <= least) return false;
        
       return check(root->left, least, root->val) && check(root->right, root->val, most);
    }
    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
        
    }
};