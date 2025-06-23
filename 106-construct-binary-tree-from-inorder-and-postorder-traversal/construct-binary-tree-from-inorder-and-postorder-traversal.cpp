// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int start , int end ,  int &idx){

//         if(start > end || idx <0){
//             return NULL;

//         }
        
//         int root_val = postorder[idx];
//         int i = start;

//         for(; i<=end;i++){
//             if(inorder[i]==root_val);
//             break;
//         }

//         idx--;
//         TreeNode* root = new TreeNode(root_val);
//         root->left = solve(inorder ,postorder , start , i-1 ,idx);
//         root->right  = solve(inorder ,postorder , i+1, end,idx);

//         return root;


//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

//         int n = inorder.size();
//         int m = postorder.size();

//         int idx  =  m-1;

//         return solve(inorder , postorder , 0 , n-1 , idx);    
//     }
// };

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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int start , int end , int &idx) {
        if (start > end || idx < 0) {
            return NULL;
        }

        int root_val = postorder[idx];
        int i = start;

        for (; i <= end; i++) {
            if (inorder[i] == root_val)  // ❗ removed stray semicolon
                break;
        }

        idx--;
        TreeNode* root = new TreeNode(root_val);

        // ❗ postorder: build right subtree before left
        root->right = solve(inorder, postorder, i + 1, end, idx);
        root->left  = solve(inorder, postorder, start, i - 1, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        int idx = m - 1;

        return solve(inorder, postorder, 0, n - 1, idx);    
    }
};
