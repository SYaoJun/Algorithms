pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut min_price = i32::MAX;
    let mut max_profit_ = 0;
    for p in prices {
        max_profit_ = max_profit_.max(p - min_price);
        if p < min_price {
            min_price = p;
        }
    }
    max_profit_
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn max_profit_test() {
        let vec = vec![7, 1, 5, 3, 6, 4];
        assert_eq!(5, max_profit(vec));
    }
}
