#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_greeting.txt > default_1plot.dat

grep "G1 " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s/5, 0}' > estadisticaGlobalIndiv1.dat
grep "G2 " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "G3 " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "G4 " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "G5 " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "G6 " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "F1 " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "F2 " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "F3 " default_1plot.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "F4 " default_1plot.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat
grep "F5 " default_1plot.dat | awk '{s=$24}END{printf "%.4f %.4f\n" , s/5, 0}' >> estadisticaGlobalIndiv1.dat