/*
Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        long long minIdx = 0;
        long long maxIdx = 0;
        unsigned long long width = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            for(int idx = 0; idx < size; idx++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                unsigned long long level = p.second;
                if(idx == 0){
                    minIdx = level;
                }
                
                if(idx == size - 1){
                    maxIdx = level;
                }
                if(node->left){
                    q.push({node->left, level * 2 + 1});
                }
                
                if(node->right){
                    q.push({node->right, level * 2 + 2});
                }
            }
            
            if(maxIdx - minIdx + 1 > width)
                width = maxIdx - minIdx + 1;
        } 
        
        return width;
    }
};
