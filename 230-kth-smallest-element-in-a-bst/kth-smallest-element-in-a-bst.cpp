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

--------------------------------------------- use INORDER TRAVERSAl ------------------------------------------

    class Solution {
public:
    int count = 0;
    int result = -1;

    void inorder(TreeNode* root, int k) {
        if (root == NULL) return;

        inorder(root->left, k);          // Visit left subtree

        count++;                         // Process current node
        if (count == k) {
            result = root->val;          // Found kth smallest
            return;
        }

        inorder(root->right, k);         // Visit right subtree
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};



-----------------------------------AUGUMENTATION OF BST --------------------------------

    #include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    int count;          // number of nodes in subtree rooted at this node
    TreeNode* left;
    TreeNode* right;

    // Constructor using initializer list to initialize all members
    TreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
};

class AugmentedBST {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        root->count = 1 + getCount(root->left) + getCount(root->right);
        return root;
    }

    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1; // invalid input

        int leftCount = getCount(root->left);

        if (k == leftCount + 1) return root->val;
        else if (k <= leftCount) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - leftCount - 1);
    }

private:
    int getCount(TreeNode* node) {
        return node ? node->count : 0;
    }
};

int main() {
    AugmentedBST bst;
    TreeNode* root = nullptr;

    vector<int> values = {5, 3, 7, 2, 4, 6, 8};
    for (int val : values) {
        root = bst.insert(root, val);
    }

    for (int k = 1; k <= values.size(); ++k) {
        cout << k << "th smallest: " << bst.kthSmallest(root, k) << "\n";
    }

    return 0;
}

