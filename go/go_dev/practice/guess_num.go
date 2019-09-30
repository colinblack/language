//猜数字
package main

import (
	"fmt"
	"math/rand"
)

func guessNum() {
	var guess int
	fmt.Scanf("%d", &guess)
	num := rand.Intn(100)
	switch {
	case guess == num:
		fmt.Println("equal")
	case guess > num:
		fmt.Println("great")
	case guess < num:
		fmt.Println("less")
	default:
		fmt.Println("error")
	}
}
