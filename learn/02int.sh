#!/bin/bash
#Arithmetic
###############################################################
#Can use arithmetic in double parenthesis(())
num1=10
num2=5
# echo "num1 + num2 = "$((num1 + num2))
# echo "num1 - num2 = "$((num1 - num2))
# echo "num1 * num2 = "$((num1 * num2))
# echo "num1 / num2 = "$((num1 / num2))
# echo "num1 % num2 = "$((num1 % num2))
#####expr: syntax (have to use \* on * to escape)
# echo "num1 + num2 = "$(expr $num1 + $num2)
# echo "num1 - num2 = "$(expr $num1 - $num2)
# echo "num1 * num2 = "$(expr $num1 \* $num2)
# echo "num1 / num2 = "$(expr $num1 / $num2)
# echo "num1 % num2 = "$(expr $num1 % $num2)

# echo 'total: '$total
###############################################################
#Expression
# -a AND &&
# -o OR ||
num=$((num1 + num2))
echo "num = $num"

if [ $num -ge 0 -a $num -le 100 ]
# if [ $num -gt 0 ] && [ $num -le 100 ]
# if [[ $num -gt 0 && $num -le 100 ]]
then
	if [ $num -gt 50 ]
	then
		if (($num > 90))
		then
			echo "Number is in Range 90"
		elif (($num > 80))
		then
			echo "Number is in Range 80"
		elif (($num > 70))
		then
			echo "Number is in Range 70"
		elif (($num > 60))
		then
			echo "Number is in Range 60"
		elif (($num > 50))
		then
			echo "Number is in Range 50"
		fi
	else
		if (($num > 40))
		then
			echo "Number is in Range 40"
		elif (($num > 30))
		then
			echo "Number is in Range 30"
		elif (($num > 20))
		then
			echo "Number is in Range 20"
		elif (($num > 10))
		then
			echo "Number is in Range 10"
		else
			echo "Number is in Range 0"
		fi
	fi
fi

###############################################################
# bc : basic calculation command

num1=20.5
num2=5

echo "$num1+$num2" | bc
echo "20.5-5" | bc
echo "20.5*5" | bc
echo "scale=2;20.5/5" | bc
echo "20.5%5" | bc

echo "scale=2;sqrt(9)" | bc -l
echo "scale=2;3^3" | bc -l