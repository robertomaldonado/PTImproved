#!/bin/sh
filename=.temp3.data

echo "set terminal postscript eps enhanced solid color \"Courier\" 16" > $filename

echo "set output '../plots/vectorAcentos.eps';">> $filename

echo "set termoption dashed" >> $filename

echo "set style line 1 lt 1 lc 3 lw 3 " >> $filename # blue = lc 3
echo "set style line 2 lt 2 lc 5 lw 3 " >> $filename # red = lc 1

echo "set style histogram errorbars gap 1 lw 1 " >> $filename
echo "set style data histograms" >> $filename

echo "set xtics font \"Courier,16\"" >> $filename
echo "set xtics('MAA' 0 , 'MAE' 1, 'MAI' 2 , 'MAO' 3, 'MAU' 4, 'MIA' 5, 'MIE' 6 , 'MII' 7, 'MIO' 8, 'MIU' 9 ) font \"Courier,16\"" >> $filename
echo "set ytics font \"Courier,16\"" >> $filename

echo "set grid" >> $filename
echo "set boxwidth 0.90 relative" >> $filename

 echo "set style fill solid 1.0 noborder" >> $filename
 echo "set key width 1 height 1 box enhanced inside top right" >> $filename
 echo "set xlabel \"Parameters\" font \"Courier,18\"" >> $filename
 echo "set ylabel \"Repetition Index \" font \"Courier,18\"" >> $filename

echo "plot  'estadisticaGlobalIndiv1.dat' ls 1 title 'Unknown Author','estadisticaGlobal.dat' ls 2 title 'Known Author' " >> $filename

gnuplot $filename
rm -Rf $filename
