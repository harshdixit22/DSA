
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
