#!/bin/bash
###############################################################
#Variable : Don't have space between = sign because shell will read as argument instead.
var1="Hello"
var2='Mos'
var3='$var1 $var2'
var4="$var1 $var2 !"

echo "Hello"
echo $var3
echo $var4
###############################################################
#Array : Use {} sign to seperate index
text[0]=Ant
text[1]=Bird
text[2]=Cat
text[3]=Dog
fruit=(Apple Banana Carot Durian)

echo $text[1] $text[2] $text[3]
echo ${text[1]} ${text[2]} ${text[3]}
echo ${fruit[0]} ${fruit[1]} ${fruit[2]}
###############################################################
#Environment variable
echo '$0 filename:'$0 #filename
echo '$1 par 1:'$1 #argument 1
echo '$2 par 2:'$2 #argument 2
echo '$@ all par:'$@ #address (all argument)
echo '$# amount of par:'$# # amount of argument

echo Hello
echo '$? status code of last cmd:'$?

cmd1 Hello
echo '$? status code of last cmd:'$?

$shell hostname
$shell pwd

# echo $BASH
# echo $BASH_VERSION
# echo $HOME
# echo $PWD

# echo "Enter your name :"
# read name1 name2
# echo "Hello $name1!"

# read -p 'Username : ' user_name
# read -sp 'Password : ' pass_word
# echo
# echo "Your username is $user_name"
# echo "Your password is $pass_word"

# read -a names
# echo "name : "${names[0]}, ${names[1]}

# read
# echo "name :" $REPLY