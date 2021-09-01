class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 双端队列来处理
        deque<int> dq;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(dq.size() && dq.front() <= i-k) dq.pop_front();
            while(dq.size() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
        
    }
};