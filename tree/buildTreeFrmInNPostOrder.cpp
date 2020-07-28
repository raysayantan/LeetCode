/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    int findIndex(vector<int> in, int target, int s, int e){
        for(int i = s; i <= e; i++){
            if(target == in[i])
                return i;
        }
        
        return -1;
    }
    TreeNode* buildTreeUtil(vector<int> in, int s, int e, vector<int> p, int &idx){
        if(s > e)
            return NULL;
        
        TreeNode* root = new TreeNode(p[idx]);
        int i = findIndex(in, p[idx], s, e);
        if(i + 1 <= e){
            idx--;
            root->right = buildTreeUtil(in, i + 1, e, p, idx);
        }
        if(s <= i - 1){
            idx--;
            root->left = buildTreeUtil(in, s, i - 1, p, idx);
        }
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        int len = postorder.size() - 1;
        return buildTreeUtil(inorder, 0, len, postorder, len);
    }
};
