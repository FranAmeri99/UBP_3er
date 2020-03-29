package domain

import "encoding/json"

type Node struct {
    Name    string `json:"name"`
    Children []*Node `json:"children"`
}

func (n Node) ToJson() (string, error) {
    ja, err := json.Marshal(n)
    if err != nil {
        return "", err
    }
    return string(ja[:]), nil
}

func(n *Node) ComputeLine(ws []string) {
    // stop

    if len(ws) == 0 {
        return
    }

    // delegation

    for _, c := range n.Children {
        if c.Name == ws[0] {
            c.ComputeLine(ws[1:])
            return
        }
    }

    // add

    c := &Node{
        Name: ws[0],
        Children: []*Node{},
    }
    n.Children = append(n.Children, c)
    c.ComputeLine(ws[1:])
}
