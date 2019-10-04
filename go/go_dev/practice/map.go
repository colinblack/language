package main

import (
	"fmt"
	"sort"
)

func testMap() {
	//	var m map[string]string
	//m["a"] = "b" 没有分配内存, 直接panic
	m := make(map[string]string, 10)
	m["a"] = "b"
	m["c"] = "d"

	fmt.Println(m)

	//申明时初始化
	m1 := map[string]string{
		"a": "b",
		"c": "d",
	}
	fmt.Println(m1)

}

//值也是map
func testMap2() {
	a := make(map[string]map[string]string, 10)
	a["key1"] = make(map[string]string)
	a["key1"]["key11"] = "a"
	a["key1"]["key12"] = "b"
	a["key1"]["key13"] = "c"
	a["key1"]["key14"] = "d"

	fmt.Println(a)
}

func modifyInfo(a map[string]map[string]string) bool {
	val, ok := a["zhangsan"]
	if ok {
		val["passwd"] = "1234"
		val["nickname"] = "pangpang"
	} else {
		a["zhangsan"] = make(map[string]string)
		a["zhangsan"]["passwd"] = "12"
		a["zhangsan"]["nickname"] = "pangzi"
	}

	//另一种写法
	/* 	if a["zhagnsan"] == nil {

	   	} */

	return true
}

func testMap3() {
	a := make(map[string]map[string]string, 10)
	modifyInfo(a)

	fmt.Println(a)
}

func trans(a map[string]map[string]string) {
	for k, v := range a {
		fmt.Println(k)
		for k1, v1 := range v {
			fmt.Println("\t", k1, v1)
		}

	}
}

//遍历，删除
//要删除所有的元素只能遍历后delete, 或者使用make
func testMap4() {
	a := make(map[string]map[string]string, 10)
	a["key1"] = make(map[string]string)
	a["key1"]["key11"] = "a"
	a["key1"]["key12"] = "b"
	a["key1"]["key13"] = "c"
	a["key1"]["key14"] = "d"
	a["key2"] = make(map[string]string)
	a["key2"]["key21"] = "d"
	a["key2"]["key22"] = "e"
	a["key2"]["key23"] = "f"
	trans(a)

	delete(a, "key1")
	trans(a)

	//长度
	fmt.Println(len(a))
}

//slice中的map
func testMap5() {
	var a []map[int]int
	a = make([]map[int]int, 5)

	//map, slice判空用nil
	if a[0] == nil {
		a[0] = make(map[int]int)
	}
	a[0][10] = 5
	fmt.Println(a)
}

//map 排序
func testMap6() {
	//key值无序
	a := make(map[int]int, 5)
	a[0] = 10
	a[1] = 10
	a[2] = 10
	a[3] = 10
	a[4] = 10

	for k, v := range a {
		fmt.Println(k, v)
	}

	var keys []int
	for k, _ := range a {
		keys = append(keys, k)
	}

	fmt.Printf("\n")
	sort.Ints(keys)

	for _, v := range keys {
		fmt.Println(v, a[v])
	}

}

//反转
func testMap7() {
	a := make(map[string]int, 5)
	b := make(map[int]string, 5)

	a["abc"] = 123
	a["def"] = 456
	a["ghi"] = 789
	a["jkl"] = 789

	for k, v := range a {
		b[v] = k
	}
	fmt.Println(b)
}
