BEGIN {
    FS=","
    OFS=","
}
{
    if (NR==1) {
        $0 = "Student ID,First Name,Middle Name,Last Name,Email-ID";
        print $0;
    }
    if (NR!=1) {
        $5=$2 $4 "@surveycorps.com"
        print $0;
    }
}