#!/bin/bash

# Define the output file; using capitals to avoid confusion with "file" which is a command in unix
FILE="output.txt"

# 1. Overwrite the file using cat <<EOF
cat <<EOF > "$FILE"
This is the first line.
This is the second line.
EOF

echo "==> Written using cat <<EOF"

# 2. Append more lines using cat <<EOF
cat <<EOF >> "$FILE"
This content is appended.
Appending another line.
EOF

echo "==> Appended using cat <<EOF"

# 3. Append using echo (you can also overwrite with >)
echo "This is an appended line using echo." >> "$FILE"
echo "Another appended line using echo." >> "$FILE"

echo "==> Appended using echo"

# 4. Append using printf
name="Sanjit"
score=92.3578
# Using echo (not formatted properly) to show the difference
echo "echo Format Column1" "Column2" "Column3" >> "$FILE"
echo "echo Format Name: $name, Score: $score" >> "$FILE"

echo "==> Formatting via echo"

# Using printf (formatted properly) 
#-10s: - means left-aligned, 10 is 10 characters, s is string output
printf "printf Name: %s, Score: %.2f\n" "$name" "$score" >> "$FILE"
printf "printf %-10s %-10s %-10s\n" "Column1" "Column2" "Column3" >> "$FILE"

echo "==> Formatting via printf"


# 5. Writing in a loop ( appends)
echo "Writing in a loop:" >> "$FILE"
while read -r line; do
    echo "$line" >> "$FILE"
done <<EOF
Loop Line 1
Loop Line 2
Loop Line 3
EOF

echo "==> Written using while loop"

