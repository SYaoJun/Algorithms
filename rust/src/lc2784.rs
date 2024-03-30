pub fn is_good(nums: Vec<i32>) -> bool {
    let mut nums = nums;
    nums.sort();
    let n = nums.len();
    for i in 0..n{
        if i == n-1 {
            return nums[i] == i as i32;
        }else if nums[i] == (i + 1) as i32{
            continue;
        }else{
            return false;
        }
    }
    return true;
}
#[test]
fn is_good_test(){
    let mut v = vec![2, 1, 3];
    assert_eq!(false,is_good(v));
    v = vec![1, 3, 3, 2];
    assert!(is_good(v));
}