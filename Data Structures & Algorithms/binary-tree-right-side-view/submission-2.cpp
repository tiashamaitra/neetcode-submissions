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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        stack<TreeNode*> st;

        q.push(root);
        vector<int> v;
        v.push_back(root->val);

        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                    st.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                    st.push(node->right);
                }
            }

            if(!st.empty())
            {
                TreeNode *r = st.top();
                v.push_back(r->val);

                while(!st.empty())
                    st.pop();
            }
        }

        return v;
    }
};
