/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.According to the definition of 
LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p 
and q as descendants (where we allow a node to be a descendant of itself).”
Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        
        if(p->val == root->val || q->val == root->val){
            return root;
        }
        
        TreeNode* p1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* q1 = lowestCommonAncestor(root->right, p, q);
        
        if(p1 && q1) return root;
        if(p1) return p1;
        return q1;
    }
};
