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
	modify(slice)

}

//切片是引用类型
func modify(a []int) {
	a[1] = 1000
}

//追加, 当追加元素后切片长度超过容积后会重新分配内存
func appendS() {
	//slice := make([]int, 5)
	//var slice1 = []int{1, 2, 3}
	//	slice = append(slice, slice1...)
	array := [...]int{1, 2, 3, 4, 5}
	slice := array[1:3]
	slice = append(slice, 1)
	slice = append(slice, 2)
	slice = append(slice, 3)
	slice = append(slice, 4)
	slice = append(slice, 5)

	fmt.Println(array)
	fmt.Println(slice)
	fmt.Printf("len=%d, cap=%d", len(slice), cap(slice))
}

//copy 拷贝不会扩容
func copyS() {
	a := []int{1, 2, 3, 4, 5, 6}
	b := make([]int, 10)

	copy(b, a)
	fmt.Println(b)
}

//字符串切片操作
func sliceStr() {
	s := "hello world"
	s1 := s[:5]
	s2 := s[6:]

	fmt.Println(s1)
	fmt.Println(s2)

}

//修改字符串
func modifyStr() {
	s := "hello world"
	//s[0] = 'a' 字符串是常量不能修改
	str := []byte(s) //修改字节
	str[0] = 'a'
	str1 := string(str)
	fmt.Printf("str=%s, s=%s \n", str1, s) //s并没有修改，说明str在不同内存

	str2 := []rune(s)
	str2[0] = '我' //修改unicode字符
	str3 := string(str2)
	fmt.Println(str3)

}
