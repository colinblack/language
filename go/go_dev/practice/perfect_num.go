package main

import "fmt"

//找出1000以内的完数

func perfectNum(num int) {
	var sum int
	for i := 1; i < num; i++ {
		for j := 1; j <= i/2; j++ {
			if i%j == 0 {
				sum += j
			}
		}
		if i == sum {
			fmt.Println(i)
		}
		sum = 0
	}
}
