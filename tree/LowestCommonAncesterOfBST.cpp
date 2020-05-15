/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the BST.
Accepted
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
   TreeNode* find(TreeNode* root, int val){
       if(root == NULL) return NULL;
       if(root->val == val) return root;
       if(val < root->val){
           return find(root->left, val);
       } else {
           return find(root->right, val);
       }
   }
   TreeNode* lca(TreeNode *root, int p, int q/*, TreeNode **l, TreeNode **r*/){
       TreeNode *l = NULL;
       TreeNode *r = NULL;
       if(root == NULL) return NULL;
       if(p == root->val || q == root->val){
           if(p == root->val){
               l = root;
               r = (q < root->val) ? find(root->left, q) : find(root->right, q);
           } else {
               r = root;
               l = (p < root->val) ? find(root->left, p) : find(root->right, p);
           }
           
       } else {
            if(p < root->val && q < root->val){
                l=r=lca(root->left, p, q);
            } else if(p >= root->val && q >= root->val){
                l=r=lca(root->right, p, q);
            } else {
                l = (p < root->val) ? find(root->left, p) : find(root->right, p);
                r = (q < root->val) ? find(root->left, q) : find(root->right, q);
            }
       }
       
       if(l && r){
           if(l == r) return l;
           return root;
       }
       
       if(l) return l;
       return r;
   } 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *l = NULL, *r = NULL;
        return lca(root, p->val, q->val);
    }
};
