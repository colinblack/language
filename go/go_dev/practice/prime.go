//素数
package main

import "math"

//判断是否为素数
func isPrime(v int) bool {
	if v == 1 {
		return false
	}
	for i := 2; i < int(math.Sqrt(float64(v)))+1; i++ {
		if v%i == 0 {
			return false
		}
	}
	return true
}
