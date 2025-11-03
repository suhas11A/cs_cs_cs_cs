touch teemmp.txt
find ./ | grep -E "*.out$" > teemmp.txt

while read line; do
    echo "$*">>$line
done < teemmp.txt

rm teemmp.txt