impl Solution {
    pub fn maximum_value(strs: Vec<String>) -> i32 {
        let mut sum = -1;
        for str in strs{
            if let Ok(number) = str.parse::<i32>(){
                sum = sum.max(number);
            }else{
                sum = sum.max(str.len());
            }
        }
        sum
    }
}
#[test]
fn maximum_value_test(){

}