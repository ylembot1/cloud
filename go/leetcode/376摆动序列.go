func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

func wiggleMaxLength(nums []int) int {
	res := 1

	h := make([]int, len(nums))
	l := make([]int, len(nums))

	h[0], l[0] = 1, 1

	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			if nums[j] > nums[i] {
				h[i] = max(h[i], l[j] + 1)
			} else if nums[j] < nums[i] {
				l[i] = max(l[i], h[j] + 1)
			}
		}

		res = max(res, max(l[i], h[i]))
	}

	return res
}