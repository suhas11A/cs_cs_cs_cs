mkdir ./secured_logs
cp `find ./vought_logs/| grep -E "*.txt"` ./secured_logs/
find ./ | grep `ls -Slh ./secured_logs/ | head -n 2 | tail -n 1 | cut -d " " -f 9` | grep -E "^\./vought_logs/" > biggest_secret.txt