package main

import "fmt"
import "math"
import "strconv"
import "strings"

func addFloatingValue(ope1, ope2 float64)(ans float64, err error) {
 
	// 小数点を文字列に変換
	var sOpe1 = strconv.FormatFloat(ope1, 'g', -1, 64)
	var sOpe2 = strconv.FormatFloat(ope2, 'g', -1, 64)

	fmt.Println(sOpe1)
 
	// 小数点の位置を取得する
	var pointOpe1 = 0
	if  strings.Index(sOpe1, ".") != -1 {
		pointOpe1 = strings.Index(sOpe1, ".")
	}
 
	var pointOpe2 = 0
	if  strings.Index(sOpe2, ".") != -1 {
		pointOpe2 = strings.Index(sOpe2, ".")
	}
	
	// 文字列から「.」を取り除く
	var intOpe1, checkErr1 = strconv.ParseInt(strings.Replace(sOpe1, ".", "", 1), 10, 64)
	if checkErr1 != nil {
		return 0 , checkErr1
	}
	var intOpe2, checkErr2 = strconv.ParseInt(strings.Replace(sOpe2, ".", "", 1), 10, 64)
	if checkErr2 != nil {
		return 0 , checkErr2
	}
 
	// 小数点桁が小さいほうを大きいほうに合わせる
	var index = 0
	if pointOpe1 > pointOpe2 {
		index = pointOpe1
		intOpe2 = intOpe2 * int64(math.Pow10(pointOpe1 - pointOpe2))
	} else {
		index = pointOpe2
		intOpe1 = intOpe1 * int64(math.Pow10(pointOpe2 - pointOpe1))
	}
 
	ans = float64(intOpe1 + intOpe2) / float64(math.Pow10(index))
 
	return ans, nil
}

func main() {
	var a, b, c float64
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)

	ca := math.Sqrt(a)
	cb := math.Sqrt(b)
	cc := math.Sqrt(c)

	ans, _ := addFloatingValue( ca, cb )
	res := ans < cc

	if res {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
