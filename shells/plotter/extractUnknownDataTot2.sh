#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_totales.txt > default_1plot.dat

grep "TNMQ " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "TNME " default_1plot.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNE " default_1plot.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNWAP " default_1plot.dat | awk '{s=$24}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNK1 " default_1plot.dat | awk '{s=$26}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNK2 " default_1plot.dat | awk '{s=$28}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNK3 " default_1plot.dat | awk '{s=$30}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNCBS " default_1plot.dat | awk '{s=$32}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TNCAS " default_1plot.dat | awk '{s=$34}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat