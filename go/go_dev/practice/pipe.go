package main

import "fmt"

func testPipe() {
	pipe := make(chan int, 3)
	pipe <- 1
	pipe <- 2
	pipe <- 3

	var t1 int
	t1 = <-pipe

	fmt.Println(t1)
	fmt.Println(len(pipe))
}
