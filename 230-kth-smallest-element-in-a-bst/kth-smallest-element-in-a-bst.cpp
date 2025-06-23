class Solution {
    unordered_map<TreeNode*, int> subtreeSize;

    // Step 1: Preprocess to compute subtree sizes
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        int left = countNodes(node->left);
        int right = countNodes(node->right);
        subtreeSize[node] = 1 + left + right;
        return subtreeSize[node];
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        countNodes(root); // Fill the map with subtree sizes

        // Step 2: Use augmented BST logic
        while (root) {
            int leftCount = root->left ? subtreeSize[root->left] : 0;

            if (k == leftCount + 1) {
                return root->val;
            } else if (k <= leftCount) {
                root = root->left;
            } else {
                k = k - leftCount - 1;
                root = root->right;
            }
        }

        return -1; // Invalid k
    }
};
