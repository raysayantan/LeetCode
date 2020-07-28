/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        //We will traverse the tree from root to the leaf level by level.
        //For that we are going to use a queue which will keep track of the
        //node at present level. The temporary result we will keep in a vector
        //and push back after each level to the result vector. Once done, 
        //will reverse the vector to get the result in bottom up
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int> temp;
            for(int idx = 0; idx < len; idx++){
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            
            result.push_back(temp);
            temp.clear();
        }
        
        //now we have result from top to bottom in level by level, need to reverse the same
        reverse(result.begin(), result.end());
        return result;
    }
};
