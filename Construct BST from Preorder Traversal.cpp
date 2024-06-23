class Solution {
public:
    TreeNode* solve(int& i, vector<int>& preorder, int min, int max) {
        if (i >= preorder.size()) {
            return nullptr;
        }
        TreeNode* root = NULL;
        if (preorder[i] > min && preorder[i] < max) {
            root = new TreeNode(preorder[i]);
            i++;
            root->left = solve(i, preorder, min, root->val);
            root->right = solve(i, preorder, root->val, max);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(i, preorder, INT_MIN, INT_MAX);
    }
};
