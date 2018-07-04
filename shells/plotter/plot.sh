#!/bin/sh

#INICIO PLOTEO DEL PRIMER VECTOR

#####PLOTEO GRUPO1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    GREEN='\033[0;32m'
    BLUE='\033[0;34m'
    NC='\033[0m' # No Color
    #printf "I ${RED}love${NC} Stack Overflow\n"

    #Obtener las estadisticas promedio
    ./extractAverageData1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram1.sh

    printf "${GREEN}Ploteo 1 generado con exito${NC}\n"

#####PLOTEO GRUPO2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram2.sh

    printf "${GREEN}Ploteo 2 generado con exito${NC}\n"

#####PLOTEO GRUPO3

   #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData3.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData3.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram3.sh

    printf "${GREEN}Ploteo 3 generado con exito${NC}\n"

#####PLOTEO GRUPO4

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageData4.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownData4.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogram4.sh

     printf "${GREEN}Ploteo 4 generado con exito${NC}\n"

#####PLOTEO GRUPO NUMERICO

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataNum.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataNum.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramNum.sh

     printf "${GREEN}Ploteo 5 generado con exito${NC}\n"

#####PLOTEO GRUPO TILDES

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAccented.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAccented.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAccented.sh

     printf "${GREEN}Ploteo 6 generado con exito${NC}\n"

#####PLOTEO GRUPO PROMEDIOS GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAvg1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAvg1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAvg1.sh

     printf "${GREEN}Ploteo 7 generado con exito${NC}\n"

#####PLOTEO GRUPO PROMEDIOS GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataAvg2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataAvg2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramAvg2.sh

     printf "${GREEN}Ploteo 8 generado con exito${NC}\n"

#####PLOTEO GRUPO TOTALES GRUPO 1

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataTot1.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataTot1.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramTot1.sh

     printf "${GREEN}Ploteo 9 generado con exito${NC}\n"

#####PLOTEO GRUPO TOTALES GRUPO 2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataTot2.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataTot2.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramTot2.sh

     printf "${GREEN}Ploteo 10 generado con exito${NC}\n"

#####PLOTEO GRUPO TOTALES GRUPO 2

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"

    #Obtener las estadisticas promedio
    ./extractAverageDataGreet.sh
    #obtener estadiscas del autor desconocido
    ./extractUnknownDataGreet.sh

    #Generar graficas con barras de error
    echo "Graficacion de resultados"
    ./plotHistogramGreet.sh

    printf "${GREEN}Ploteo 10 generado con exito${NC}\n"

    printf "${BLUE}PLOTS HAVE FINISHED!!${NC}\n"

    #Eliminar .dat existentes
    rm *.dat
    echo "Archivos eliminados"
