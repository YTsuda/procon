package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)

	var res int
	var has bool

	for i := 0; i < 100000; i++ {
		fa := float64(i) * 0.08
		fb := float64(i) * 0.1

		ta := int(fa) == a
		tb := int(fb) == b

		// fmt.Println(i, fa, fb, int(fa), int(fb), ta, tb)
		if ta && tb {
			res = i
			has = true
			break
		}
	}

	if has {
		fmt.Println(res)
	} else {
		fmt.Println(-1)
	}
}
