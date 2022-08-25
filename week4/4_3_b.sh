#!/bin/bash
#Display the names of all files in the working directory which have 
#size greater than 0.
echo "Files having size greater than 0 are:"
 for name in `ls`
 do
	 if [ -s $name ]
	 then
		 echo $name
	 fi
 done
