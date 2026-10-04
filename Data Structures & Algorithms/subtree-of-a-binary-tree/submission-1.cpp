class Solution {
public:

    bool same(TreeNode* r, TreeNode* subRoot)
    {
        if(r==NULL && subRoot==NULL)
        {
            return true;
        }

        if(r==NULL || subRoot==NULL)
        {
            return false;
        }

        if(r->val != subRoot->val)
        {
            return false;
        }

        return same(r->left, subRoot->left) &&
               same(r->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL)
        {
            return false;
        }

        if(same(root, subRoot))
        {
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};