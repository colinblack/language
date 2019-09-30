//匿名函数

package main

import "fmt"

var funcVar = func(a int, b int) int {
	return a + b
}

func anonFunc() {
	res := funcVar(3, 4)
	res = func(a int, b int) int {
		return a + b
	}(1, 2)

	fmt.Println("res=", res)
}
