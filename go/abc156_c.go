package main

import "fmt"
import "math"

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)

	var a int
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		arr[i] = a
	}

	var min_cost float64
	min_cost = math.Inf(0)

	for i := 0; i < 100; i++ {
		var cost float64
		for _, x := range arr {
			z := float64(i - x)
			cost = cost + math.Pow(z, 2)
		} 
		if cost < min_cost {
			min_cost = cost
		}
	}

	fmt.Println(min_cost)
}
