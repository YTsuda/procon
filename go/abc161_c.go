package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n)
	fmt.Scan(&k)

	amari := n % k

	if amari == 0 {
		fmt.Println(0)
	} else {
		diff := k - amari
		if amari > diff {
			fmt.Println(diff)
		} else {
			fmt.Println(amari)
		}
	}
}
