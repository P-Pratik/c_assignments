function find_sum()
{
    SUM=`expr $1 + $2`
    echo $SUM
}


find_sum 10 20

RESULT=`find_sum 100 200`
echo $RESULT
