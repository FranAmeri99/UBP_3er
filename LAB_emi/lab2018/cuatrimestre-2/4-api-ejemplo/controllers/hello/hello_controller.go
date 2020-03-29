package hello

import (
    "github.com/gin-gonic/gin"
    "net/http"
    helloService "github.com/emikohmann/lab2018/cuatrimestre-2/4-api-ejemplo/services/hello"
)

func Hello(c *gin.Context) {
    
    helloMessage := helloService.GetHelloMessage()

    c.JSON(http.StatusOK, helloMessage)
}
