/*
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 

Example 1:



Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 

Constraints:

The number of nodes in the given tree is less than 6000.
-100 <= node.val <= 100
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
    Node *findRightNode(Node *parent, Node* child){
        Node *node = NULL;
        if(child == parent->left && parent->right){
            node = parent->right;
        } else {
            while(parent != NULL){
                Node *t = parent->next;
                if(t && t->left){
                    node = t->left;
                    break;
                } else if(t && t->right){
                    node = t->right;
                    break;
                } else{
                    parent = parent->next;
                }
            }
        }
        return node;
    }
    void connectUtility(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return;
        }
        if(root->left)
            root->left->next = findRightNode(root, root->left);
        if(root->right)
            root->right->next = findRightNode(root, root->right);
        connectUtility(root->right);
        connectUtility(root->left);
    }
public:
    Node* connect(Node* root) {
        connectUtility(root);
        return root;
    }
};
//****************************************************** Alternate Approach but recursive ****************************************
class Solution {
    void helper(Node* root, Node* parent){
        if(root == NULL){
            return;
        }
              
        if(parent == NULL){
            root->next = NULL;
        } else {
           if(parent->left == root){
               root->next = parent->right;
           } else {
               if(parent->next){
                   root->next = parent->next->left;
               } else {
                   root->next = NULL;
               }
           }
        }
        
        helper(root->left, root);
        helper(root->right, root);
    }
public:
    Node* connect(Node* root) {
        helper(root, NULL);
        return root;
    }
};
