//输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数

package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
)

func count() {
	var input string
	var countLetter int
	var countDigit int
	var countSpace int
	var countOther int
	reader := bufio.NewReader(os.Stdin) //读取输入
	res, _, err := reader.ReadLine()
	if err != nil {
		fmt.Println("read error: ", err)
		return
	}
	//fmt.Scanf("%s", &input)
	input = string(res)
	for _, v := range input {
		if unicode.IsLetter(v) {
			countLetter++
		} else if unicode.IsDigit(v) {
			countDigit++
		} else if unicode.IsSpace(v) {
			countSpace++
		} else {
			countOther++
		}
	}

	fmt.Println("letter: ", countLetter, "digit: ", countDigit, "space: ", countSpace, "other:", countOther)
}
