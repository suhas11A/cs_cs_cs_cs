# run the script via "ls | awk -f 01-example.awk

BEGIN { print "List of jpg files:" }
/\.jpg$/ { print }
END { print "All done!" }
