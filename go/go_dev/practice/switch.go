package main

import "fmt"

func switchS() {
	var a int = 10
	switch a {
	case 0:
		fmt.Println("a is 0")
	case 10:
		fmt.Println("a is 10")
	default:
		fmt.Println("a is default")
	}

}
