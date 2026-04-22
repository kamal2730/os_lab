echo "Enter the value for a variable"
read v
echo "entered value : ${v}"

echo "value of next variable"
read x
res=$(expr $v + $x)
echo "${res}"
