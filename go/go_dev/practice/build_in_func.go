//内置函数
package main

import (
	"errors"
	"fmt"
)

func newF() {
	var i int
	fmt.Println(i)

	j := new(int)
	fmt.Println(j)
	*j = 100
	fmt.Println(*j)

}

func appendF() {
	var a []int                //数组
	a = append(a, 10, 20, 111) //用于切片
	a = append(a, a...)        //...将a展开
	fmt.Println(a)

}

func initConf() (err error) {
	return errors.New("init config error")
}

//panic and recover 相当于 throw and try catch

func exception() {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println(err)
		}
	}() //注意要加()表示调用
	/*
		b := 0
		a := 1000 / b //会产生panic */

	//	fmt.Println(a)
	err := initConf()
	if err != nil {
		panic(err)
	}

	return
}

//make和new 的区别
func differentMakeNew() {
	s1 := new([]int)
	fmt.Print(s1)

	s2 := make([]int, 10)
	fmt.Print(s2)

	//	(*s1)[0] = 100 //err 没有初始化
	*s1 = make([]int, 10)
	s2[0] = 1

}
