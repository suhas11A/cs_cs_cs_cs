#!/bin/bash

awk '
BEGIN {
    print "Loop Demonstrations:\n";

    # while loop
    i = 1;
    while (i <= 5) {
        print "While Loop Iteration:", i;
        i++;
    }
    print "";

    # do-while loop
    j = 5;
    do {
        print "Do-While Loop Iteration:", j;
        j--;
    } while (j > 0);
    print "";

    # for loop
    for (k = 1; k <= 5; k++) {
        print "For Loop Iteration:", k;
    }
    print "";

    # break and continue example
    for (m = 1; m <= 5; m++) {
        if (m == 3) {
            print "Skipping iteration", m, "using continue";
            continue;
        }
        if (m == 5) {
            print "Breaking loop at", m;
            break;
        }
        print "For Loop Iteration:", m;
    }
    print "";

    print "End of loop demonstrations.";
}'
