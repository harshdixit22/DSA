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

    int solve(TreeNode* root , int mini , int maxi , int max_diff){
        if(root==NULL){
            max_diff  =  max(max_diff , abs(mini - maxi));
            return max_diff;
        }

        mini  = min(mini , (root->val));
        maxi  = max(maxi , (root->val));

        


        int l = solve(root->left , mini , maxi , max_diff);
        int r = solve(root->right , mini , maxi , max_diff);

        return max(l,r);

    }
    int maxAncestorDiff(TreeNode* root) {

        int mini  = INT_MAX;
        int maxi = INT_MIN;
        int max_diff = -1;

        return solve(root , mini , maxi , max_diff);
        
        
    }
};