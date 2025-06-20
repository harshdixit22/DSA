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
        vector<int> vec;
        queue<TreeNode*> q;
        if (root == nullptr) return vec;

        q.push(root);

        while (!q.empty()) {
            int count = q.size();
            

            while (count!=0) {
                TreeNode* temp = q.front();
                q.pop();

                if(count==1 && temp!=NULL){
                    vec.push_back(temp->val);
                }

                

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }

                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                count--;
            }

            
        }

        return vec;
        
    }
};