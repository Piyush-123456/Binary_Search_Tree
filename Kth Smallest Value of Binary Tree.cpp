class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if (root == NULL) {
            return -1;
        }
        int leftcall = kthSmallest(root->left, k);
        k--;
        if (leftcall != -1) {
            return leftcall;
        }
        if(k==0){
            return root->val;
        }
        int rightcall = kthSmallest(root->right, k);
        return rightcall;
    }
};
