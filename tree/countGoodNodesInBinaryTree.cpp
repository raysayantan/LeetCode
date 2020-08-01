/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.

Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].
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
//We are going to solve this using Inorder traversal in recursive fashion.
//We have two interger variable - currMax : This will track the max value
//on this path till now and the other one iscount : which will increment 
//as soon as we have one node with value greater than currMax and we will 
//change the currMax for that path
class Solution {
    void traverseUtil(TreeNode* root, int &count, int currMax){
        if(root == NULL)
            return;
        if(root->val >= currMax){
            count++;
            currMax = root->val;
        }
        
        traverseUtil(root->left, count, currMax);
        traverseUtil(root->right, count, currMax);
    }
public:
    int goodNodes(TreeNode* root) {
        int currMax = INT_MIN;
        int count = 0;
        traverseUtil(root, count, currMax);
        
        return count;
    }
};
