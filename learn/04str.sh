#!/bin/bash

#####String Expression
#in shell you can = or == it's mean equal

echo -e "Enter your string : \c"
read str1

str2="hello"

# if [ $str1 ]
# then
# 	echo "string is not empty"
# else
# 	echo "string is empty"
# fi

# if [ -n $str1 ]
# then
# 	echo "str's length more than 0"
# fi

# if [ -z $str1 ]
# then
# 	echo "str's length equal 0"
# fi

# if [ $str1 ]
# then
# 	if [ $str1 = $str2 ]
# 	then
# 		echo "str1 is equal str2"
# 	elif [ $str1 != $str2 ]
# 	then
# 		echo "str1 is not equal str2"
# 	fi
# fi

#####Can compare string by use >, < with double square blanket [[]]
# if [[ $str1 > $str2 ]]
# then
# 	echo "Str1 > str2"
# elif [[ $str1 < $str2 ]]
# then
# 	echo "Str1 < str2"
# else
# 	echo "str1 = str2"
# fi

#####Double quote around variable
str2="hello world"
if [ "$str1" = "$str2" ]
then
	echo "it's equal"
fi
