/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> oddLevel;
        queue<TreeNode*> evenLevel;
        vector<int> result;
        
        if(root == NULL) return {};
        
        oddLevel.push(root);
        while(!oddLevel.empty()){
            TreeNode* front = NULL;
            while(!oddLevel.empty()){
                front = oddLevel.front();
                oddLevel.pop();
                if(front->left) evenLevel.push(front->left);
                if(front->right) evenLevel.push(front->right);
            }
            if(front)
                result.push_back(front->val);
            front = NULL;
            while(!evenLevel.empty()){
                front = evenLevel.front();
                evenLevel.pop();
                if(front->left) oddLevel.push(front->left);
                if(front->right) oddLevel.push(front->right);
            }
            if(front)
                result.push_back(front->val);
        }
        return result;
    }
};
