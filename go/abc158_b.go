package main

import "fmt"

func main() {
	var n, a, b int
	fmt.Scan(&n)
	fmt.Scan(&a)
	fmt.Scan(&b)

	var res int

	if a == 0 && b == 0 {
		res = 0
	} else {
		ab := a + b

		sho := n / ab
		amari := n % ab

		if a - amari < 0 {
			res = sho * a + a
		} else {
			res = sho * a + amari
		}
	}

	fmt.Println(res)
}
