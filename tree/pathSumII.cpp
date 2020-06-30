/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> result;
    vector<int> path;
    void findPathSum(TreeNode *root, int num, int sum){
        if(root == NULL)
            return;
        sum += root->val;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            //leaf node
            if(sum == num){
                result.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        if(root->left){
            findPathSum(root->left, num, sum);
        }
        if(root->right){
            findPathSum(root->right, num, sum);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findPathSum(root, sum, 0);
        return result;
    }
};
