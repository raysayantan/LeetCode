/*
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
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
//For this we will use the concept of level order traversal.
//we have a queue to keep the nodes of each level and find
//the max in each level and put it in the result vector
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int maxVal = INT_MIN;
        
        while(!q.empty()){
            int len = q.size();
            maxVal = INT_MIN;
            for(int idx = 0; idx < len; idx++){
                TreeNode* front = q.front();
                q.pop();
                if(front->val > maxVal){
                    maxVal = front->val;
                }
                
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            
            result.push_back(maxVal);
        }
        
        return result;
    }
};
