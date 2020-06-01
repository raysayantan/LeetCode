/*
Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as 
far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Example 1:
Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:
Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
Note:
The tree will have between 1 and 100 nodes.
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
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> container;
        int childAbsent = false;
        if(root == NULL) return true;
        container.push(root);
        //level order traversal approach
        while(!container.empty()){
            int size = container.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = container.front();
                container.pop();
                if(node->left){
                    if(childAbsent) return false;
                    container.push(node->left);
                } else {
                   childAbsent = true; 
                }
                if(node->right){
                    if(childAbsent) return false;
                    container.push(node->right);
                } else {
                    childAbsent = true;
                }
            }
        }
        
        return true;
    }
};
