package main

import (
	"fmt"
	"sync"
)

func main() {

	// Creo un wait group
	var wg sync.WaitGroup

	// Informo al wait group que voy a ejecutar 2 go routines
	wg.Add(2)

	// Lanzamos go routines
	go mostrarMensaje("HOLA!", &wg)
	go mostrarMensaje("CHAU!", &wg)

	// Hacemos que el wait group espere la finalizacion de las go routines
	wg.Wait()
}

func mostrarMensaje(msj string, wg *sync.WaitGroup) {
	// Muestro el mensaje
	fmt.Println(msj)

	// Informo al wait group que la go routine termino
	wg.Done()
}