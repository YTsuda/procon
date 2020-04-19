package main

import "fmt"
import "math"

func main() {
	var k int
	fmt.Scan(&k)

	arr := make([]bool, 100000)

	var cnt int
	var i int
	for i = 1; i < 1000; i++ {
		if i < 10 {
			cnt = cnt + 1
		} else if i < 100 {
			k10 := i / 10
			k1 := i % 10
			diff := math.Abs(float64(k10 - k1))
			if diff < 2 {
				cnt = cnt + 1
				arr[i] = true
			}
		} else if i < 1000 {
			k100 := i / 100
			k10s := i % 100
			k10 := k10s / 10
			diff := math.Abs(float64(k100 - k10))
			if diff < 2 && arr[k10s] {
				cnt = cnt + 1
				arr[i] = true
				fmt.Println(i)
			}
		} else if i < 10000 {
			k1000 := i / 1000
			k100s := i % 1000
			k100 := k100s / 100
			diff := math.Abs(float64(k1000 - k100))
			if diff < 2 && arr[k100s] {
				cnt = cnt + 1
				arr[i] = true
			}
		} else if i < 100000 {
			k10000 := i / 10000
			k1000s := i % 10000
			k1000 := k1000s / 1000
			diff := math.Abs(float64(k10000 - k1000))
			if diff < 2 && arr[k1000s] {
				cnt = cnt + 1
				arr[i] = true
			}
		}
	}
	fmt.Println(cnt)
}
