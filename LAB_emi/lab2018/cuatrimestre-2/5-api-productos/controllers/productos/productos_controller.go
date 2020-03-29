package productos

import (
    "github.com/gin-gonic/gin"
    "net/http"
    productosService "github.com/emikohmann/lab2018/cuatrimestre-2/5-api-productos/services/productos"
    "github.com/emikohmann/lab2018/cuatrimestre-2/5-api-productos/utils"
)

func GetProductos(c *gin.Context) {
    
    productsList := productosService.GetProductsList()

    c.JSON(http.StatusOK, productsList)
}

func PostProductos(c *gin.Context) {

    body := utils.GetJsonBody(c.Request)

    productosService.AddProduct(body)

    c.String(http.StatusCreated, "ok")
}