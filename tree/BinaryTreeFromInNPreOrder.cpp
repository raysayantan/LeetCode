/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    int find(vector<int> in, int start, int end, int ele){
        for(int i = start; i <= end; i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* buildTreeUtil(vector<int>& pre, vector<int>& in, int &idx, int s, int e){
        if(s > e) return NULL;
        if(s == e){
           return new TreeNode(pre[idx++]); 
        }
        int val = pre[idx++];
        int rootIdx = find(in, s, e, val);
        if(rootIdx == -1) return NULL;
        TreeNode* node = new TreeNode(val);
        if(rootIdx - 1 >= s)
            node->left = buildTreeUtil(pre, in, idx, s, rootIdx - 1);
        if(rootIdx + 1 <= e)
            node->right = buildTreeUtil(pre, in, idx, rootIdx + 1, e);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return buildTreeUtil(preorder, inorder, idx, 0, preorder.size() -1);
    }
};
