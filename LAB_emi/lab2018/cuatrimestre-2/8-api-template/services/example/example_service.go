package example

import (
    "github.com/emikohmann/api-template/domain/example"
    "github.com/emikohmann/api-template/clients/rest_client"
)

// TODO!! Documentation
func ExampleService() (*example.ExampleDomain, error) {
    if err := rest_client.Get("http://example.com/example"); err != nil {
        return nil, err
    }

    if err := rest_client.Post("http://example.com/example"); err != nil {
        return nil, err
    }

    return &example.ExampleDomain{
        ExampleField: "example",
    }, nil
}
