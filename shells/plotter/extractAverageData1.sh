#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot.txt >> global.dat

grep "default_5.txt" ../../files/default_5.txtplot.txt >> global.dat

grep "default_6.txt" ../../files/default_6.txtplot.txt >> global.dat

grep "PPD " global.dat | awk '{s+=$4}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "PCN " global.dat | awk '{s+=$6}END{printf "%.4f %.4f\n", (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "PCA " global.dat | awk '{s+=$8}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "PSC " global.dat | awk '{s+=$10}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "EEO " global.dat | awk '{s+=$12}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "EEC " global.dat | awk '{s+=$14}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "EQO " global.dat | awk '{s+=$16}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "EQC " global.dat | awk '{s+=$18}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
