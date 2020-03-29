package generator

import (
    "strings"
    "github.com/emikohmann/lab2018/cuatrimestre-2/7-tree-generator/domain"
    "github.com/emikohmann/lab2018/cuatrimestre-2/7-tree-generator/io"
)

func GenerateTree(filePath string) (*domain.Node, error) {
    lines, err := io.ReadFile(filePath)
    if err != nil {
        return nil, err
    }

    node := domain.Node{
        Name: "MASTER",
        Children: []*domain.Node{},
    }

    for _, line := range lines {
        node.ComputeLine(strings.Split(line, " "))
    }

    return &node, nil
}
