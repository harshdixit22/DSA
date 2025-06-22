
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

    // Count all paths starting from this node that sum to targetSum
    int solve(TreeNode* root, long long targetSum){
        if(root == NULL){
            return 0;
        }

        int count = 0;
        if(root->val == targetSum){
            count++;
        }

        count += solve(root->left, targetSum - root->val);
        count += solve(root->right, targetSum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }

        int z = solve(root, targetSum); 
        int x = pathSum(root->left, targetSum);
        int y = pathSum(root->right, targetSum);

        return x + y + z;
    }
};


---------------------------------------- INTUTIVE APPROACH -----------------------------------------
    class Solution {
public:
    int count;

    void solve(Node* root, int sum, int curr_sum) {
        if (root == NULL) return;

        curr_sum += root->key;

        if (curr_sum == sum) {
            count++;
        }

        solve(root->left, sum, curr_sum);
        solve(root->right, sum, curr_sum);
    }

    int countPaths(Node* root, int sum) {
        if (root == NULL) return 0;

        // Reset count for each top-level call
        count = 0;
        solve(root, sum, 0); // Start a path from this node

        // Also count paths starting from left and right subtrees
        return count + countPaths(root->left, sum) + countPaths(root->right, sum);
    }
};

