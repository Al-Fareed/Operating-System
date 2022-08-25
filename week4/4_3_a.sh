#!/bin/bash
#Count and display the number of ordinary files, hidden files and sub
#directories present in the working directory.
orfile=0
hidfile=0
dir=0
for file in `ls`
do
	echo $file
	if [ -f $file ]
	then 
		orfile=$(($file+1))
	elif [ -h $file ]
	then 
		hidfile=$(($hidfile+1))
	elif [ -d $file ]
	then
		dir=$(($dir+1))
	fi
done
echo number of ordinary files are: $orfile
echo number of hidden files are: $orfile
echo number of subdirectories are: $orfile
