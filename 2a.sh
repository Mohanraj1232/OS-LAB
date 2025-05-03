echo "SUM OF FIRST N NUMBERS"
echo "Enter N"
read n
org_n=$n
sum=0
while((n>=0))
do
((sum=sum+n))
((n=n-1))
done 

echo "SUM of First $org_n Numbers Is $sum"