pub fn is_palindrome(s: String) -> bool {
    let mut ss = String::new();
    for c in s.chars(){
        if c.is_alphabetic(){
            ss.push(c.to_lowercase());
        }
    }
    let n = ss.len();
    let mut i = 0;
    let mut j = n -1;
    while i < j{
        if ss[i] != ss[j]{
            return false;
        }
        i+=1;
        j-=1;
    }
    return true;
}