#!/bin/bash
#SCRIPT PARA PROYECTO COVID-19 UBP 2020 FRANCISCO AMERI

#TODAVIA NO CORRERLO, el sqlite que genera no funciona para la app
#se buscando mas informacion sobre comandos bash e importar archivos para que en la proxima vercion no haya que
#depender d eun conversor online
#descargar el csv directo de git con las carpetas
wget -m https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv
#para facilitar muevo el acrivo csv a la carpeta raiz y lo re nombre como recuperados.csv
mv raw.githubusercontent.com/CSSEGISandData/COVID-19/master/csse_covid_19_data/csse_covid_19_time_series/time_series_covid19_recovered_global.csv recuperados.csv
#elimino carpeta vacia
rm -r raw.githubusercontent.com
#install curl para convertit csv a sqlite comprimido en zip
sudo apt install curl
#genero el zip
curl -F files[]=@recuperados.csv 'https://www.rebasedata.com/api/v1/convert?outputFormat=sqlite&errorResponse=zip' -o output.zip 
#descomprimir archivo
unzip output.zip
#instal rename para renombrar archivo
sudo apt install rename
#lo renombro
rename 's/data/recuperados/' data.sqlite
#booro el zip
rm -r output.zip
#nueva el archivo BaseDeDatos.sqlite a la carpeta build-Clase13-Desktop-Debug
mv recuperados.sqlite build-COVID-RECUPERADOS-Desktop-Debug