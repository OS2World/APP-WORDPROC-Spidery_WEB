##157:

#line 22 "cycle.web"

#line 23 "cycle.web"
NF==4&&$3=="-->"{
incoming[$4]+=1
if(incoming[$2]==""){
incoming[$2]=0
}
successors[$2]=successors[$2]" "$4
outgoing_edges[$2] = outgoing_edges[$2] $0 "\n"
next
}
!/^ *$/{
print"What's all this?",$0
exit 1
}
END{
##158:

#line 57 "cycle.web"

#line 58 "cycle.web"
for(node in incoming){
if(incoming[node]==0){
work[high++]=node
}
}

##:158

#line 38 "cycle.web"

n=0
while(n<high){
##159:

#line 64 "cycle.web"

#line 65 "cycle.web"
thisnode=work[n]
temp=successors[thisnode]
m=split(temp,newnodes," ")
for(j=1;j<=m;j++){
thisnode=newnodes[j]
incoming[thisnode]-=1
if(incoming[thisnode]==0){
work[high++]=thisnode
}
}

##:159

#line 42 "cycle.web"

n++
}
for(node in incoming){
if(incoming[node]!=0){
##160:

#line 76 "cycle.web"

#line 77 "cycle.web"
if(cycle==0){
print"There is a potential cycle here somewhere -- check the context"
cycle=1
}
printf "%s", outgoing_edges[node]
#line 2527 "/u/nr/web/src/master/spider.web"
##:160

#line 47 "cycle.web"

}
}
if(cycle==0){
print"There can't possibly be a cycle in the graph"
}else{
exit 0
}
}

##:157

