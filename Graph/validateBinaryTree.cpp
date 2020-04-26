/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:



Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
Example 4:



Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
 

Constraints:

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1
*/
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //As per the question we have only one valid Binary tree, so I will check there will be one and only
        //one node with in degree 0 and all rest are indegree one, the one having indegree 0, must have atleast
        //one child if node count more than one, else return false;
        vector<int> inDegree(n);
        if(n == 1) return true;
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1){
                inDegree[leftChild[i]]++;
            }
            
            if(rightChild[i] != -1){
                inDegree[rightChild[i]]++;
            }
        }
        
        int rootNodeCnt = 0;
        int rootNode = -1;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) {
                if(rootNodeCnt == 0){
                    rootNodeCnt++;
                    rootNode = i;
                } else return false;
            }
            if(inDegree[i] > 1) return false;
        }
        
        if(rootNodeCnt == 1) {
            if(leftChild[rootNode] == -1 && rightChild[rootNode] == -1)
                return false;
        } else {
            return false;
        }
        
        return true;
    }
};
