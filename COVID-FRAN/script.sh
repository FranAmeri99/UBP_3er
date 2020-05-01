#!/bin/bash
#SCRIPT PARA PROYECTO COVID-19 UBP 2020 FRANCISCO AMERI
#BORRAR '//' DESDE sqlite3 (no se como se hacne los comentarios en sqlite xD
#descargar el csv directo de git con las carpetas
wget -m https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv
#para facilitar muevo el acrivo csv a la carpeta raiz y lo re nombre como recuperos.csv
mv raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv ~/Escritorio/COVID-FRAN/recuperados.csv
#elimino carpeta vacia
rm -r raw.githubusercontent.com
#creo una nueva base de datos llamada recuperados.db
sqlite3 recuperados.db
// establece el modo de salida.
sqlite> .mode csv
// importo recuperados.csv y creo la tabla t_recuperados
sqlite> .import recuperados.csv recuperados
// Cambio el nombre de la colmuna 'Country/Region' a pais */
sqlite> ALTER TABLE t_recuperados RENAME 'Country/Region' to pais;
// Cambio el nombre de la colmuna 'Province/State' a provincias */
sqlite> ALTER TABLE recuperados RENAME 'Province/State'  to provincias;

