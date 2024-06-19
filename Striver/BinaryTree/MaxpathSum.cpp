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
class Solution
{
public:
    int findMaxPath(TreeNode *root, int &maxi)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftmaxpath = max(0, findMaxPath(root->left, maxi));
        int rightmaxpath = max(0, findMaxPath(root->right, maxi));
        maxi = max(maxi, leftmaxpath + rightmaxpath + root->val);

        return max(leftmaxpath, rightmaxpath) + root->val;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        findMaxPath(root, maxi);
        return maxi;
    }
};