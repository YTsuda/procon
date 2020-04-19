package main

import "fmt"
import "math"

func main() {
	var H, W float64
	fmt.Scan(&H)
	fmt.Scan(&W)

	if H == 1 || W == 1 {
		fmt.Println(1)
	} else {
		res := H * W / 2
		fmt.Println(int(math.Ceil(res)))
	}

}
