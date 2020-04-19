package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)

	var a int
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		arr[i] = a
	}

	fmt.Println(arr)
}
