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
    void solve(TreeNode* root , vector<int> &vec, unordered_set<TreeNode*> &st,int level){

        if(root == NULL){
            return;
        }
        if(level == st.size()){
            vec.push_back(root->val);
            st.insert(root);
        }

        solve(root->right, vec , st,  level +1);

        solve(root->left, vec , st,  level +1);

    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        unordered_set<TreeNode*> st;

        solve(root,vec,st,0);

        return vec;
        
        
    }
};