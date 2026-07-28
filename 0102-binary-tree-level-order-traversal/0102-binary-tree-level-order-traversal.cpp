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
void traversal(TreeNode* &root, int level, vector<vector<int>> &ans){ //, vector<vector<int>> &ans, queue &q
    
    if(root == NULL) return;
    if(ans.size() == level){
        ans.push_back({});
    }

    ans[level].push_back(root->val);
    traversal(root->left, level+1, ans);
    traversal(root->right, level+1, ans);
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        traversal(root, 0, ans);
        return ans;        
    }
};