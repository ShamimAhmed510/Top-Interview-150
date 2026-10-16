/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 
class Solution {
public:
    int ans = INT_MAX;
    int pre = -1;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        if (pre != -1) {
            ans = min(ans, root->val - pre);
        }
        pre = root->val;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {

        inorder(root);
        return ans;
    }
}; 
