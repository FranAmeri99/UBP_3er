package main

import (
    "fmt"
    "math/rand"
)

type Mapping struct {
    URL  string
    Hash string
}

const (
    urlCount   = 5
    hashLength = 7
)

var (
    letterRunes = []rune("ghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
    mappings    = make([]Mapping, 0)
)

func RandomString(n int) string {
    b := make([]rune, n)
    for i := range b {
        b[i] = letterRunes[rand.Intn(len(letterRunes))]
    }
    return string(b)
}

func main() {
    EnterData()
    fmt.Println("Mappings: ", mappings)
    FindURL()
}

func EnterData() {
    for i := 0; i < urlCount; i++ {
        fmt.Print(fmt.Sprintf("Enter url %d: ", i+1))

        var url string
        fmt.Scan(&url)

        var hash string
        ok := false
        for ok == false {
            hash = RandomString(hashLength)
            ok = true
            for _, m := range mappings {
                if hash == m.Hash {
                    ok = false
                    break
                }
            }
        }

        mappings = append(mappings, Mapping{
            URL:  url,
            Hash: hash,
        })
    }
}

func FindURL() {
    fmt.Print("Enter hash: ")
    var hash string
    fmt.Scan(&hash)
    for _, m := range mappings {
        if m.Hash == hash {
            fmt.Println(fmt.Sprintf("Found URL: %s", m.URL))
            return
        }
    }
    fmt.Println("URL not found")
}
