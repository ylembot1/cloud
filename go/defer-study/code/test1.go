package main

import "fmt"

var g = 100
func f() (r1 int) {
	r := g
	defer func() {
		r = 200
	}()
	r = 0
	return r
}

func main() {
	i := f()
	fmt.Printf("main: i = %d, g = %d\n", i, g)
}