/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
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
    int maxVal(int a, int b){
        return (a > b) ? a : b;
    }
    int maxSumPathUtil(TreeNode* root, int &maxSum){
        int left = INT_MIN;
        int right = INT_MIN;
        if(root == NULL) return 0;
        
        left = maxSumPathUtil(root->left, maxSum);
        right = maxSumPathUtil(root->right, maxSum);
        
        int maxSubTree = maxVal(maxVal(left, right) + root->val, root->val);
        maxSum = maxVal(maxSum, max(maxSubTree, root->val + left + right));
        
        return maxSubTree;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int val = maxSumPathUtil(root, maxSum);
        return maxSum;
    }
};
