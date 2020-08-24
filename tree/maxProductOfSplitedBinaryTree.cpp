/*
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Example 3:

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
Example 4:

Input: root = [1,1]
Output: 1
 

Constraints:

Each tree has at most 50000 nodes and at least 2 nodes.
Each node's value is between [1, 10000].
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
    //Split this problem in two parts - 1) First traverse the tree in inorder and update
    //each node with the sum of (left subtree + right subtree + node val) in post order sequence 
    //and calculate the total sum.
    //2) Will perform another post order traversal and for each node will calculate the sum of
    //the product and check for the maximum value. Here we will perform the product of the node
    //val (which is the sum of its left and right subtree + its own val) and the remaiining elements sum
    long traverseNSum(TreeNode* root){
        if(root == NULL)
            return 0;
        long left = traverseNSum(root->left);
        long right = traverseNSum(root->right);    
        root->val = left + right + root->val;
        return root->val;
    }
    
    void traverseNFindMax(TreeNode* root, long &maxVal, long sum){
        if(root == NULL)
            return;
        
        traverseNFindMax(root->left, maxVal, sum);
        traverseNFindMax(root->right, maxVal, sum);
        long prod = root->val * (sum - root->val);
        if(prod > maxVal){
            maxVal = prod;
        }
    }
public:
    int maxProduct(TreeNode* root) {
        long sum = traverseNSum(root);
        long maxVal = INT_MIN;
        traverseNFindMax(root, maxVal, sum);
        
        return (maxVal % 1000000007);
    }
};
