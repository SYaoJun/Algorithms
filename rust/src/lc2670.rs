use std::collections::HashSet;

pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
    let mut hash_set: HashSet<i32> = HashSet::new();
    let mut pre_set:HashSet<i32> = HashSet::new();
    for x in nums{
        hash_set.insert(x);
    }
    // let mut res:Vec<i32> = vec![];
    let mut res = vec![0;nums.len()];
    for (i, x) in nums.iter().enumerate(){
        pre_set.insert(x);
        res[i] = hash_set.len() - pre_set.len();
    }
    res
}