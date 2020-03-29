package main

import (
    "fmt"
    "errors"
)

type Valores []int

func (valores *Valores) Promedio() (float32, error) {
    if len(*valores) == 0 {
        return -1, errors.New("el array no puede estar vacio")
    }
    acum := 0
    for _, v := range *valores {
        acum += v
    }
    return float32(acum) / float32(len(*valores)), nil
}

func (valores *Valores) Mediana() (float32, error) {
    if len(*valores) == 0 {
        return -1, errors.New("el array no puede estar vacio")
    }
    if len(*valores)%2 != 0 {
        i := (len(*valores) - 1) / 2
        return float32((*valores)[i]), nil
    }
    i := (len(*valores) / 2) - 1
    j := i + 1
    return float32(((*valores)[i] + (*valores)[j]) / 2), nil
}

func (valores *Valores) Moda() (int, error) {
    if len(*valores) == 0 {
        return -1, errors.New("el array no puede estar vacio")
    }

    contadores := map[int]int{}
    for _, v := range *valores {
        contadores[v]++
    }

    maximo, moda := 0, 0
    for i, c := range contadores {
        if c > maximo {
            moda = i
            maximo = c
        }
    }

    return moda, nil
}

func main() {
    valores := Valores{4, 7, 2, 2, 5, 1, 1, 7, 9, 7}

    promedio, err := valores.Promedio()
    if err != nil {
        fmt.Println("No se pudo calcular el promedio,", err.Error())
    } else {
        fmt.Println("Promedio de los valores:", promedio)
    }

    mediana, err := valores.Mediana()
    if err != nil {
        fmt.Println("No se pudo calcular la mediana,", err.Error())
    } else {
        fmt.Println("Mediana de los valores:", mediana)
    }

    moda, err := valores.Moda()
    if err != nil {
        fmt.Println("No se pudo calcular la moda,", err.Error())
    } else {
        fmt.Println("Moda de los valores:", moda)
    }
}
