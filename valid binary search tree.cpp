class Solution {
public:
    bool solve(TreeNode* root, int lowerbound, int upperbound){
        if(root==NULL){
            return true;
        }
        bool cond1 = root->val > lowerbound;
        bool cond2 = root->val < upperbound;
        bool leftans = solve(root->left, lowerbound, root->val);
        bool rightans = solve(root->right, root->val, upperbound);
        if(cond1 && cond2 && leftans && rightans){
            return true;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        int lowerbound = INT_MIN;
        int upperbound = INT_MAX;
        return solve(root, lowerbound, upperbound);
    }
};
