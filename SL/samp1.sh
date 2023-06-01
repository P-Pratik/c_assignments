echo 'Enter the score'

read x

if [[ $x -eq 90 ]];
then
  echo “You have won the First Prize”

elif [[ $x -eq 60 ]];
then
  echo “You have won the Second Prize”

elif [[ $x -eq 30 ]];
then 
  echo “You have won the Second Prize”
else
  echo “Please try again”
fi
