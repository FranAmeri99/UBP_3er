package main

import (
    "fmt"
    "time"
)

func main() {
    start := time.Now()
    fmt.Println("Processing")

    ch := make(chan int, 2)

    go func() {
        values := make([]int, 0)
        for i := 0; i < 2; i++ {
            v := <-ch
            values = append(values, v)
        }
        var result int
        for _, v := range values {
            result += v
        }
        fmt.Println("Result", result)
        fmt.Println("Time", time.Since(start))
    }()

    go computeA(ch)
    go computeB(ch)
}

func computeA(ch chan int) {
    time.Sleep(
        5 * time.Second,
    )
    fmt.Println("Return value", 5)
    ch <- 5
}

func computeB(ch chan int) {
    time.Sleep(
        3 * time.Second,
    )
    fmt.Println("Return value", 6)
    ch <- 6
}
