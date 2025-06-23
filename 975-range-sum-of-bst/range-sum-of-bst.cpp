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
    // We store additional info in maps since we can't modify TreeNode in LeetCode
    unordered_map<TreeNode*, long> subsum;
    unordered_map<TreeNode*, int> minVal, maxVal;

    void build(TreeNode* node) {
        if (!node) return;

        build(node->left);
        build(node->right);

        long leftSum = node->left ? subsum[node->left] : 0;
        long rightSum = node->right ? subsum[node->right] : 0;
        subsum[node] = node->val + leftSum + rightSum;

        int leftMin = node->left ? minVal[node->left] : node->val;
        int rightMin = node->right ? minVal[node->right] : node->val;
        int leftMax = node->left ? maxVal[node->left] : node->val;
        int rightMax = node->right ? maxVal[node->right] : node->val;

        minVal[node] = std::min({node->val, leftMin, rightMin});
        maxVal[node] = std::max({node->val, leftMax, rightMax});
    }

    void solve(TreeNode* node, int low, int high, long& sum) {
        if (!node) return;

        if (minVal[node] >= low && maxVal[node] <= high) {
            sum += subsum[node];
            return;
        }

        if (node->val >= low && node->val <= high)
            sum += node->val;

        solve(node->left, low, high, sum);
        solve(node->right, low, high, sum);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        build(root);
        long sum = 0;
        solve(root, low, high, sum);
        return static_cast<int>(sum);
    }
};
