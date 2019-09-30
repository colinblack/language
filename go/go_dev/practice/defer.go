package main

import "fmt"

func deferDemo() {
	var i int = 0
	defer fmt.Println(i)

	i = 10
	fmt.Println(i)
}

func deferDemo1() {
	defer fmt.Println("hello")
	defer fmt.Println("world")
}
