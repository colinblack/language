//阶乘

package main

func factorial(n int) int64 {
	var res int64
	tmp := 1
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			tmp *= j
		}
		res += int64(tmp)
		tmp = 1
	}

	return res
}
