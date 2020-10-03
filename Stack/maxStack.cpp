/*
Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
class MaxStack {
    stack<pair<int, int>> data;
    pair<int, int> front;
public:
    /** initialize your data structure here. */
    MaxStack() {
        front = {INT_MIN, INT_MIN};
    }
    
    void push(int x) {
        pair<int, int> e;
        e.first = x;
        e.second = (x >= front.second) ? x : front.second;
        data.push(e);
        front = e;
    }
    
    int pop() {
        if(!data.empty()){
            pair<int, int> e = data.top();
            data.pop();
            if(!data.empty())
                front = data.top();
            else
                front = {INT_MIN, INT_MIN};
            return e.first;
        }
        
        return INT_MIN;
    }
    
    int top() {
        return front.first;
    }
    
    int peekMax() {
        return front.second;
    }
    
    int popMax() {
        int retVal = INT_MIN;
        if(!data.empty()){
            stack<pair<int, int>> temp;
            int maxVal = front.second;
            while(!data.empty() && data.top().first != maxVal){
                temp.push(data.top());
                data.pop();
            }
            
            if(!data.empty()){
                auto e = data.top();
                data.pop();
                retVal = e.first;
            }
            maxVal = (!data.empty()) ? data.top().second : INT_MIN;
            //cout<<"max here "<<maxVal<<endl;
            while(!temp.empty()){
                auto e = temp.top();
                temp.pop();
                e.second = (e.first > maxVal) ? e.first : maxVal;
                maxVal = e.second;
                //cout<<e.first<<":"<<e.second<<endl;
                data.push(e);
            }
            
            if(!data.empty()){
                front = data.top();
            } else {
                front = {INT_MIN, INT_MIN};
            }
        }
        return retVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
