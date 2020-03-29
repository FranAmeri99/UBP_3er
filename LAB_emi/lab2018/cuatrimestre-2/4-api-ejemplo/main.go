package main

import (
    "github.com/gin-gonic/gin"
    helloController "github.com/emikohmann/lab2018/cuatrimestre-2/4-api-ejemplo/controllers/hello"
    "net/http"
)

func main() {
    router := gin.Default()

    router.GET("/ping", func(c *gin.Context) {

        c.String(http.StatusOK, "pong")
    })

    router.GET("/hello", helloController.Hello)

    router.Run(":8080")
}

