class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            int key = target - nums[i];
            if(mp.count(key)) {
                return {i, mp[key]};
            }
            mp[nums[i]] = i;
        }
        return {0,1};
    }
};