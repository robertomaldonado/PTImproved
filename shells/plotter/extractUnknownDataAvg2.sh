#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot_averages.txt > default_1plot.dat

grep "AMQPP " default_1plot.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "AWSPS " default_1plot.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AK1 " default_1plot.dat | awk '{s=$24}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AK2 " default_1plot.dat | awk '{s=$26}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AK3 " default_1plot.dat | awk '{s=$28}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "AWS " default_1plot.dat | awk '{s=$30}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ACAS " default_1plot.dat | awk '{s=$32}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "ACBS " default_1plot.dat | awk '{s=$34}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat