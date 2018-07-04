#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_totales.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot_totales.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot_totales.txt >> global.dat

grep "default_5.txt" ../../files/default_5.txtplot_totales.txt >> global.dat

grep "default_6.txt" ../../files/default_6.txtplot_totales.txt >> global.dat

grep "TUS " global.dat | awk '{s+=$4}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "TLS " global.dat | awk '{s+=$6}END{printf "%.4f %.4f\n",(s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TNW " global.dat | awk '{s+=$8}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TNS " global.dat | awk '{s+=$10}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TNP " global.dat | awk '{s+=$12}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TNT " global.dat | awk '{s+=$14}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "TNWS " global.dat | awk '{s+=$16}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
