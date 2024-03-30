pub fn minimum_sum(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut sum = 0x3f3f3f3f;
    for i in 0..n{
        for j in i..n{
            for k in j..n{
                if nums[i] < nums[j]  && nums[j] > nums[k]{
                    sum = sum.min(nums[i]+nums[j] + nums[k]);
                }
            }
        }
    }
    if sum == 0x3f3f3f3f{
        return -1;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn minimum_sum_test() {
        let mut vec = vec![8,6,1,5,3];
        assert_eq!(9, minimum_sum(vec));
        vec = vec![5,4,8,7,10,2];
        assert_eq!(13, minimum_sum(vec));
        vec = vec![6,5,4,3,4,5];
        assert_eq!(-1, minimum_sum(vec));
    }
}