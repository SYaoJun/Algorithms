use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let n = nums.len();
        let mut mp: HashMap<i32, i32> = HashMap::new();
        let mut i = 0;
        while i != n{
            let key = target-nums[i];
            if mp.contains_key(&key) {
                return vec![*mp.get(&key).unwrap(), i as i32];;
            }
            mp.insert(nums[i], i as i32);
            i += 1;
        }
        return vec![0,1];
    }
}