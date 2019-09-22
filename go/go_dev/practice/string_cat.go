//拼接两个字符串
package main

import "fmt"

func strcat(s1 string, s2 string) string {
	return s1 + " " + s2
}

func strcat1(s1 string, s2 string) string {
	return fmt.Sprintf("%s %s", s1, s2)
}

//使用strings.join方法
/* func strcat2(s1 string, s2 string) string {


} */
