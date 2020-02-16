package main

import "fmt"

func main() {
	var h, n, a, as int
	fmt.Scan(&h)
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		as = as + a
	}

	var answer string

	if h <= as {
		answer = "Yes"
	} else {
		answer = "No"
	}

	fmt.Println(answer)
}
