package main

import "fmt"

func main() {
	var h, n int

	fmt.Scan(&h)
	fmt.Scan(&n)

	type Magic struct {
		damage int
		cost int
	}

	magics := make([]Magic, n)

	var d, c int

	dp := make([]int, h + 1)

	for i := 0; i < n; i++ {
		fmt.Scan(&d)
		fmt.Scan(&c)
		magics[i] = Magic{d, c}
	}

	for i := 0; i < h; i++ {
		if i > 0 && dp[i] == 0 {
			continue
		}

		for _, m := range magics {
			next_cost := dp[i] + m.cost
			next_i := i + m.damage

			if next_i >= h {
				next_i = h
			} 

			if dp[next_i] == 0 || dp[next_i] > next_cost {
				dp[next_i] = next_cost
			}
		}
	}

	fmt.Println(dp[h])
}
