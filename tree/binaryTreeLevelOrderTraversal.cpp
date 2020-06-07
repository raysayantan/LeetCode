/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    void levelOrderUtil(TreeNode* root, vector<vector<int>> &traversedNode, int level){
        if(root == NULL) return;
        if((int)(traversedNode.size() - 1) < level){
            vector<int> v;
            v.push_back(root->val);
            traversedNode.push_back(v);
        } else {
            traversedNode[level].push_back(root->val);
        }
        if(root->left) 
            levelOrderUtil(root->left, traversedNode, level + 1);
        if(root->right)
            levelOrderUtil(root->right, traversedNode, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversedNode;
        int level = 0;
        levelOrderUtil(root, traversedNode, level);
        return traversedNode;
    }
};
