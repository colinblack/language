//两两相加等于一个固定的数
package main

import "fmt"

var gcount int

//方法一 复杂度O（n^2）
func twoNumSum(a int, b int, input int) {
	if gcount < input {
		gcount++
		twoNumSum(a+1, b, input)
	}

	if b <= input {
		twoNumSum(a, b+1, input)
		if a+b == input {
			fmt.Println("a=", a, "b=", b)
		}
	}
}

//方法二
func twoNumSum1(input int) {
	for i := 0; i < input; i++ {
		fmt.Println("a+b=", i, input-i, input)
	}
}
