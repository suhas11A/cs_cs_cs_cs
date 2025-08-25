function valid_master(n) {
        if(n<NUM_MAS && n>=0) {
            for(i in exmas){
                if (n==exmas[i]) return 0;
            }
            return 1;
        }
        else return 0;
    }
    function valid_worker(n) {
        if(n<NUM_WOR && n>=0) {
            for(i in exwor) {
                if(n==exwor[i]) return 0;
            }
            return 1;
        }
        else return 0;
    }
    function arr_check(n,arr) {
        for(i in arr) {
            if(n==arr[i]) return 0;
        }
        return 1;
    }
BEGIN {
    buffer="";
    size=0;
    main=0;
    m=0;
    w=0;
    done=0;
}
{

    if($1=="Master" && arr_check($2,exmas)) {
        exmas[m]=$2;
        m++;
        print buffer;
        next;
    }
    else if ($1=="Worker" && arr_check($2,exwor)) {
        exwor[w]=$2;
        w++;
        print buffer;
        next;
    }

if ($1 == "Produced" && size <= BUF_SIZE && valid_master($5) && arr_check($2,buf)) {
    buf[main]=$2;
    main++;
    buffer=buffer $2 " ";
    size++;
}
else if ($1 == "Consumed" && size >0 && index(buffer,$2) && valid_worker($5)) {
    buf[main]=$2;
    main++;
    sub($2 " ","",buffer);
    size--;
}
else {
    done=1;
    }
print buffer;
}
END {
    if(done==0) {
    print "YES";
    }
    else print "NO";
}