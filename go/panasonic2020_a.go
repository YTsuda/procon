package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	var arr = []int{1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51}

	fmt.Println(arr[n - 1])
}
