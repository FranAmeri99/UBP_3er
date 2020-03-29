package main

import (
    "fmt"
    "strings"
)

func main() {
    texto := "Anita lava la tina"
    fmt.Println("Cadena de texto: ", texto)

    if esPalindromo(texto) {
        fmt.Println("SI es palíndromo")
    } else {
        fmt.Println("NO es palíndromo")
    }
}

func esPalindromo(texto string) bool {
    texto = preparar(texto)
    n := len(texto)
    for i, j := 0, n-1; i < n/2; i, j = i+1, j-1 {
        if texto[i] != texto[j] {
            return false
        }
    }
    return true
}

func preparar(cadena string) string {
    cadena = strings.ToLower(cadena)
    return borrar(cadena, " ")
}

func borrar(cadena string, patron string) string {
    return strings.Replace(cadena, patron, "", -1)
}
