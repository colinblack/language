//判断水仙花数
package main

func isNarc(v int) bool {
	//必须是三位数
	if v < 99 || v > 999 {
		return false
	}

	var tmp int
	var res int
	value := v
	for v != 0 {
		tmp = v % 10
		res += tmp * tmp * tmp
		v /= 10
	}

	return res == value
}
