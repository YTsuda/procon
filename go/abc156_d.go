package main

import "fmt"
import "math"

func main() {
	var n, a, b int
	fmt.Scan(&n)
	fmt.Scan(&a)
	fmt.Scan(&b)

	ne := float64(n)

	var sum float64
	
	sum = math.Pow(2, float64(n + 1))
	fmt.Println(sum)

	sum = sum - 1 - ne
	fmt.Println(sum)
}
