/*
*/
class Solution {
    int getNextIdx(vector<int>& nums, int idx, bool dir){
        bool direction = (nums[idx] >= 0);
        if(dir != direction)
            return -1;
        int index = idx + nums[idx];
        if(index < 0)
            index = (nums.size() - (-index % nums.size()))%nums.size();
        else if(index >= 0)
            index = (index)%nums.size();
        if(index == idx)
            return -1;
        return index;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        int l = nums.size();
        if(l <= 1)
            return false;
        for(int i = 0; i < l; i++){
            int slow = i;
            int fast = i;
            bool isForward = nums[i] >= 0;
            while(true){
                slow = getNextIdx(nums, slow, isForward);
                if(slow == -1)
                    break;
                fast = getNextIdx(nums, fast, isForward);
                if(fast == -1)
                    break;
                fast = getNextIdx(nums, fast, isForward);
                if(fast == -1)
                    break;
                if(fast == slow)
                    return true;
            }
        }
        return false;
    }
};
