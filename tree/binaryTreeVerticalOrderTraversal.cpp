/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]
Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7 

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        //We will use a map here to solve the problem. Root will have track value 0 and when we
        //move left we will decrement the track value by one so root's left will be -1 and root's
        //right will be +1 and so on. Finally we have the collection of all the nodes with same track
        //value and store the result in the result vector and return
        map<int, vector<int>> tracker;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();
                int level = front.second;
                TreeNode* node = front.first;
                tracker[level].push_back(node->val);
                if(node->left){
                    q.push({node->left, level - 1});
                }
                
                if(node->right){
                    q.push({node->right, level + 1});
                }
            }
        }
        
        //extract the result traversing the map by track value
        for(auto m = tracker.begin(); m != tracker.end(); m++){
            result.push_back(m->second);
        }
        
        return result;
    }
};
