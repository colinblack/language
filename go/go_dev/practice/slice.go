//切片
package main

import "fmt"

func testSlice() {
	var slice []int
	var arr = [5]int{1, 2, 3, 4, 5}
	slice = arr[2:5] //上闭下开
	fmt.Println(slice)
	fmt.Println(len(slice))
	fmt.Println(cap(slice))

	slice = slice[0:1]
	fmt.Println(len(slice))
	fmt.Println(cap(slice))

	//slice 初始化三种方式
	//	var slice1 = []int{6, 7, 8, 9, 10}
	//		var slice1 = make([]int, 5)
	//	slice1 = arr[:]

}
