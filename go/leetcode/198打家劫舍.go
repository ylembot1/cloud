func rob(nums []int) int {
    n := len(nums)

    dp := make([]int, n + 1)
    dp[1] = nums[0]

    for i := 2; i <= n; i++ {
        dp[i] = dp[i - 2] + nums[i - 1]
        if dp[i] < dp[i - 1] {
            dp[i] = dp[i - 1]
        }
    }

    return dp[n]
}