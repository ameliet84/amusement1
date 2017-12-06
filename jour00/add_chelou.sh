
echo "$FT_NBRE1 + $FT_NBR2"|tr "mrdoc" "01234"|sed  "s/'/0/"|sed 's/\\/1/'|sed 's/"/3/'|sed 's/\?/4/'|sed 's/!/5/'|bc
