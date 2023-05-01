#!/bin/bash
#Functions
###############################################################
# 2 way of create function
# function ft_hello(){
# 	echo -e "Hello \c" 
# }
# ft_world () {
# 	echo "World"
# }
# ft_hello #call the function ft_hello
# ft_world #call the function ft_world
###############################################################
#pass argument into function
# function ft_print() {
# 	echo $1 $2
# }
# ft_print Hello
# ft_print World
# ft_print me again
###############################################################
#Local variables
# function ft_print() {
# 	local name=$1
# 	echo "The name is $name : Function"
# }
# name="Mos"
# echo "The name is $name : Before"
# ft_print Prach
# echo "The name is $name : After"
###############################################################
#Function Return
usage() {
	echo "You need to provide an argument :"
}
function is_file_exitst() {
	local file="$1"
	[ -f "$file" ] && return 0 || return 1
}
[ $# -eq 0 ] && usage
if ( is_file_exitst "$1" )
then
	echo "File found"
else
	echo "File not found"
fi