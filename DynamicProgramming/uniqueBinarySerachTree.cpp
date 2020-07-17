/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

Constraints:

1 <= n <= 19
*/
class Solution {
    unordered_map<int, int> counter;
    int numTreeUtil(int low, int high){
        int leftCnt = 0;
        int rightCnt = 0;
        int total = 0;
        if(low > high)
            return 0;
        if(low == high)
            return 1;
        if(counter.find(high - low + 1) != counter.end()){
            return counter[high - low + 1];
        } else {
            for(int i = low; i <= high; i++){
                leftCnt = numTreeUtil(low, i - 1);
                rightCnt = numTreeUtil(i + 1, high);
                if(leftCnt == 0)
                    total += rightCnt;
                else if(rightCnt == 0)
                    total += leftCnt;
                else
                    total += leftCnt*rightCnt;
            }
        }
        
        counter[high - low + 1] = total;
        return total;
    }
public:
    int numTrees(int n) {
       return numTreeUtil(1, n); 
    }
};
