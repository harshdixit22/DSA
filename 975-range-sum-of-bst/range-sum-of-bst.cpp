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


------------------------------------------------------------------------------------------------------------------------------


    #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Augmented TreeNode with subsum, minVal, maxVal
struct TreeNode {
    int val;
    long subsum = 0;
    int minVal, maxVal;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int x) : val(x), subsum(x), minVal(x), maxVal(x) {}
};

// Build function to compute subsum, minVal, maxVal for each node
void build(TreeNode* node) {
    if (!node) return;

    if (node->left) build(node->left);
    if (node->right) build(node->right);

    node->subsum = node->val +
        (node->left ? node->left->subsum : 0) +
        (node->right ? node->right->subsum : 0);

    node->minVal = min({node->val,
                        node->left ? node->left->minVal : node->val,
                        node->right ? node->right->minVal : node->val});

    node->maxVal = max({node->val,
                        node->left ? node->left->maxVal : node->val,
                        node->right ? node->right->maxVal : node->val});
}

// Efficient range sum using augmentation
void solve(TreeNode* node, int low, int high, long& sum) {
    if (!node) return;

    if (node->minVal >= low && node->maxVal <= high) {
        sum += node->subsum;
        return;
    }

    if (node->val >= low && node->val <= high)
        sum += node->val;

    if (node->left) solve(node->left, low, high, sum);
    if (node->right) solve(node->right, low, high, sum);
}

// Main function to calculate range sum
int rangeSumBST(TreeNode* root, int low, int high) {
    build(root);
    long sum = 0;
    solve(root, low, high, sum);
    return (int)sum;
}

// Helper function to insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Main test function
int main() {
    vector<int> values = {10,5,15,3,7,13,18,1,6};
    TreeNode* root = nullptr;

    for (int val : values)
        root = insert(root, val);

    int low = 6, high = 10;
    int result = rangeSumBST(root, low, high);

    cout << "Range sum [" << low << ", " << high << "] = " << result << endl;
    return 0;
}

