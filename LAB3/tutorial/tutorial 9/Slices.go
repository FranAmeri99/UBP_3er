package main

import (
	"fmt"
)

func main() {
	fmt.Println("\n")

	//slices son parecidos a los array pero no hace falta definir el tamano

	var matriz []int
	fmt.Println(matriz)
	matriz2:= [5]int{1,2,3,4}
	fmt.Println(matriz2)
	fmt.Println("\n------------slice------------\n")
//	arreglo := [3]int{1,2,3}
	slice := matriz2[0:3]
	fmt.Println(slice)


}