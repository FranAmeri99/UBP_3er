package main

import(
	"fmt"
)

func main() {

	for i:=0;i<10; i++  {
		fmt.Println("for1 posicion [",i, "] \n")
	}
	fmt.Println("\n--------------------------------\n")


	j:=0
	for j<10  {
		fmt.Println("for2 posicion [",j, "] \n")
		j++
	}

	fmt.Println("\n--------------------------------\n")
	k:=0
	for {
		fmt.Println("for3 posicion [",k, "] \n")
		k++
		if k>=10{
			break
		}
	}

	fmt.Println("\n--------------------------------\n")




}