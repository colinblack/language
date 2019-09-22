//字符串反转
package main

import "fmt"

func reverse(s string) string {
	var tmp string
	len := len(s)
	for i := 0; i < len; i++ {
		tmp = tmp + fmt.Sprintf("%c", tmp[len-i-1])
	}
	return tmp
}

//使用append
func reverse1(s string) string {
	var res []byte
	len := len(s)
	tmp := []byte(s)
	for i := 0; i < len; i++ {
		res = append(res, tmp[len-i-1])
	}

	return string(res)
}
