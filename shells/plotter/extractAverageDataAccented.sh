#!/bin/sh

grep "default_2.txt" ../../files/default_2.txtplot_tildes.txt >> global.dat

grep "default_3.txt" ../../files/default_3.txtplot_tildes.txt >> global.dat

grep "default_4.txt" ../../files/default_4.txtplot_tildes.txt >> global.dat

grep "default_5.txt" ../../files/default_5.txtplot_tildes.txt >> global.dat

grep "default_6.txt" ../../files/default_6.txtplot_tildes.txt >> global.dat

grep "MAA " global.dat | awk '{s+=$4}END{printf "%.4f %.4f\n"  , (s/5), sqrt((s/5)*(s/5)/5)}' > estadisticaGlobal.dat
grep "MAE " global.dat | awk '{s+=$6}END{printf "%.4f %.4f\n", (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MAI " global.dat | awk '{s+=$8}END{printf "%.4f %.4f\n" , (s/5), sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MAO " global.dat | awk '{s+=$10}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MAU " global.dat | awk '{s+=$12}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MIA " global.dat | awk '{s+=$14}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MIE " global.dat | awk '{s+=$16}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MII " global.dat | awk '{s+=$18}END{printf "%.4f %.4f\n" , (s/5),sqrt((s/5)*(s/5)/5)}' >> estadisticaGlobal.dat
grep "MIO " global.dat | awk '{s=$20}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobal.dat
grep "MIU " global.dat | awk '{s=$22}END{printf "%.4f %.4f\n" , s, 0}' >> estadisticaGlobal.dat
