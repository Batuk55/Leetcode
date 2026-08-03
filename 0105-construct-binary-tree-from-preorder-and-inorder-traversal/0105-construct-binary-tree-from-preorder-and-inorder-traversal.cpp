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
    TreeNode* construct(vector<int>& preorder, int pre_start, int pre_end,  vector<int>& inorder, int in_start, int in_end, unordered_map<int, int> &mpp_ino){
        if(pre_start > pre_end || in_start > in_end) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        int inRoot = mpp_ino[root->val];
        int numsLeft = inRoot - in_start;

        root->left = construct(preorder, pre_start + 1, pre_start + numsLeft, inorder, in_start,  inRoot-1, mpp_ino);
        root->right= construct(preorder, pre_start + numsLeft + 1, pre_end, inorder, inRoot+1,  in_end, mpp_ino);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mpp_ino;

        for(int i = 0; i< n; i++){
            mpp_ino[inorder[i]] = i;
        }
        TreeNode* root = construct(preorder, 0, n-1, inorder, 0, n-1, mpp_ino);

        return root;
    
        
    }
};