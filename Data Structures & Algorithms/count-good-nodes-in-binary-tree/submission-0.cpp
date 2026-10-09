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
    int check(TreeNode *root, int prev)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        if(root->val>=prev)
        {
            
            return 1+check(root->left,root->val)+check(root->right,
            root->val);
        }
        else
        {
            int maxi=prev;
            return check(root->left,maxi)+check(root->right
            ,maxi);
        }
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        return check(root,INT_MIN);
    }
};
