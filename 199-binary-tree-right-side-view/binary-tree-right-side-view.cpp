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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                // If it's the last node in the level, add to result
                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }

                // Push left and right children to the queue
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }

        return result;
    }
};



////---------------------------------------Reverse pre order traversal (NRL)-----------------------------

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


// --------------for left side view in recusrion just use preorder with same logic------------


