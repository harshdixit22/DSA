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

-------------------------------------------- when string is passed by value --------------------------------------------
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


----------------------------------------- when string is passed by reference -----------------------------------------
class Solution {
public:
    void dfs(TreeNode* node,vector<string> &res,string curr){
        if(node==NULL){
            return;
        }
        int prevSize = curr.size();


        if(node->left ==NULL && node->right==NULL){
            curr+=to_string(node->val);
            res.push_back(curr);
        }
        else{
            curr+=to_string(node->val) + "->";
        }
        dfs(node->left , res , curr);

        dfs(node->right , res,  curr);

        curr.resize(prevSize);

        
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string curr = "";

        dfs(root, res, curr);
        return res;
    }
};


------------------------------ Particular node is given -----------------------------------------------------

class Solution {
public:
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        if (!root)
            return false;

        arr.push_back(root->val);

        if (root->val == x)
            return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;

        arr.pop_back(); // backtrack
        return false;
    }

    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (A == NULL) {
            return arr;
        }
        getPath(A, arr, B);
        return arr;
    }
};
  
    
