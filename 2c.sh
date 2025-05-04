echo "FACTORIAL OF A NUMBER"
echo "ENTER N"
read n
org_n=$n
fact=1
while((n>0))
do
    ((fact*=n))
    ((n-=1))
done
echo "$org_n!=$fact"