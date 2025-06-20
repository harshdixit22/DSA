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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root == NULL) return res;

        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int count = q.size();
            deque<int> vec;
            

            while (count!=0) {
                TreeNode* temp = q.front();
                q.pop();
                if(level%2!=0) vec.push_back(temp->val);
                else{
                    vec.push_front(temp->val);
                }



                
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }

                if (temp->right != nullptr) {
                    q.push(temp->right);
                }

                count--;    

            }

            // or what else i can do is to reverse vector incase of even level before putting it to result vector instead of using deque.
                
            
            level++;
            res.push_back(vector<int> (vec.begin(),vec.end()));  //converting deque back to vector

        }  
        

        return res;
        
    
        
    }
};
