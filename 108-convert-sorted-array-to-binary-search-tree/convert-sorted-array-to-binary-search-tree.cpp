class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nullptr;

        int mid = n / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Left half (exclude mid)
        vector<int> left(nums.begin(), nums.begin() + mid);
        root->left = sortedArrayToBST(left);

        // Right half (always exclude mid)
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(right);

        return root;
    }
};
