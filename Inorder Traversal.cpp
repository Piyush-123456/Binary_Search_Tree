class Solution {
public:
    void inorder_traversal(TreeNode* root, vector<int>& in) {
        if (root == NULL) {
            return;
        }
        inorder_traversal(root->left, in);
        in.push_back(root->val);
        inorder_traversal(root->right, in);
    }
    TreeNode* buildtree(int start, int end, vector<int>& in) {
        if (start>end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = buildtree(start, mid - 1, in);
        root->right = buildtree(mid + 1, end, in);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder_traversal(root, in);
        return buildtree(0, in.size()-1, in);
        
    }
};
