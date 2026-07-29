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
int depthh(TreeNode* root, int curr_depth){
    if(root == NULL) return curr_depth;

    return max(depthh(root->left, curr_depth+1), depthh(root->right, curr_depth+1));
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        
        int Maxdepth = depthh(root, 0);

        return Maxdepth;
    }
};