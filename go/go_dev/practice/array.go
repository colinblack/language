//数组
package main

import "fmt"

//数组是值类型, 要改变它的值必须传指针

func arrayAdd(arr *[5]int) {
	(*arr)[0] = 100
}
func arrayDemo() {
	var arr [5]int
	arrayAdd(&arr)
}

//多维数组
func multiArray() {
	var a [2][5]int = [...][5]int{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}} //中括号中数字可以用...代替
	for row, v := range a {
		for col, v1 := range v {
			fmt.Printf("(row, col)=%d", a[row][col], v1)
		}

	}
}
