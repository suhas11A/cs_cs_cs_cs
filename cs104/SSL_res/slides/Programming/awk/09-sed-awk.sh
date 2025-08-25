
#!/bin/bash

#combine sed and awk
sed 's/,/ /g' students.csv | awk '{print $2, $3}'
