#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_tildes.txt > default_1plot.dat

grep "MAA " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "MAE " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MAI " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MAO " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MAU " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MIA " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MIE " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MII " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MIO " default_1plot.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "MIU " default_1plot.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat