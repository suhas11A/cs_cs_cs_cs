BEGIN {
    FS = ",";
    array["Net"]=0;
}

{   if (NR==1) {
        print $0;
    }
    if (NR!=1) {
        array[$3] += $4;
        array["Net"] += $4;
        print $0;
    }
}

END {
    print "====="
    print "Net : " array["Net"];
    delete array["Net"]
    n=asorti(array, sorted);
    for (i=1; i<=n; i++) {
        print sorted[i] " : " array[sorted[i]]
    }
}