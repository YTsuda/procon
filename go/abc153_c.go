package main

import "fmt"
import "sort"

func main() {
	var n, k int
	hits := make([]int, n)
	fmt.Scan(&n)
	fmt.Scan(&k)

	if n <= k {
		fmt.Println(0)
	} else {
		var h int
		for i := 0; i < n; i++ {
			fmt.Scan(&h)
			hits = append(hits, h)
		}

		sort.Ints(hits)
		hits = hits[:len(hits)-k]

		var s int64

		for _, v := range hits {
			s = s + int64(v)
		}

		fmt.Println(s)
	}
}
