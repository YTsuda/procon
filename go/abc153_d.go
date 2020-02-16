package main

import "fmt"
import "math"

func main() {
	var h float64
	var x float64
	fmt.Scan(&h)

	x = math.Floor(math.Log2(h))
	m := math.Pow(2, x)
	l := int64(m)
	a := l * 2 - 1

	fmt.Println(a)
}
