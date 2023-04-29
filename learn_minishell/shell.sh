#!/bin/bash

#Variable : Don't have space between = sign because in shell you split argument
# var1="Afternoon"
# var2='Evening'
# var3='$var1 $var2'
# var4="$var1 Hello $var2"

# echo "Hello"
# echo $var3
# echo $var4

#Array : Use {} sign to seperate index
# text[0]=Ant
# text[1]=Bird
# text[2]=Cat
# text[3]=Dog
# fruit=(Apple Banana Carot Durian)

# echo $text[1] $text[2] $text[3]
# echo ${text[1]} ${text[2]} ${text[3]}
# echo ${fruit[0]} ${fruit[1]} ${fruit[2]}

#Environment variable

#Expression
num1=20
num2=20
num3=30

if [ $num1 -le $num2 ]
then
	echo "$num1 Equal $num2"
else
	echo "$num1 Not equal $num2"
fi

if [ $num1 -gt $num2 ]
then
	echo "$num1 Greater $num2"
elif [ $num1 -lt $num2 ]
then
	echo "$num1 less than $num2"
elif [ $num1 -ge $num2 ]
then
	echo "$num1 Greater or equal $num2"
fi