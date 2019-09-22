//双引号和反引号的区别

package main

import "fmt"

func strOper1() {
	var str1 = "hello world \n\n"
	var str2 = `hello world \n\n
	this is a test string`

	fmt.Println("str1=", str1)
	fmt.Println("str2=", str2)
}
