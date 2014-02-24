/*4:*/
#line 88 "/u/nr/web/src/master/pathopen.web"

/*9:*/
#line 171 "/u/nr/web/src/master/pathopen.web"
#include<stdio.h>

/*:9*/
#line 89 "/u/nr/web/src/master/pathopen.web"


static int nextpath= 0;
static char pathtexts[1024];
static char*searchpath[64]= {pathtexts};
static char*maxpathtexts= pathtexts+1024;

void pathreset()
{
nextpath= 0;
searchpath[nextpath]= pathtexts;
}

/*:4*//*5:*/
#line 103 "/u/nr/web/src/master/pathopen.web"

void pathaddname(name)
char*name;
{char*t= searchpath[nextpath];
if(name==NULL)return;
if(nextpath>=64)overflow("paths");
while(*name){
if(t>=maxpathtexts)overflow("path texts");
*t++= *name++;
}
/*6:*/
#line 118 "/u/nr/web/src/master/pathopen.web"

#line 119 "/u/nr/web/src/master/pathopen.web"
if(t==searchpath[nextpath])nextpath--;
else if(t==searchpath[nextpath]+1&&
*searchpath[nextpath]=='/')
t--;

/*:6*/
#line 114 "/u/nr/web/src/master/pathopen.web"

searchpath[++nextpath]= t;
}

/*:5*//*7:*/
#line 125 "/u/nr/web/src/master/pathopen.web"

#line 126 "/u/nr/web/src/master/pathopen.web"
void pathaddpath(path,path_separator)
char*path;
char path_separator;
{
char*t= searchpath[nextpath];
if(path!=NULL){
while(*path){
if(nextpath>=64)overflow("paths");
while(*path!=path_separator&&*path!='\0'){
if(t>=maxpathtexts)overflow("path texts");
*t++= *path++;
}
/*6:*/
#line 118 "/u/nr/web/src/master/pathopen.web"

#line 119 "/u/nr/web/src/master/pathopen.web"
if(t==searchpath[nextpath])nextpath--;
else if(t==searchpath[nextpath]+1&&
*searchpath[nextpath]=='/')
t--;

/*:6*/
#line 138 "/u/nr/web/src/master/pathopen.web"

searchpath[++nextpath]= t;
if(*path)path++;
}
}
}

/*:7*//*8:*/
#line 151 "/u/nr/web/src/master/pathopen.web"

FILE*pathopen(name)
char*name;
{
FILE*fp;
char pathname[1024];
char*s,*t;
int i;

if((*(name)=='/'))
return fopen(name,"r");
else{
if((fp= fopen(name,"r"))!=NULL)return fp;
for(i= 0;i<nextpath;i++){
/*10:*/
#line 173 "/u/nr/web/src/master/pathopen.web"

#line 174 "/u/nr/web/src/master/pathopen.web"
for(s= pathname,t= searchpath[i];t<searchpath[i+1];){
*s++= *t++;
if(s>pathname+1024)overflow("path name length");
}
*s++= '/';
if(s>pathname+1024)overflow("path name length");
t= name;
while(*s++= *t++)
if(s>pathname+1024)overflow("path name length");
if((fp= fopen(pathname,"r"))!=NULL)return fp;


/*:10*/
#line 165 "/u/nr/web/src/master/pathopen.web"

}
}
return NULL;
}

/*:8*/
