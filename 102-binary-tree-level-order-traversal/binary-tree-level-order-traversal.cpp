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
    //harsh

    int height(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int left = 1+ height(root->left);
        int right = 1+ height(root->right);

        return max(left , right);

    }

    void solve(TreeNode* root , int level, vector<int> &vec){

        if(root==0){
            return;
        }

        if(level==0){
            vec.push_back(root->val);
        }

        else if(level > 0 ){

            solve(root->left, level-1,vec);
            solve(root->right, level-1,vec);
        }
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> res;

        for(int i = 0; i<height(root); i++){
            vector<int> vec;
            solve(root , i,vec);
            res.push_back(vec);
        }
        return res;
    }
};