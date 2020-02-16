package main

import "fmt"
import "math"

func main() {
	var h, a float64
	var hit float64
	fmt.Scan(&h)
	fmt.Scan(&a)

	hit = math.Ceil(h / a)

	fmt.Println(hit)
}
