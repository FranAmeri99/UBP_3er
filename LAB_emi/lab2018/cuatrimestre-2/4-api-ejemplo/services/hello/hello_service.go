package hello

import helloDomain "github.com/emikohmann/lab2018/cuatrimestre-2/4-api-ejemplo/domain/hello"

func GetHelloMessage() *helloDomain.HelloMessage {
    return &helloDomain.HelloMessage{
        Message: "Hello API!",
    }
}
