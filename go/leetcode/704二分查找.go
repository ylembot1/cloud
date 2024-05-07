func search(nums []int, target int) int {
	i := 0
	j := len(nums)

	for i < j {
		mid := (j - i) / 2 + i
		if nums[mid] == target {
            return mid
        } else if nums[mid] < target {
            i = mid + 1
        } else {
            j = mid
        }
	}
	return -1;
}