package main

import (
    "github.com/gin-gonic/gin"
    productosController "github.com/emikohmann/lab2018/cuatrimestre-2/5-api-productos/controllers/productos"
    productosService "github.com/emikohmann/lab2018/cuatrimestre-2/5-api-productos/services/productos"
)

func main() {
    productosService.LoadProducts()

    router := gin.Default()

    router.GET("/productos", productosController.GetProductos)
    router.POST("/productos", productosController.PostProductos)

    router.Run(":8080")
}

