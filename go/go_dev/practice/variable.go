//可变参
package main

//一个或多个int相加
func addI(arg ...int) (res int) {
	for _, v := range arg {
		res += v
	}
	return
}

//一个或多个string拼接
func concat(s ...string) (res string) {
	for _, v := range s {
		res += v
	}

	return
}
