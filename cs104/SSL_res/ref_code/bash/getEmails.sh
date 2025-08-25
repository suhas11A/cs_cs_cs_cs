#!/bin/bash

if (($#!=1)); then 
    echo "Usage: ./getEmails.sh <valid_file.txt>"
    exit 0
fi

if !(ls $1 &>/dev/null); then
    echo "Usage: ./getEmails.sh <valid_file.txt>"
    exit 0
fi

touch emails.txt sortedEmails.txt cseEmails.txt

while read -r line; do
    if [[ "$line" =~ [a-zA-Z0-9]{1,}@[a-zA-Z]{1,}\.iitb\.ac\.in ]]; then
        echo "$line">>emails.txt
    fi
done < "$1"

sort -fr emails.txt>sortedEmails.txt

while read -r line; do
    if [[ "$line" =~ [a-zA-Z0-9]{1,}@cse\.iitb\.ac\.in ]]; then
        echo "$line">>cseEmails.txt
    fi
done < sortedEmails.txt