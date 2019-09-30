//闭包

package main

func Adder() func(int) int {
	var x int
	return func(a int) int {
		x += a
		return x
	}
}
