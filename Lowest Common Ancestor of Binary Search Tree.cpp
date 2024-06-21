class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }
        TreeNode* leftcall = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightcall = lowestCommonAncestor(root->right, p, q);
        if (leftcall != NULL && rightcall == NULL) {
            return leftcall;
        }
        if (rightcall != NULL && leftcall == NULL) {
            return rightcall;
        }
        if (rightcall == NULL && leftcall == NULL) {
            return NULL;
        } else {
            return root;
        }
    }
};
