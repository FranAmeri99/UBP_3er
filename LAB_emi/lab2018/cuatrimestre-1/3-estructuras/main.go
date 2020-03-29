package main

import (
    "fmt"
)

type Alumno struct {
    Nombre   string
    Legajo   int64
    Promedio float32
}

func (alumno *Alumno) ModificarLegajo(nuevoLegajo int64) *Alumno {
    alumno.Legajo = nuevoLegajo
    return alumno
}

func main() {
    alumno := &Alumno{
        Nombre:   "Emiliano",
        Legajo:   123,
        Promedio: 7.67,
    }

    fmt.Println("Viejo legajo: ", alumno.Legajo)
    alumno = alumno.ModificarLegajo(555)
    fmt.Println("Nuevo legajo: ", alumno.Legajo)
}
