package main

import (
	"fmt"
	"time"
)

//格式化时间
func formatTime() string {
	now := time.Now()
	return now.Format("2006/1/02 15:04")
}

//统计一段代码耗时，精确到微秒
func execTime() {
	start := time.Now().UnixNano()
	time.Sleep(time.Millisecond * 100)
	end := time.Now().UnixNano()

	res := (end - start) / 1000
	fmt.Printf("cost %d us", res)
}
