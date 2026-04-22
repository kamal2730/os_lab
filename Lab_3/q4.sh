echo "ENter the value for Basic and TA"

read b t

_bas=$(expr $b / 10)

result=$(expr $b + $t + $_bas)

echo ${result}
