/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents (TreeNode* root, unordered_map <TreeNode*, TreeNode*> &parent_map)
    {
        if (!root) return;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
                parent_map[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parent_map[node->right] = node;
            }
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map <TreeNode*, TreeNode*> parent_map;
        markParents (root,parent_map);
        unordered_map <TreeNode*,bool> visited;
        queue <TreeNode*> q;
        int distance = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int n = q.size();
            if (distance == k) break;
            
            for (int i = 0; i<n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent_map[node] && !visited[parent_map[node]])
                {
                    q.push(parent_map[node]);
                    visited[parent_map[node]] = true;
                }
                
            }
            distance++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            int value = q.front()->val;
            q.pop();
            ans.push_back(value);
        }
        return ans;  
    }
};
