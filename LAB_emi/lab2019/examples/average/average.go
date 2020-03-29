package main

import (
    "errors"
    "fmt"
)

func main() {
    prom, err := average([]int{1, 2, 3, 3, 4})
    if err != nil {
        fmt.Println("Error: ", err)
        return
    }
    fmt.Println("Average: ", prom)
}

func average(v []int) (int, error) {
    n := len(v)
    if n == 0 {
        e := errors.New("empty array")
        return 0, e
    }
    prom := 0
    for _, x := range v {
        prom = prom + x
    }
    return prom / n, nil
}
