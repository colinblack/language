//回文串

package main

import "fmt"

func palindrome() bool {
	var input string
	fmt.Scanf("%s", &input)
	//注意go不支持逗号表达式
	if len(input) < 2 {
		return false
	}

	inputS := []rune(input) //支持utf8编码
	for i, j := 0, len(inputS)-1; i < j; i, j = i+1, j-1 {
		if inputS[i] != inputS[j] {
			return false
		}
	}

	return true
}
