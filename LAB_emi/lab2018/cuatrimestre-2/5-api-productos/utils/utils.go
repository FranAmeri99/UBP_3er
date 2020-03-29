package utils

import (
	"net/http"
	"io/ioutil"
)

func GetJsonBody(request *http.Request) []byte {
	bytes := request.Body
	data, _ := ioutil.ReadAll(bytes)
	return data
}