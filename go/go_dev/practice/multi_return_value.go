//多返回值
package main

func calc(a int, b int) (int, int) {
	sum := a + b
	avg := (a + b) / 2

	return sum, avg
}
