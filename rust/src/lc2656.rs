pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
    let n = nums.len();
    let m = nums.iter().max();
    let mut sum = 0;
    for i in 0..k as usize{
        sum += m + i as i32;
    }
    sum
}