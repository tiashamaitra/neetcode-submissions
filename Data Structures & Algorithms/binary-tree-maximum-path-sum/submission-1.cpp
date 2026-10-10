class Solution {
public:
    int maxi = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = solve(root->left);
        int r = solve(root->right);

        // best path passing through this node (can use both children) -> update answer
        maxi = max(maxi, max(root->val + l + r, max(root->val + r, max(root->val + l, root->val))));

        // value returned upward: can use at most ONE child branch
        return max(root->val, root->val + max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};