package main

import "fmt"

type add_func func(int, int) int

func addf(a, b int) int {
	return a + b
}

func operator(op add_func, a int, b int) int {
	return op(a, b)
}

func funcDemo() {
	f := addf
	fmt.Println(f)
	res := operator(addf, 1, 2)
	fmt.Println(res)
}
