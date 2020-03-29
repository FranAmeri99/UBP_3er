package app

import (
    "github.com/gin-gonic/gin"
    "github.com/emikohmann/api-template/controllers/example"
)

const (
    appPort = ":8080"

    endpointExample = "/example"
)

var (
    router = gin.Default()
)

func mapRoutes() {
    router.GET(
        endpointExample, example.ExampleController,
    )
}

func run() {
    router.Run(appPort)
}
