package main

import (
	"fmt"
	"math/rand"
	"sync"
	"sync/atomic"
	"time"
)

//线程同步 go build *.go -race可以检查是否有竞争
func testSync() {
	a := make(map[int]int, 10)
	a[0] = 1
	a[1] = 2
	a[2] = 3
	a[3] = 4
	a[4] = 5

	//启两个协程go + func
	for i := 0; i < 2; i++ {
		go func(b map[int]int) {
			b[0] = rand.Intn(100) //每个协程都会写入， 有竞争
		}(a)
	}

	fmt.Println(a)
}

var lock sync.Mutex

//加锁
func testSync1() {
	a := make(map[int]int, 10)
	a[0] = 1
	a[1] = 2
	a[2] = 3
	a[3] = 4
	a[4] = 5

	//启两个协程go + func
	for i := 0; i < 2; i++ {
		go func(b map[int]int) {
			lock.Lock()
			b[0] = rand.Intn(100) //每个协程都会写入， 有竞争
			lock.Unlock()
		}(a)
	}

	//读也要加锁
	lock.Lock()
	fmt.Println(a)
	lock.Unlock()
}

var rwlock sync.RWMutex

//读写锁
func testSync2() {
	a := make(map[int]int, 10)
	a[0] = 1
	a[1] = 2
	a[2] = 3
	a[3] = 4
	a[4] = 5

	var count int32
	//启两个协程go + func
	for i := 0; i < 2; i++ {
		go func(b map[int]int) {
			rwlock.Lock()
			//time.Sleep(10 * time.Millisecond)
			b[0] = rand.Intn(100)
			rwlock.Unlock()
		}(a)
	}

	for i := 0; i < 100; i++ {
		go func(b map[int]int) {
			rwlock.RLock()
			//time.Sleep(time.Millisecond)
			fmt.Println(b)
			rwlock.RUnlock()
			atomic.AddInt32(&count, 1)
		}(a)
	}
	time.Sleep(time.Second * 10)
	fmt.Println(atomic.LoadInt32(&count))
}
