/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
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
    TreeNode* prev;
    TreeNode* firstNode;
    TreeNode* secondNode;
    bool done;
    void recoverTreeUtil(TreeNode* root){
        //this is an utility function, and recursive
        //same as inorder traversal. we keep a prev pointer
        //which will always point to the inorder predecessor
        //once we have NULL or done == true we will return.
        if(done == true)
            return;
        if(root){
            recoverTreeUtil(root->left);
            if(prev != NULL){
                if(firstNode){
                    if(prev->val > root->val){
                        secondNode = root;
                        done = true;
                    }
                } else {
                    if(prev->val > root->val){
                        firstNode = prev;
                        secondNode = root;
                    }
                }
            }
            prev = root;
            recoverTreeUtil(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
        firstNode = NULL;
        prev = NULL;
        secondNode = NULL;
        done = false;
        //we are going to use the concept of inorder traversal as this will arrange
        //the elements in a BST in sorted order(asc). Every time in a traversal of the BST
        //we found a break in the rule we need to keep track of the nodes. firstNode
        //will keep track the node the one need to exchange with second node. When 
        //we have predecessor has greater value in inorder traversal we have predecessor 
        //as firstNode and root as second. We will continue this process of searching the
        //sorted order break till another point as we may have another such break at most.
        //at the end we will swap these two nodes data. e.g. [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1]
        //here we have sorting order break at (11, 2) pair so we will assign firstNode as 
        //11 and secondNode as 2 as this is the first time we are getting this break, so we might 
        //have one more at most. Second time we got at (10,1) so this time we have the secondNode
        //as firstNode we have alreay on the first break.
        recoverTreeUtil(root);
        //now we have two nodes whose value need to be exchanged, lets do that
        int temp = secondNode->val;
        secondNode->val = firstNode->val;
        firstNode->val = temp;    
    }
};
