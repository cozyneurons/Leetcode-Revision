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
    TreeNode* helper(TreeNode* node)
    {
        if (!node->left) return node->right;
        else if (!node->right) return node->left;
        TreeNode* LR = findLastRight(node->left);
        TreeNode* RightChild = node->right;
        LR->right = RightChild;
        return node->left; 

    }
    TreeNode* findLastRight(TreeNode* node)
    {
        while(node->right) node = node->right;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(!root) return NULL;
        if (root->val==key) return helper(root);
        TreeNode* temp = root;
        while(root)
        {
            if (root->val>key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }

            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root-> right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return temp;
    }
    
};
