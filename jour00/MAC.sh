ifconfig -a | grep "eth0"|sed s'/  */@/g' |cut -d@ -f5 | sed s'/:/\n/g' 
