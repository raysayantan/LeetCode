/*
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
Example 3:

Input: root = [2,1,3], k = 4
Output: true
Example 4:

Input: root = [2,1,3], k = 1
Output: false
Example 5:

Input: root = [2,1,3], k = 3
Output: true
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
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
    void inorder(TreeNode* root, vector<int> &tree){
        if(root != NULL){
            inorder(root->left, tree);
            tree.push_back(root->val);
            inorder(root->right, tree);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> tree;
        inorder(root, tree);
        int start = 0;
        int end = tree.size() - 1;
        while(start < end){
            int sum = tree[start] + tree[end];
            if(sum == k){
                return true;
            }
            if(sum < k){
                start++;
            } else {
                end--;
            }
        }
        
        return false;
    }
};
