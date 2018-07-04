#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_numbers.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot_numbers.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot_numbers.txt >> global.dat

grep "default_5.txt" ../../files/default_5.txtplot_numbers.txt >> global.dat

grep "default_6.txt" ../../files/default_6.txtplot_numbers.txt >> global.dat

grep "ZERO " global.dat | awk '{s+=$4}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "ONE " global.dat | awk '{s+=$6}END{printf "%.4f %.4f\n", (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TWO " global.dat | awk '{s+=$8}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "THREE " global.dat | awk '{s+=$10}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "FOUR " global.dat | awk '{s+=$12}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "FIVE " global.dat | awk '{s+=$14}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "SIX " global.dat | awk '{s+=$16}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "SEVEN " global.dat | awk '{s+=$18}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "EIGTH " global.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobal.dat
grep "NINE " global.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobal.dat
