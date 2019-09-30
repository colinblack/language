//大数相加

package main

import "fmt"

func bigNumAdd(a string, b string) string {
	var (
		res string
		tmp byte
		v1  byte
		v2  byte
	)
	for i, j := len(a)-1, len(b)-1; i >= 0 || j >= 0; i, j = i-1, j-1 {
		if i < 0 {
			v1 = 0
		} else {
			v1 = a[i]
		}

		if j < 0 {
			v2 = 0
		} else {
			v2 = b[j]
		}

		tmp = (v1 - '0') + (v2 - '0') + tmp
		res = fmt.Sprintf("%d%s", tmp%10, res)
		tmp /= 10
	}
	if tmp > 0 {
		res = fmt.Sprintf("%c%s", tmp, res)
	}

	return res
}
