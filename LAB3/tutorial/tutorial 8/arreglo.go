package main

import (
	"fmt"
)

func main() {

	var arreglo [10]int
	fmt.Println(arreglo)
	fmt.Println("\n+++++++++++++++++\n")

	arreglo2 :=[3]int{5,6}
	fmt.Println(arreglo2)
	fmt.Println("\n+++++++++++++++++\n")

	for i:=0;i<len(arreglo2) ;i++  {
		fmt.Println(arreglo2[i])

	}
	//matrices

	fmt.Println("MATRICES")

	var matriz[3][3]int

	fmt.Println(matriz)

	matriz[0][0] = 1

	fmt.Println(matriz)

}