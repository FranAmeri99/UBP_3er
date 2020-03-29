package main

import (
	"fmt"
)

func main() {
	/*copy(destino, fuente)


	copia el minimo de elementos
	tomana el tamano mas chico
	 */
	slice := []int{1,2,3,4,5,6,7,8,9}
	copia := make([]int, len(slice), cap(slice)*2)

	fmt.Println(slice)
	fmt.Println(copia)
	copy(copia,slice)
	fmt.Println(copia)

}