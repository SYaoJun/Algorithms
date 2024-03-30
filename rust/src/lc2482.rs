pub fn ones_minus_zeros(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let m = grid.len();
    let n = grid[0].len();

     let mut rows:Vec<i32> = vec![];
     let mut cols:Vec<i32> = vec![];
     for i in 0..m{
        // 计算行
        let mut row_sum = 0;
        for j in 0..n{
            row_sum += grid[i][j];
        }
        rows.push(row_sum);
     }
     for j in 0..n{
        // 计算列
        let mut col_sum = 0;
        for i in 0..m{
            col_sum += grid[i][j];
        }
        cols.push(col_sum);
     }
     let mut res:Vec<Vec<i32>> = vec![vec![0; n]; m];
    for i in 0..m{
        // res[i].resize(n, 0);
        for j in 0..n{
            res[i][j] = 2*rows[i]-n as i32+ 2*cols[j] -m as i32;
        }
    }
    // println!("res = {:?}", res);
    res
}
#[test]
fn ones_minus_zeros_test(){
    let grid = vec![vec![0,1,1],vec![1,0,1],vec![0,0,1]];
    let res = vec![vec![0,0,4],vec![0,0,4],vec![-2,-2,2]];
    assert_eq!(ones_minus_zeros(grid), res);
}
