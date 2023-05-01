#!/bin/bash
###############################################################
#Readonly
# var=31
# readonly var
# var=50
# echo $var
# hello() {
# 	echo "Hello World"
# }
# readonly -f hello
# hello() {
# 	echo "Hello World Again"
# }
# hello
#Use this command to print readonly variable
# readonly
###############################################################
#Signals & Traps
# Ctrl+c SIGINT : signal interrupt
# Ctrl+z suspend signal
# trap can't trap sigkill, sigstop
file=file.txt
touch $file
trap "echo Exit with interrupt signal" SIGKILL
trap "echo Exit with interrupt signal" SIGINT
trap "rm -f $file; exit" 0
echo "pid : $$"
while ((count < 2))
do
	sleep 4
	((count++))
	echo $count
done
exit 0
###############################################################
#Debug
# bash -x filename.sh (when you run the script)
# #!/bin/bash -x (Put -x in top after shebang)
# set -x (enable debug command)
# set -x (disable debug command)