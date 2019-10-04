package main

import (
	"fmt"
	"sort"
)

//整数排序
func testSort() {
	a := []int{5, 2, 7, 1, 3, 4, 6, 0, 8, 10}
	sort.Ints(a)

	fmt.Println(a)
}

//字符串排序
func testStr() {
	a := [...]string{"abc", "def", "A", "ddd", "aaa", "edfg"}
	sort.Strings(a[:])

	fmt.Println(a)
}

//小数排序
func testFloat() {
	a := [...]float64{0.54, 0.88, 0.3145, 0.4657, 0.6677, 0.234}
	sort.Float64s(a[:])

	fmt.Println(a)
}

func searchInt() {
	var a = [...]int{1, 8, 33, 21, 2, 342, 123}
	index := sort.SearchInts(a[:], 2) //查找会预先排序
	fmt.Println(index)
}

//冒泡排序
func bubbleSort(data []int) {
	for i := 0; i < len(data)-1; i++ {
		for j := 0; j < len(data)-i-1; j++ {
			if data[j] > data[j+1] {
				data[j+1], data[j] = data[j], data[j+1]
			}
		}
	}
}

//选择排序
func selectSort(data []int) {
	var maxIndex int
	for i := len(data) - 1; i > 0; i-- {
		for j := 0; j <= i; j++ {
			if data[j] > data[maxIndex] {
				maxIndex = j
			}
		}
		data[maxIndex], data[i] = data[i], data[maxIndex]
		maxIndex = 0
	}
}

//插入排序
func insertSort(data []int) {
	var tmp int
	var j int
	for i := 1; i < len(data); i++ {
		tmp = data[i]
		for j = i - 1; j >= 0 && data[j] > tmp; j-- {
			data[j+1] = data[j]
		}
		data[j+1] = tmp
	}
}

func quickSplit(data []int) int {
	var pvoit int
	var index = len(data) / 2
	data[0], data[index] = data[index], data[0]
	pvoit = data[0]

	i, j := 0, len(data)-1
	for i < j {
		for i < j && data[j] > pvoit {
			j--
		}
		if i < j {
			data[i] = data[j]
			i++
		}

		for i < j && data[i] < pvoit {
			i++
		}
		if i < j {
			data[j] = data[i]
			j--
		}
	}
	data[i] = pvoit

	return i
}

//快速排序
func quickSort(data []int) {
	if len(data) > 0 {
		index := quickSplit(data)
		quickSort(data[:index])
		quickSort(data[index+1:])
	}
}

func testSort1() {
	a := [...]int{2, 5, 1, 0, 3, 7, 6}
	//bubbleSort(a[:])
	//	selectSort(a[:])
	//insertSort(a[:])
	quickSort(a[:])
	fmt.Println(a)
}
