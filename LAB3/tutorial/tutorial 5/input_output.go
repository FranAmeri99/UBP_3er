package main

import (
	"fmt"
	"bufio"
	"os"
)

func main() {
	var edad  int

	fmt.Println("\nIngrese su edad: ")
	fmt.Scan(&edad)
	fmt.Print("\nmi edad es: ", edad,"\n")
///////////////////////// bufaio

	reader := bufio.NewReader(os.Stdin)
	fmt.Println("\nIngrese tu nombre: ")
	text, err := reader.ReadString('\n')

	if (err != nil) {
		fmt.Println(err)
	}else {

		fmt.Println("\nhola "+ text)
	}
}
