cat /etc/passwd | sed s'/^\#//g' | sed -n '1~2p'|sed s'/\//\/\ /g'|sed s'/\(.*\)\///g'|rev| sort -r|sed s'/ //g'|tr "\n" ","|sed  s'/.$/\.\n/g'
