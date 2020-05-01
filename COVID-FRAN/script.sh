#!/bin/bash


wget -m https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv
mv raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv ~/Escritorio/COVID-FRAN/recuperados.csv
rm -r raw.githubusercontent.com

sqlite3 recuperados.db
.mode csv
.import recuperados.csv recuperados
ALTER TABLE recuperados RENAME 'Country/Region' to pais;

