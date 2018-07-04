#!/bin/sh

grep "default_1.txt" ../../files/default_1.txtplot.txt > default_1plot.dat

grep "GPO " default_1plot.dat | awk '{s=$36}END{printf "%.4f %.4f\n" , s, 0}' > estadisticaGlobalIndiv1.dat
grep "GPC " default_1plot.dat | awk '{s=$38}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "GCO " default_1plot.dat | awk '{s=$40}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat
grep "GCC " default_1plot.dat | awk '{s=$42}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "GBO " default_1plot.dat | awk '{s=$44}END{printf "%.4f %.4f\n", s, 0}' >> estadisticaGlobalIndiv1.dat
grep "GBC " default_1plot.dat | awk '{s=$46}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobalIndiv1.dat