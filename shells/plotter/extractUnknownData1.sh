#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot.txt > default_1plot.dat

grep "PPD " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "PCN " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "PCA " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "PSC " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "EEO " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "EEC " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "EQO " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "EQC " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat