func twoSum(nums []int, target int) []int {
	prevNums := map[int]int{}

	for i, num := range nums {
		targetNum := target - num
		targetNumIndex, ok := prevNums[targetNum]
		if ok {
			return []int{targetNumIndex, i}
		}
		prevNums[num] = i
	}

	return []int{}
}


func twoSum(nums []int, target int) []int {
	for i, num := range nums {
		for j := i + 1; j < len(nums); j++ {
			if (num + nums[j] == target) {
				return []int{i, j}
			}
		}
	}

	return []int{}
}