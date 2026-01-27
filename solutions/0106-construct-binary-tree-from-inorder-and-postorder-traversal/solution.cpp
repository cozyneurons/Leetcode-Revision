class Solution {
public:
    unordered_map<int, int> inorder_map;
    int postorderIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;

        postorderIndex = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& postorder, int low, int high) {
        if (low > high) return nullptr;

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorder_map[rootVal];

        root->right = build(postorder, mid + 1, high);
        root->left  = build(postorder, low, mid - 1);

        return root;
    }
};
