/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode* , TreeNode* > parent;
    unordered_map<TreeNode* , long> depth;
public:

    void depths(TreeNode* node){
        if(!node) return;
        depth[node->left] = 1 + depth[node];
        depth[node->right] = 1+depth[node];

        depths(node->left);
        depths(node->right); 
    }

    void parents(TreeNode* node,TreeNode* par){
        if(!node) return;
        parent[node]  = par;
        parents(node->left , node);
        parents(node->right , node);
    }

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* dummy = depth[p] < depth[q] ? q : p;
        TreeNode* y = depth[p] < depth[q] ? p : q;
        while(depth[dummy] != depth[y]){
            dummy = parent[dummy];
        }
        while(dummy != y){
            dummy = parent[dummy];
            y = parent[y];

        }
        return dummy;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        parents(root , NULL);
        depths(root);

        return solve(root , p ,q);
        
    }
};