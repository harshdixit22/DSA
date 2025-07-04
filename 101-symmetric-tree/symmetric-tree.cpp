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

    bool solve(TreeNode* p , TreeNode* q){

        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL || p->val != q->val) return false;

        return solve(p->left , q->right) && solve(p->right , q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {


        return solve(root->left , root->right);    
    }
};