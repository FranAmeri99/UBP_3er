#!/bin/bash

#descargar el csv directo de git con las carpetas
wget -m https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv
#para facilitar muevo el acrivo csv a la carpeta raiz y lo re nombre como recuperos.csv
mv raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv ~/Escritorio/COVID-FRAN/recuperados.csv
#elimino carpeta vacia
rm -r raw.githubusercontent.com
#creo una nueva base de datos llamada recuperados.db
sqlite3 recuperados.db
// establece el modo de salida.
.mode csv
// importo recuperados.csv y creo la tabla t_recuperados
.import recuperados.csv recuperados
// Cambio el nombre de la colmuna 'Country/Region' a pais */
ALTER TABLE t_recuperados RENAME 'Country/Region' to pais;

