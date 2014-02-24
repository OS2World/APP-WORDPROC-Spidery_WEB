##161:

#line 2529 "/u/nr/web/src/master/spider.web"

#line 2530 "/u/nr/web/src/master/spider.web"
{if($0==last){
print"Error: duplicate name",$0,"on lines",NR-1"-"NR
exit-1
}
last=$0
}
##:161

