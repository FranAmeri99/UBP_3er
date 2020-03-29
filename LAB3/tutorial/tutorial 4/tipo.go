package main

import (
	"fmt"
	"strconv"
)

func main()  {

	edad := 22

	edad_string := strconv.Itoa(edad) //Int to array
	dato:="40"
	//Una funcion en go puede retornar multiples datos
	//en esta onvercion retorna dos valores, el pirmero es edad_int va a ser lo
	// entero y seguido utilizamos el operador lineal _ para descartar la basura
	//que trae. si printiamos la basura nos da <nil>
	edad_int,ena:= strconv.Atoi(dato) // Array to int
	fmt.Print("\nmi eddad es "+edad_string+"\n")
	fmt.Print(edad_int,"\n")
	fmt.Print(ena,"\n")
}