Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2:
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int leftMost;
        q.push(root);
        
        while(!q.empty()){
            int len = q.size();
           for(int i = 0; i < len; i++){
                TreeNode* top = q.front();
                if(i == 0) leftMost = top->val;
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        
        return leftMost;
    }
};
