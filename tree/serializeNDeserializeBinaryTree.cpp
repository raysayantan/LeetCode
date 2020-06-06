/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Accepted
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string result ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* front = q.front();
                q.pop();
                string str;
                if(front){
                    str = to_string(front->val);
                    q.push(front->left);
                    q.push(front->right);
                } else {
                    str = "null";
                }
            
                if(result != ""){
                    result += "," + str;
                } else {
                    result += str;
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        TreeNode* start = NULL;
        queue<TreeNode*> q;
        stringstream ss(data);
        if(ss.good()){
            string str;
            getline(ss, str,',');
            TreeNode* node;
            if(str != "null"){
                node = new TreeNode(stoi(str));
                start = node;
                q.push(node);
                while(!q.empty()){
                    int size = q.size();
                    for(int i = 0; i < size; i++){
                        TreeNode* front = q.front();
                        q.pop();
                        if(!front) continue;
                        TreeNode* left = NULL;
                        TreeNode* right = NULL;
                        if(ss.good()){
                            getline(ss, str, ',');
                            if(str != "null")
                                left = new TreeNode(stoi(str));
                        }
                        if(ss.good()){
                            getline(ss, str, ',');
                            if(str != "null")
                                right = new TreeNode(stoi(str));
                        }
                        front->left = left;
                        front->right = right;
                        if(front->left) q.push(front->left);
                        if(front->right) q.push(front->right);
                    }
                }
            }
        }        
        return start;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
