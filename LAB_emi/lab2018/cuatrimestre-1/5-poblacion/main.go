package main

import (
    "fmt"
    "math/rand"
    "time"
)

const (
    hierba = 0
    conejo = 1
    zorro  = 2
)

var (
    bosque         [][]int
    ultimoBosque   [][]int
    vueltasTotales int
)

func main() {
    crearBosque(5)
    cargarBosque()
    mostrarBosque()
    ejecutarSimulacion()
}

func crearBosque(n int) {
    bosque = make([][]int, n)
    for i := 0; i < len(bosque); i++ {
        bosque[i] = make([]int, n)
    }
    ultimoBosque = make([][]int, n)
    for i := 0; i < len(ultimoBosque); i++ {
        ultimoBosque[i] = make([]int, n)
    }
    fmt.Println("Bosque creado")
}

func cargarBosque() {
    rand.Seed(time.Now().UTC().UnixNano())
    n := len(bosque) * len(bosque) / 2
    for i := 0; i < n; i++ {
        crearNuevo(1 + rand.Intn(2))
    }
    fmt.Println("Bosque cargado")
}

func ejecutarSimulacion() {
    for true {
        actualizarUltimoBosque()
        ejecutarPaso()
        if terminoCiclo() {
            fmt.Println("\nVueltas totales:", vueltasTotales-1)
            return
        }
        mostrarBosque()
    }
}

func ejecutarPaso() {
    vueltasTotales++

    for i, f := range bosque {
        for j := range f {
            celda := bosque[i][j]
            if celda == conejo && rodeadoPor(i, j, conejo) {
                crearNuevo(conejo)
                continue
            }
            if celda == zorro && rodeadoPor(i, j, zorro) {
                crearNuevo(zorro)
                continue
            }
        }
    }

    for i, f := range bosque {
        for j := range f {
            celda := bosque[i][j]
            if celda == zorro {
                if !rodeadoPor(i, j, conejo) {
                    bosque[i][j] = hierba
                    continue
                }
            }
        }
    }

    for i, f := range bosque {
        for j := range f {
            celda := bosque[i][j]
            if celda == conejo {
                if rodeadoPor(i, j, zorro) {
                    bosque[i][j] = hierba
                    continue
                }
            }
        }
    }
}

func actualizarUltimoBosque() {
    for i, f := range bosque {
        for j := range f {
            ultimoBosque[i][j] = bosque[i][j]
        }
    }
}

func terminoCiclo() bool {
    for i, f := range bosque {
        for j := range f {
            if ultimoBosque[i][j] != bosque[i][j] {
                return false
            }
        }
    }
    return true
}

func crearNuevo(elemento int) {
    n := len(bosque)
    bosque[rand.Intn(n)][rand.Intn(n)] = elemento
}

func rodeadoPor(i int, j int, elemento int) bool {
    supIzq, sup, supDer, izq, der, infIzq, inf, infDer := hierba, hierba, hierba, hierba, hierba, hierba, hierba, hierba

    if i > 0 {
        if j > 0 {
            supIzq = bosque[i-1][j-1]
        }
        sup = bosque[i-1][j]
        if j < len(bosque[i])-1 {
            supDer = bosque[i-1][j+1]
        }
    }
    if j > 0 {
        izq = bosque[i][j-1]
    }
    if j < len(bosque[i])-1 {
        der = bosque[i][j+1]
    }
    if i < len(bosque)-1 {
        if j > 0 {
            infIzq = bosque[i+1][j-1]
        }
        inf = bosque[i+1][j]
        if j < len(bosque[i])-1 {
            infDer = bosque[i+1][j+1]
        }
    }

    return supIzq == elemento ||
        sup == elemento ||
        supDer == elemento ||
        izq == elemento ||
        der == elemento ||
        infIzq == elemento ||
        inf == elemento ||
        infDer == elemento
}

func mostrarBosque() {
    fmt.Println("\nBosque:")
    for i := range bosque {
        fmt.Println(bosque[i])
    }
}
