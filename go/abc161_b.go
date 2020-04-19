package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	arr := make([]int, n)

	var a int
	var total int
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		arr[i] = a
		total = total + a
	}
	var cnt int

	for i := 0; i < len(arr); i++ {
		if arr[i] * 4 * m >= total {
			cnt = cnt + 1
		}
	}

	if cnt >= m {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
