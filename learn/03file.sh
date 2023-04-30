#!/bin/bash

echo -e "Enter your file name : \c"
read filename

#File Expression
##### -e For checking Is a file or a directory exist?
# if [ -e $filename ]
# then
# 	echo "$filename found"
# else
# 	echo "$filename not found"
# fi

##### -d For checking Is this argument a directory?
# if [ -d "$filename" ]
# then
# 	echo "$filename a is directory"
# else
# 	echo "$filename is not a directory"
# fi

##### -s For checking Is this file empty?
# if [ -s $filename ]
# then
# 	echo "$filename : this file not empty"
# else
# 	echo "$filename : this file are empty"
# fi

##### -f For checking Is this argument a file?
##### -r Check Is this file readable?
##### -w Check Is this file writable?
##### -x Check Is this file executable?
if [ -f $filename ]
then
	echo "$filename is a file"
	if [ -r $filename ]
	then
		echo "$filename : this file are readable"
	else
		echo "$filename : this file can't read"
	fi
	if [ -w $filename ]
	then
		echo "$filename : this file are writable"
	else
		echo "$filename : this file can't write"
	fi
	if [ -x $filename ]
	then
		echo "$filename : this file are executable"
	else
		echo "$filename : this file can't execute"
	fi
else
	echo "$filename is not a file"
fi

# can check 2 type of files
# -c :character file = textfile
# -b :block special file = vedio, image, music
