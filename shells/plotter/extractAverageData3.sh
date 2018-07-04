#!/bin/sh

grep "default_2.txt" ../files/default_2.txtplot.txt >> global.dat

grep "default_3.txt" ../files/default_3.txtplot.txt >> global.dat

grep "default_4.txt" ../files/default_4.txtplot.txt >> global.dat

grep "default_5.txt" ../files/default_5.txtplot.txt >> global.dat

grep "default_6.txt" ../files/default_6.txtplot.txt >> global.dat

grep "GPO " global.dat | awk '{s+=$36}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "GPC " global.dat | awk '{s+=$38}END{printf "%.4f %.4f\n", (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "GCO " global.dat | awk '{s+=$40}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "GCC " global.dat | awk '{s+=$42}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "GBO " global.dat | awk '{s+=$44}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "GBC " global.dat | awk '{s+=$46}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
