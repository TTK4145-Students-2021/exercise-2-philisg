// Use `go run foo.go` to run your program

package main

import (
	"fmt"
	"runtime"
)

func number_server(add <-chan int, sub <-chan int, read chan<- int, done <-chan bool) {
	var number = 0
	// This for-select pattern is one you will become familiar with...
	for {
		select {
			case num := <- sub:
				number -= num
			case num := <- add:
				number += num
			case <- done:
				read <- number
				return
        }
		
	}
	
}

func incrementer(add chan<- int, finished chan<- bool) {
	for j := 0; j < 1000000; j++ {
		add <- 1
	}
	//TODO: signal that the goroutine is finished
	finished <- true
	return
}

func decrementer(sub chan<- int, finished chan<- bool) {
	for j := 0; j < 1000000; j++ {
		sub <- 1
	}
	
	//TODO: signal that the goroutine is finished
	finished <- true
	return
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	var number_of_finish = 0

	// TODO: Construct the remaining channels
	read := make(chan int)
	add  := make(chan int)
	sub  := make(chan int)
	finished := make(chan bool, 2)
	done := make(chan bool)
	
	// TODO: Spawn the required goroutines
	go incrementer(add, finished)
	go decrementer(sub,	finished)
	go number_server(add, sub, read, done)
	// TODO: block on finished from both "worker" goroutines
	for number_of_finish < 2{
		if <-finished{
			number_of_finish++;	
		}
	}
	done <- true
	fmt.Println("The magic number is:", <-read)
}
