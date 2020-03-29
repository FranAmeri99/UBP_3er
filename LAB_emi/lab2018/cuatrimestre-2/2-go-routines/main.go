package main

import "fmt"

func main() {
	// go fmt.Println("Hola mundo")
	// go mostrarMensaje(56)

	for i := 0; i < 100; i++ {

		// Lanzo go routines
		go mostrarMensaje(i)
	}
}

func mostrarMensaje(i int) {
	fmt.Println(fmt.Sprintf("Hola %d", i))
}