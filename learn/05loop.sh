#!/bin/bash
#Loop
###############################################################
# While loops
#n=1
# while [ $n -le 10 ]
# do
# 	echo "$n"
# 	# n=$((n + 1))
# 	((n++))
# 	sleep 0.2
# done
###############################################################
# Until loops : execute when condition is fault
# n=1
# until [ $n -ge 10 ]
# do
# 	echo "$n"
# 	((n++))
# done
###############################################################
# For loops
#for VAR in 1 2 3 4 5
#for VAR in {1..6}
# for VAR in {1..10..2} #{start..end..increament}
# do
# 	echo $VAR
# done
#OR------------------------------------
# for (( i = 0 ; i < 5; i++))
# do
# 	echo $i
# done
#OR------------------------------------
# for cmd in ls pwd date
# do
# 	echo "----------------$cmd----------------"
# 	$cmd #this line is execute the command
# done
#OR------------------------------------
# for item in *.sh
# do
# 	if [ -f $item ]
# 	then
# 		echo $item
# 	fi
# done
###############################################################
# Select loops : give numbered list and you can select
# Use in case of you have to select something
# select name in mos meaw mark mobile
# do
# 	case $name in
# 	mos)
# 		echo "$name selected"
# 		;;
# 	meaw)
# 		echo "$name selected"
# 		;;
# 	mark)
# 		echo "$name selected"
# 		;;
# 	mobile)
# 		echo "$name selected"
# 		;;
# 	*)
# 		echo "Error please provide the Number 1 - 4"
# 	esac
# done
###############################################################
# Break & Continue
for ((i = 1; i <= 10 ; i++))
do
	if [ $i -eq 2 ] || [ $i -eq 5 ]
	then
		continue
	fi
	if [ $i -gt 7 ]
	then
		break
	fi
	echo "$i"
done