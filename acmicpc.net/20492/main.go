package main

import "fmt"

func main() {
	var input int
	fmt.Scanf("%d", &input)
	fmt.Printf("%d %d\n", input/1000*780, input/1000*956)
}
