pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
    let mut sum = 0;
    let n = nums.len();
    for i in 0..n{
        if n % (i+1) == 0{
            sum += nums[i]*nums[i];
        }
    }
    return sum;
}

#[test]
fn sum_of_squares_test(){
    let mut v = vec![1,2,3,4];
    assert_eq!(21, sum_of_squares(v));
    v = vec![2,7,1,19,18,3];
    assert_eq!(63, sum_of_squares(v));
}