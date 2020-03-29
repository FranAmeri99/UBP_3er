package productos

import (
    productosDomain "github.com/emikohmann/lab2018/cuatrimestre-2/5-api-productos/domain/productos"
    "encoding/json"
    "io/ioutil"
    "fmt"
)

var (
    productsList = make([]productosDomain.Producto, 0)
)

func LoadProducts() {
    bytes, err := ioutil.ReadFile("./productos.json")
    if err != nil {
        panic(err)
    }
    if err = json.Unmarshal(bytes, &productsList); err != nil {
        panic(err)
    }
    fmt.Println(productsList)
}

func GetProductsList() *[]productosDomain.Producto {
    return &productsList
}

func AddProduct(body []byte) {

    var p productosDomain.Producto

    json.Unmarshal(body, &p)

    productsList = append(productsList, p)

    bytes, _ := json.Marshal(&productsList)

    ioutil.WriteFile("./productos.json", bytes, 0644)
}