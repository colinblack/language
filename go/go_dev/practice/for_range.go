package main

import "fmt"

func forRange() {
	s := "hello 中国"
	for i, v := range s {
		fmt.Printf("index[%d], value[%c], len[%d] \n", i, v, len(string(v)))
	}

}
