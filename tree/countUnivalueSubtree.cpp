/*
Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

 

Example 1:


Input: root = [5,1,5,5,5,null,5]
Output: 4
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6
 

Constraints:

The numbrt of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
Accepted
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
    bool isUniValue(TreeNode* root, int val){
        if(root == NULL){
            return false;
        }
        bool status = true;
        if(root->val == val){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            
            if(left){
                status &= isUniValue(left, val);
            }
            if(status == false){
                return false;
            }
            if(right){
                status &= isUniValue(right, val);
            }
            if(status == false){
                return false;
            }
        } else {
            return false;
        }
        
        return status;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int univalue = 0;
        if(root == NULL){
            return univalue;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int idx = 0; idx < size; idx++){
                TreeNode* node = q.front();
                q.pop();
                if(isUniValue(node, node->val)){
                    univalue++;
                }
                
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        
        return univalue;
    }
};
