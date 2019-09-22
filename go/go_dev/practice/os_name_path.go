//获取当前运行的操作系统名称和Path环境变量值, 并打印到终端

package main

import (
	"fmt"
	"os"
)

func GetOsInfo() {
	var goos string = os.Getenv("GOOS")
	fmt.Printf("The Os is %s \n", goos)
	path := os.Getenv("PATH")
	fmt.Printf("Path %s \n", path)
}
