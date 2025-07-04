class Solution {
public:
    
        
    string DFS(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& res){
        if(root == NULL) 
            return "NULL";
        
        string s = to_string(root->val) + "," + DFS(root->left, mp, res) + "," + DFS(root->right, mp, res);
        
        if(mp[s] == 1)
            res.push_back(root);
        
        mp[s]++;
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        
        vector<TreeNode*>res;
        
        DFS(root, mp, res);
        
        return res;
    }

};