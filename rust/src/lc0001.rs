use std::collections::HashMap;

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let n = nums.len();
    let mut mp: HashMap<i32, i32> = HashMap::new();
    let mut i = 0;
    while i != n {
        let key = target - nums[i];
        if mp.contains_key(&key) {
            return vec![*mp.get(&key).unwrap(), i as i32];
        }
        mp.insert(nums[i], i as i32);
        i += 1;
    }
    return vec![0, 1];
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn two_sum_test() {
        let vec = vec![7, 1, 5, 3, 6, 4];
        assert_eq!(vec![1,5], two_sum(vec, 5));
    }
}