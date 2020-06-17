/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
then right to left for the next level and alternate between).
For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //Using two stack for alternative level
        stack<TreeNode*> oddLevel;
        stack<TreeNode*> evenLevel;
        vector<vector<int>> result;
        if(root == NULL) 
            return result;
        
        oddLevel.push(root);
        while(!oddLevel.empty() || !evenLevel.empty()){
            vector<int> v;
            while(!oddLevel.empty()){
                TreeNode* top = oddLevel.top();
                oddLevel.pop();
                v.push_back(top->val);
                //One level push element from left to right
                if(top->left)
                    evenLevel.push(top->left);
                if(top->right)
                    evenLevel.push(top->right);
            }
            if(v.size() > 0){
                result.push_back(v);
                v.clear();
            }
            while(!evenLevel.empty()){
                TreeNode* top = evenLevel.top();
                evenLevel.pop();
                v.push_back(top->val);
                //Nexy level push elements from right to left
                if(top->right)
                    oddLevel.push(top->right);
                if(top->left)
                    oddLevel.push(top->left);
            }
            if(v.size() > 0){
                result.push_back(v);
                v.clear();
            }
        }
        return result;
    }
};
