#! /bin/bash
echo "DELAY 2000" > script.ducky
echo "UP" >> script.ducky
head -n 10 rockyou.txt | xargs -I {} -n 1 echo STRING {} | awk ' {print;} NR % 1 == 0 { print "ENTER\nDELAY 100"; }' >> script.ducky
