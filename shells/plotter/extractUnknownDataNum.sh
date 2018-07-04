#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_numbers.txt > default_1plot.dat

grep "ZERO " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "ONE " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "TWO " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "THREE " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "FOUR " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "FIVE " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "SIX " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "SEVEN " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "EIGTH " default_1plot.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "NINE " default_1plot.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat