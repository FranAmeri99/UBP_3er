package main

import(


	"fmt"
)

func main() {
	//make (tipo de datos, tamano del arreglo, capacidad)
	//propiedad slice capacity
	slice:=make([]int,3,5)

	fmt.Println("cout sline vacio: ",slice)
	fmt.Println("cout tamano slaine: ",len(slice))
	fmt.Println("\ncout append slice 2: ")
	slice = append(slice,2)
	fmt.Println("\ncout sline: ")
	fmt.Println(slice)
	fmt.Println("\ncout tamano sline: ",len(slice))
	fmt.Println("\ncout append slice 5: ")
	slice = append(slice,5)
	fmt.Println("\ncout sline: ")
	fmt.Println(slice)
	fmt.Println("\ncout append slice 4: ")
	slice = append(slice,4)
	fmt.Println("\ncout sline: ")

	fmt.Println(slice)

	fmt.Println("\ncout capacidad: ")
	fmt.Println(cap(slice))

}