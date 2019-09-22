package main

//生成随机数
import (
	"fmt"
	"math/rand"
)

func randNum() {
	for i := 0; i < 10; i++ {
		fmt.Println(rand.Intn(100))
	}

	for i := 0; i < 10; i++ {
		fmt.Println(rand.Float32())
	}
}
