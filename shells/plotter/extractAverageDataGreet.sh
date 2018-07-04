#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_greeting.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot_greeting.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot_greeting.txt >> global.dat

grep "default_5.txt" ../../files/default_5.txtplot_greeting.txt >> global.dat

grep "default_6.txt" ../../files/default_6.txtplot_greeting.txt >> global.dat

grep "G1 " global.dat | awk '{s+=$4}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "G2 " global.dat | awk '{s+=$6}END{printf "%.4f %.4f\n",(s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "G3 " global.dat | awk '{s+=$8}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "G4 " global.dat | awk '{s+=$10}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "G5 " global.dat | awk '{s+=$12}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "G6 " global.dat | awk '{s+=$14}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "F1 " global.dat | awk '{s+=$16}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "F2 " global.dat | awk '{s+=$18}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "F3 " global.dat | awk '{s+=$20}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "F4 " global.dat | awk '{s+=$22}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "F5 " global.dat | awk '{s+=$24}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
