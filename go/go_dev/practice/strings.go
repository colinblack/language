package main

import (
	"fmt"
	"strconv"
	"strings"
)

//HasPrefix和HasSuffix
func prefixAndSuffix() {
	var (
		url  string
		path string
	)

	fmt.Scanf("%s%s", &url, &path)

	res := strings.HasPrefix(url, "http://")
	if !res {
		url = fmt.Sprintf("http://%s", url)
	}

	res = strings.HasSuffix(path, "/")
	if !res {
		path = fmt.Sprintf("%s/", path)
	}
	fmt.Println("url", url, "path", path)
}

//替换
func replace() {
	str := "my name is colin"
	str = strings.Replace(str, "colin", "cp", 1) //替换, 注意str是值传递
	fmt.Println("str=", str)
}

//重复
func repeat() {
	str := "hello"
	str = strings.Repeat(str, 3)
	fmt.Println("str=", str)
}

//转成小写
func toLower() {
	str := "HELLO WORLD"
	str = strings.ToLower(str)
	fmt.Println("str=", str)
}

//转成大写
func toUper() {
	str := "hello world"
	str = strings.ToUpper(str)
	fmt.Println("str=", str)
}

//去掉字符串首尾空白字符
func TrimSpace() {
	str := "   hello world   "
	str = strings.TrimSpace(str)
	fmt.Println("str=", str)
}

//去掉字符串首尾cut字符
func Trim() {
	str := "...hello world..."
	str = strings.Trim(str, ".")
	fmt.Println("str=", str)
}

//去掉字符串首cut字符
func TrimLeft() {
	str := "   hello world   "
	str = strings.TrimLeft(str, " ")
	fmt.Println("str=", str)
}

//去掉字符串尾cut字符
func TrimRight() {
	str := " hello world***"
	str = strings.TrimRight(str, "*")
	fmt.Println("str=", str)
}

//返回str空格分隔的所有子串的slice
func Filed() {
	str := "ab cd efg hi"
	res := strings.Fields(str)
	for i := 0; i < len(res); i++ {
		fmt.Println(res[i])
	}
}

//返回str split分隔的所有子串的slice
func Split() {
	str := "ab,cd,efg,hi"
	res := strings.Split(str, ",")
	for i := 0; i < len(res); i++ {
		fmt.Println(res[i])
	}
}

//用sep把s1中的所有元素链接起来
func Join() {
	s := []string{"aa", "bb", "cc", "dd"}
	str := strings.Join(s, ",")
	fmt.Println("str=", str)
}

//把一个整数i转成字符串
func Itoa() {
	i := 666
	str := strconv.Itoa(i)
	fmt.Println("str=", str)
}

//把一个字符串转为整数
func Atoi() {
	str := "666"
	i, _ := strconv.Atoi(str)
	fmt.Println("i=", i)
}
