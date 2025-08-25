# Write your commands here
# run with 'bash commands.sh' 
cat collect.txt | grep -E "[a-z]{1,}[0-9]{2} [1-4] (22b|23b)[0-9]{4}@iitb\.ac\.in submission.sh$" > valid.txt 
paste -d " " <(cat valid.txt | cut -d " " -f 1) <(cat valid.txt | cut -d " " -f 3 | cut -d "b" -f 2 | cut -d "@" -f 1) <(cat valid.txt | cut -d " " -f 3 | cut -d "@" -f 1) | sort -k2 | cut -d " " -f 1,3 > sorted.txt