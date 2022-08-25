echo "Enter range"
echo "Enter Upper limit:"
read n1
echo "Enter Lower limit:"
read n2
up=$n1
n1=$(($n1+1))
echo "The numbers are:"
until [ $n1 -eq $n2 ]
do
	echo $n1
	n1=$(($n1+1))
done
prod=1
up=$(($up+1))
while [ $up -le $n2 ]
do
	prod=$(($prod*$up))
	up=$(($up+1))
done
echo "Product is:" $prod
num=$prod
rev=0
while [ $num -ne 0 ]
do
	rem=$(($num%10))
	rev=$(($rev*10+$rem))
	num=$(($num/10))
done
echo "Reverse" $rev
if [ $rev -eq $prod ]
then
	echo $prod "The number is Palindrom"
else
	echo $prod "The number is not Palindrome"
fi


