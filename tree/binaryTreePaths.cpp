/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    void helper(TreeNode* root, vector<string> &paths, string path){
        if(root->left == NULL && root->right == NULL){
            path = path + to_string(root->val);
            paths.push_back(path);
            return;
        }
        
        path = path + to_string(root->val) + "->";
        if(root->left){
            helper(root->left, paths, path);
        }
        
        if(root->right){
            helper(root->right, paths, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        if(root == NULL)
            return paths;
        string path = "";
        helper(root, paths, path);
        
        return paths;
    }
};
