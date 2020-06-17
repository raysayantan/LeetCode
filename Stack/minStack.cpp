/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
Constraints:
Methods pop, top and getMin operations will always be called on non-empty stacks.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    vector<vector<int>> data;
    int topIdx;
    MinStack() {
        topIdx = -1;
    }
    
    void push(int x) {
        vector<int> front(2);
        int min = x;
        if(topIdx >= 0){
            min = data[topIdx][1];
            if(x < min){
                min = x;
            }
        }
        front[0] = x;
        front[1] = min;
        data.push_back(front);
        topIdx++;
    }
    
    void pop() {
        data.pop_back();
        topIdx--;
    }
    
    int top() {
        return data[topIdx][0];
    }
    
    int getMin() {
        return data[topIdx][1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
