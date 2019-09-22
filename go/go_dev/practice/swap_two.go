//交换两个整数的值
package main

func swap(a int, b int) (int, int) {
	return b, a
}

//a ^b 结果再^b还是a; a^a=0; 0^b=b
func swap1(a *int, b *int) {
	*a = *a ^ *b
	*b = *a ^ *b
	*a = *b ^ *a
}
