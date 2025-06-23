
class Solution {
public:
    
    int minDiff = INT_MAX;
    
    void inOrder(TreeNode* root, TreeNode* &prev) {
        
        if(root == NULL)
            return;
        
        inOrder(root->left, prev);
        
        if(prev != NULL) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        
        prev = root;
        
        inOrder(root->right, prev);
        
    }
    
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        inOrder(root, prev);
        return minDiff;
    }
};






//  one more approach INORDER OF BST IS SORTED THEN TAKE DIFFERENCE OF ADJACENT ELEMENTS ///