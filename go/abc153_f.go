package main

import "fmt"

func main() {
	var n, m int
	var answer string
	fmt.Scan(&n)
	fmt.Scan(&m)

	if n == m {
		answer = "Yes"
	} else {
		answer = "No"
	}
	fmt.Println(answer)
}
