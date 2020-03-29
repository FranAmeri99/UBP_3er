package main

import (
    "encoding/json"
    "errors"
    "fmt"
    "io/ioutil"
    "net/http"
)

type Location struct {
    IP                 string  `json:"ip"`
    City               string  `json:"city"`
    Region             string  `json:"region"`
    RegionCode         string  `json:"region_code"`
    Country            string  `json:"country"`
    CountryName        string  `json:"country_name"`
    ContinentCode      string  `json:"continent_code"`
    InEu               bool    `json:"in_eu"`
    Postal             string  `json:"postal"`
    Latitude           float64 `json:"latitude"`
    Longitude          float64 `json:"longitude"`
    Timezone           string  `json:"timezone"`
    UtcOffset          string  `json:"utc_offset"`
    CountryCallingCode string  `json:"country_calling_code"`
    Currency           string  `json:"currency"`
    Languages          string  `json:"languages"`
    Asn                string  `json:"asn"`
    Org                string  `json:"org"`
    Reason             string  `json:"reason"`
    Reserved           bool    `json:"reserved"`
}

const (
    geolocationEndpoint = "https://ipapi.co/%s/json/"
    errReservedIP       = "Reserved IP address"
)

func main() {
    if err := Execute(); err != nil {
        fmt.Println("Execution error: ", err)
    }
}

func Execute() error {
    ip, err := Load()
    if err != nil {
        return err
    }
    location, err := GetLocation(ip)
    if err != nil {
        return err
    }
    ShowLocation(location)
    return nil
}

func Load() (string, error) {
    fmt.Print("Enter IP address: ")
    var ip string
    _, err := fmt.Scan(&ip)
    if err != nil {
        return "", nil
    }
    return ip, nil
}

func GetLocation(ip string) (*Location, error) {
    response, err := http.Get(fmt.Sprintf(geolocationEndpoint, ip))
    if err != nil {
        return nil, err
    }
    bytes, err := ioutil.ReadAll(response.Body)
    if err != nil {
        return nil, err
    }
    var location Location
    if err := json.Unmarshal(bytes, &location); err != nil {
        return nil, err
    }
    if location.Reason != "" {
        return nil, errors.New(location.Reason)
    }
    if location.Reserved {
        return nil, errors.New(errReservedIP)
    }
    return &location, nil
}

func ShowLocation(location *Location) {
    fmt.Println("\tIP: ", location.IP)
    fmt.Println("\tCity: ", location.City)
    fmt.Println("\tRegion: ", location.Region)
    fmt.Println("\tRegionCode: ", location.RegionCode)
    fmt.Println("\tCountry: ", location.Country)
    fmt.Println("\tCountryName: ", location.CountryName)
    fmt.Println("\tContinentCode: ", location.ContinentCode)
    fmt.Println("\tInEu: ", location.InEu)
    fmt.Println("\tPostal: ", location.Postal)
    fmt.Println("\tLatitude: ", location.Latitude)
    fmt.Println("\tLongitude: ", location.Longitude)
    fmt.Println("\tTimezone: ", location.Timezone)
    fmt.Println("\tUtcOffset: ", location.UtcOffset)
    fmt.Println("\tCountryCallingCode: ", location.CountryCallingCode)
    fmt.Println("\tCurrency: ", location.Currency)
    fmt.Println("\tLanguages: ", location.Languages)
    fmt.Println("\tAsn: ", location.Asn)
    fmt.Println("\tOrg: ", location.Org)
}
