touch output.txt

a=0

while [ $a -lt 10 ]
do
    ./A 10
    ./A 20
    ./A 30
    ./A 40
    ./A 50
    ./driver 10 >> output.txt
    ./driver 20 >> output.txt
    ./driver 30 >> output.txt
    ./driver 40 >> output.txt
    ./driver 50 >> output.txt
    a=`expr $a + 1`
done