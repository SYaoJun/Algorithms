func twoSum(nums []int, target int) []int {
	n := len(nums)
	// 哈希表
	mp := make(map[int]int)
	for i := 0; i < n; i++ {
		x := target - nums[i]
		if value, has := mp[x]; has {
			return []int{i, value}
		}
		mp[nums[i]] = i
	}
	return []int{0, 0}
}