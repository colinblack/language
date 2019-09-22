package main

import (
	"fmt"
	"math/rand"
	"time"
)

//初始化
func init() {
	rand.Seed(time.Now().UnixNano()) //随机数种子
}

//全局管道
var gpipe chan int

func add(a int, b int) {
	sum := a + b
	gpipe <- sum
	return
}

//channel作为入参
func add1(a int, b int, c chan int) {
	sum := a + b
	c <- sum
}

func main() {

	//	go testGoroute(100, 200)
	/* 	for i := 0; i < 100; i++ {
		go testPrint(i)
	} */

	//	testPipe()

	//gpipe = make(chan int, 1)
	//go add1(2, 3, gpipe)

	//	sum := <-gpipe //管道没有数据的时候会阻塞，所以不用sleep
	//	fmt.Println("sum=", sum)
	//	time.Sleep(time.Second)
	//	a, b := calc(100, 200)
	//	fmt.Println("sum=", a, "avg", b)
	//	f := 100.10
	//	fmt.Println(f)
	//	twoNumSum(0, 0, j)
	//GetOsInfo()
	/* 	a, b := 4, 5
	   	swap1(&a, &b)
	   	fmt.Println("a=", a, "b=", b) */
	//randNum()
	//strOper1()
	//	fmt.Println("s=", substr("hello world", 0, 5))
	fmt.Println(reverse1("hello world"))
}
