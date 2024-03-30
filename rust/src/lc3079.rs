pub fn sum_of_encrypted_int(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut sum = 0;
    for x in nums{
        let c1: char = '0';
        for c in x.to_string().chars(){
            if c > c1{
                c1 = c;
            }
        }
        let s = std::iter::repeat(c1).take(x.len()).collect();
        sum += s.parse().unwrap();;
    }
    sum
}