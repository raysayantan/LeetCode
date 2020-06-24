/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    TreeNode* parent = NULL;
public:
    void flatten(TreeNode* root) {  
        //Idea is to everytime we update the parent pointer
        //for root node it will be NULL and for others it will 
        //be the preorder predecessor
        if(root != NULL){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if(parent != NULL){
                parent->right = root;
                parent->left = NULL;
            }
            parent = root;
            flatten(left);
            flatten(right);
        }
    }
};
