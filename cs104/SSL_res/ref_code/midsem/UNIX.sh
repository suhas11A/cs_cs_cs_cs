cat input.txt | grep -E "#" | cut -d "|" -f 4 | cut -d "#" -f 2 > temp_hashtags.txt
yes "#" | head -n `cat input.txt | grep -Ec "#"` > number.txt
paste number.txt temp_hashtags.txt -d "" > hashtags.txt
cat input.txt | grep -E "#" | cut -d "|" -f 3|cut -d "-" -f 2 > pop_counts.txt 
paste -d "," hashtags.txt pop_counts.txt > temp.txt
sort -t "," -nrk 2 temp.txt > output.txt
rm -f temp_hashtags.txt number.txt temp.txt