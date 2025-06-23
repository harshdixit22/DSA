// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if (root == NULL) {
//             return true;
//         }

//         if (root->left == NULL && root->right == NULL) {
//             return true;
//         }

//         if (root->left != NULL && root->val <= root->left->val) {
//             return false;
//         }

//         if (root->right != NULL && root->val >= root->right->val) {
//             return false;
//         }

//         return isValidBST(root->left) && isValidBST(root->right);
//     }
// };
//  -------------- above code failed ---------------------------------------------------

class Solution {
public:
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        // Left subtree
        if (!isValidBST(root->left)) return false;

        // Current node must be greater than previous
        if (prev != NULL && root->val <= prev->val) return false;

        // Update prev to current
        prev = root;

        // Right subtree
        return isValidBST(root->right);
    }
};
