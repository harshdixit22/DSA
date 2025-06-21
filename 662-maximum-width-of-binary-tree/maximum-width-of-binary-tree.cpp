// class Solution {
//     int y;
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if (root == NULL) return 0;
//         int maxi = 0;

//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});

//         while (!q.empty()) {
//             int count = q.size();
//             int x = count;

//             int first = 0, last = 0;

//             while (x) {
//                 auto z = q.front();
//                 int depth = z.second;
//                 TreeNode* node = z.first;
//                 q.pop();

//                 if (x == count) {
//                     y = depth;
//                     first = depth;
//                 }
//                 if (x == 1) {
//                     last = depth;
//                     maxi = max(maxi, abs(last - first) + 1);  // ✅ Correct width
//                 }

//                 if (node->left != NULL) {
//                     q.push({node->left, depth - 1});
//                 }

//                 if (node->right != NULL) {
//                     q.push({node->right, depth + 1});
//                 }

//                 x--;
//             }
//         }

//         return maxi;
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
    int y;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int maxi = 0;

        // Use unsigned long long to prevent overflow
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int count = q.size();
            int x = count;

            unsigned long long first = 0, last = 0;
            unsigned long long min_index = q.front().second;

            while (x) {
                auto z = q.front();
                TreeNode* node = z.first;
                unsigned long long index = z.second - min_index;  // Normalize to prevent overflow
                q.pop();

                if (x == count) {
                    y = index;
                    first = index;
                }
                if (x == 1) {
                    last = index;
                    maxi = max(maxi, static_cast<int>(last - first + 1));
                }

                if (node->left != NULL) {
                    q.push({node->left, index * 2});
                }

                if (node->right != NULL) {
                    q.push({node->right, index * 2 + 1});
                }

                x--;
            }
        }

        return maxi;
    }
};
