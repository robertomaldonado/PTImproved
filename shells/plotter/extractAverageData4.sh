#!/bin/sh

grep "default_2.txt" ../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../files/default_4.txtplot.txt >> global.dat

grep "default_5.txt" ../files/default_5.txtplot.txt >> global.dat

grep "default_6.txt" ../files/default_6.txtplot.txt >> global.dat

grep "OBS " global.dat | awk '{s+=$48}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "OAA " global.dat | awk '{s+=$50}END{printf "%.4f %.4f\n", (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "ONS " global.dat | awk '{s+=$52}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "ODS " global.dat | awk '{s+=$54}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "OHO " global.dat | awk '{s+=$56}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "ONP " global.dat | awk '{s+=$58}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "OVD " global.dat | awk '{s+=$60}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "OUS " global.dat | awk '{s+=$62}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
