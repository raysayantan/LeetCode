/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,null,2]
Output: [1,2]
Example 5:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1
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
    vector<int> largestValues(TreeNode* root) {
        int maxVal = INT_MIN;
        vector<int> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            maxVal = INT_MIN;
            for(int eIdx = 0; eIdx < size; eIdx++){
                TreeNode* node = q.front();
                q.pop();
                if(maxVal < node->val){
                    maxVal = node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                
                if(node->right){
                    q.push(node->right);
                }
            }
            
            result.push_back(maxVal);
        }
        return result;
    }
};
