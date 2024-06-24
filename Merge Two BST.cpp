class Solution
{
    public:
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        Node* a = root1;
        Node* b = root2;
        stack<Node*> sa, sb;

        while (a || b || !sa.empty() || !sb.empty()) {
            while (a) {
                sa.push(a);
                a = a->left;
            }
            while (b) {
                sb.push(b);
                b = b->left;
            }
            if (sb.empty() || (!sa.empty() && sa.top()->data <= sb.top()->data)) {
                auto atop = sa.top();
                ans.push_back(atop->data);
                sa.pop();
                a = atop->right;
            } else {
                auto btop = sb.top();
                ans.push_back(btop->data);
                sb.pop();
                b = btop->right;
            }
        }
        return ans;
    }
};
