/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees 
of every node never differ by more than 1.
Example:
Given the sorted linked list: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    TreeNode* constructTree(vector<int> data, int start, int end){
        TreeNode* root = NULL;
        if(start > end){
            return NULL;
        }  
            
        int mid = (start +  end)/2;
        root = new TreeNode(data[mid]);
        root->left = constructTree(data, start, mid - 1);
        root->right = constructTree(data, mid + 1, end);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        //put the node values in a vector for random access
        vector<int> data;
        while(head){
            data.push_back(head->val);
            head = head->next;
        }
        
        //Everytime pick the middle element and left of it will be left subtree 
        //and the right one is right subtree and will keeps on moving
        TreeNode* root = NULL;
        root = constructTree(data, 0, data.size() - 1);
        return root;
    }
};
