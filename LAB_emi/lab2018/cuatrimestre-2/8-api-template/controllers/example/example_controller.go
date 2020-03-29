package example

import (
    "github.com/gin-gonic/gin"
    "github.com/emikohmann/api-template/services/example"
    "net/http"
)

const (
    keyError = "error"
)

// TODO!! Documentation
func ExampleController(c *gin.Context) {
    example, err := example.ExampleService()
    if err != nil {
        c.JSON(
            http.StatusInternalServerError,
            map[string]interface{}{
                keyError: err.Error(),
            },
        )
        return
    }

    c.JSON(
        http.StatusOK,
        example,
    )
}
