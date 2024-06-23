class Solution {
public:
    void rangesum(TreeNode* root, int low, int high, int& sum) {
        if (root == NULL) {
            return;
        }
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        rangesum(root->left, low, high, sum);
        rangesum(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) { 
        int sum = 0;
        rangesum(root, low, high, sum);
        return sum;
    }
};
