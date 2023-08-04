#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <map>
using namespace std;

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

TEST_CASE(){
    Solution s;
    vector<int> v = {2,7,11,15};
    int target = 9;
    auto res = s.twoSum(v, target);
    REQUIRE(res.size()==2);
    REQUIRE(res[0] == 1);
    REQUIRE(res[1] == 0);
}