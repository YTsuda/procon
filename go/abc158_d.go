package main

import "fmt"
import "strings"
import "sort"

func main() {
	var si string
	var q int
	fmt.Scan(&si)
	fmt.Scan(&q)

	ss := make([]string, len(si), q)
	sis := strings.Split(si, "")
	copy(ss, sis)

	var is_reversed bool

	for i := 0; i < q; i++ {
		var method int
		fmt.Scan(&method)

		if method == 1 {
			// reverse 
			is_reversed = !is_reversed
		} else {
			// add 
			var f int
			var c string
			fmt.Scan(&f)
			fmt.Scan(&c)

			if f == 1 {
				if is_reversed {
					ss = append(ss, c)
				} else {
					ss = append([]string{c}, ss...)
				}
			} else {
				if is_reversed {
					ss = append([]string{c}, ss...)
				} else {
					ss = append(ss, c)
				}
			}

		}
	}

	fmt.Println(sort.Reverse(ss))
}
