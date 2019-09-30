package main

import "fmt"

//使用闭包求斐波那契数
func fibo() func(int64) (int64, int64) {
	var (
		x int64
		y int64
	)
	return func(a int64) (int64, int64) {
		x = y
		y = a
		return x, y
	}
}

func fiboNum() {
	f := fibo()
	var v int64
	var a int64
	var b int64
	v = 1
	for i := 0; i < 100; i++ {
		a, b = f(v)
		v = a + b
		fmt.Println(v)
	}
}
