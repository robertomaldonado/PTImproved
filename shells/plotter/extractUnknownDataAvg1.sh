#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_averages.txt > default_1plot.dat

grep "AWL " default_1plot.dat | awk '{s=$4}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "AWPS " default_1plot.dat | awk '{s=$6}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AWPP " default_1plot.dat | awk '{s=$8}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ADPP " default_1plot.dat | awk '{s=$10}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ACPP " default_1plot.dat | awk '{s=$12}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ACOPP " default_1plot.dat | awk '{s=$14}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ASCPP " default_1plot.dat | awk '{s=$16}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AQPP " default_1plot.dat | awk '{s=$18}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat