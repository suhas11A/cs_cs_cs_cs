tar -xvf files.tar.gz
find ./bigdirectory/ | grep -E "file_[0-9]{4}\.txt$" > ./1.txt
find ./bigdirectory/ | grep -E ".*\.log$" > ./2.txt
find ./bigdirectory/ -perm 777 > ./3.txt
find -type f ./bigdirectory/ -mtime 0 > ./4.txt
find -type f ./bigdirectory/ -size +100c -mtime +7 > ./5.txt