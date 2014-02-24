##162:

#line 2537 "/u/nr/web/src/master/spider.web"

#line 2538 "/u/nr/web/src/master/spider.web"
/^good translations$/,/^test translations$/{
if($0!~/^good translations$|^test translations$/){
istranslation[$0]=1
}
next
}

{if(istranslation[$0]!=1){
print"Error:",$0,"is not a valid translation"
exitcode=-1
}
}

END{
exit exitcode
}
##:162

