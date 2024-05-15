func minimumRounds(tasks []int) int {
    mp := make(map[int]int)
    for _, num := range tasks {
        mp[num]++
    }

    res := 0
    for _, c := range mp {
        t, y := c / 3, c % 3
        if y != 0 {
            if y == 2 {
                res += t + 1
            } else if y == 1 {
                if t != 0 {
                    res += t + 1
                } else {
                    return -1
                }
            }
        } else {
            res += t
        }
    }

    return res;
}