package main

import (
    "fmt"
    "github.com/emikohmann/lab2018/cuatrimestre-2/7-tree-generator/generator"
)

func main() {
    tree, err := generator.GenerateTree("./input.txt")
    if err != nil {
        panic(err)
    }

    output, err := tree.ToJson()
    if err != nil {
        panic(err)
    }

    fmt.Println(output)
}
