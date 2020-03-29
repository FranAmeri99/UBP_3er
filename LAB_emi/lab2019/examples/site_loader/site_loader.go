package main

import (
    "encoding/json"
    "fmt"
    "io/ioutil"
    "net/http"
)

type Site struct {
    Name              string `json:"name"`
    CountryID         string `json:"country_id"`
    DefaultCurrencyID string `json:"default_currency_id"`
}

func main() {
    var siteID string
    fmt.Print("Enter Site ID: ")
    fmt.Scan(&siteID)

    response, err := http.Get(
        fmt.Sprintf("https://api.mercadolibre.com/sites/%s", siteID))
    if err != nil {
        fmt.Println(err)
        return
    }

    bytes, err := ioutil.ReadAll(response.Body)
    if err != nil {
        fmt.Println(err)
        return
    }

    var site Site
    err = json.Unmarshal(bytes, &site)
    if err != nil {
        fmt.Println(err)
        return
    }

    fmt.Println("Name: ", site.Name)
    fmt.Println("Country: ", site.CountryID)
    fmt.Println("Currency: ", site.DefaultCurrencyID)
}
