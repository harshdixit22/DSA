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
    void dfs(TreeNode* node,vector<string> &res,string curr){
        if(node==NULL){
            return;
        }


        if(node->left ==NULL && node->right==NULL){
            curr+=to_string(node->val);
            res.push_back(curr);
        }
        else{
            curr+=to_string(node->val) + "->";
        }
        dfs(node->left , res , curr);

        dfs(node->right , res,  curr);

        
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string curr = "";

        dfs(root, res, curr);
        return res;
    }
};