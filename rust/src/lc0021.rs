pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>
  }

  
  impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
      ListNode {
        next: None,
        val
      }
    }
  }
pub fn merge_two_lists(list1: Option<Box<ListNode>>, list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    let mut new_head:Option<Box<ListNode>> = None;
    // 很明显这里需要两个指针指向头节点
    // let mut other_head = new_head.clone();
    let mut carry = 0;
    let mut list1 = list1;
    let mut list2 = list2;
    loop {
        let mut sum = 0;
        if let Some(mut a) = list1{
            sum = a.val;
            list1 = a.next;
        }else{
            break;
        }
        if let Some(mut b) = list2{
            sum += b.val;
            list2 = b.next;
        }else{
            break;
        }
        carry += sum;
        new_head = Some(Box::new(ListNode::new(carry%10)));
        carry /= 10;
    }
    None 
}

fn merge_two_lists_test(){
    let mut lst1 = ListNode::new(1);
    let mut lst2 = ListNode::new(2);
    let mut lst3 = ListNode::new(3);
    // 插入
    lst2.next = Some(Box::new(lst3));
    lst1.next = Some(Box::new(lst2));
    let head1 = Some(Box::new(lst1));

    let mut lst11 = ListNode::new(4);
    let mut lst22 = ListNode::new(5);
    let mut lst33 = ListNode::new(6);
    // 插入
    lst22.next = Some(Box::new(lst33));
    lst11.next = Some(Box::new(lst22));
    let head2 = Some(Box::new(lst11));
    
    merge_two_lists(head1, head2);
    // assert_eq!()
}