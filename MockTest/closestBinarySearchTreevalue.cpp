/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
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
    void helper( TreeNode* root, double target, int &res, double &diff){
        if(abs(target - root->val) < diff){
            diff = abs(target - root->val);
            res = root->val;
        }
        
        if(root->left){
            helper(root->left, target, res, diff);
        }
        
        if(root->right){
            helper(root->right, target, res, diff);
        }
    }
public:
    int closestValue(TreeNode* root, double target) {
        double diff = DBL_MAX;
        if(root == NULL)
            return diff;
        int res = root->val;
        helper(root, target, res, diff);
        
        return res;
    }
};
