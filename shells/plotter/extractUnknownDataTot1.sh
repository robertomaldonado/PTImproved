#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_totales.txt > default_1plot.dat

grep "TUS " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "TLS " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNW " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNS " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNP " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNT " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNWS " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat