/*1:*/
#line 44 "tangle.web"

/*4:*/
#line 15 "common.h"

#line 16 "common.h"
#include<stdio.h>

/*:4*//*93:*/
#line 1046 "tangle.web"

#line 1047 "tangle.web"
#include"ctype.h"

/*:93*/
#line 45 "tangle.web"

/*3:*/
#line 9 "common.h"

typedef short boolean;
typedef char unsigned eight_bits;
extern boolean program;
extern int phase;

/*:3*//*5:*/
#line 24 "common.h"

typedef char ASCII;
typedef char outer_char;
extern ASCII xord[];
extern outer_char xchr[];
ASCII mod_text[400+1];
ASCII *mod_text_end= mod_text+400;
ASCII *id_first;
ASCII *id_loc;

/*:5*//*6:*/
#line 37 "common.h"

#line 38 "common.h"
extern ASCII buffer[];
extern ASCII *buffer_end;
extern ASCII *loc;
extern ASCII *limit;

/*:6*//*7:*/
#line 55 "common.h"

typedef struct name_info{
ASCII *byte_start;
struct name_info *link;
union{
struct name_info *Rlink;

eight_bits Ilk;

}dummy;
ASCII *equiv_or_xref;
}name_info;
typedef name_info *name_pointer;
typedef name_pointer *hash_pointer;
extern ASCII byte_mem[];
extern ASCII *byte_mem_end;
extern name_info name_dir[];
extern name_pointer name_dir_end;
extern name_pointer name_ptr;
extern ASCII *byte_ptr;
extern name_pointer hash[];
extern hash_pointer hash_end;
extern hash_pointer h;
extern name_pointer id_lookup();
extern name_pointer mod_lookup();
extern name_pointer prefix_lookup();

/*:7*//*8:*/
#line 98 "common.h"

extern history;

/*:8*//*9:*/
#line 109 "common.h"

extern include_depth;
extern FILE *file[];
extern FILE *change_file;
extern char C_file_name[];
extern char tex_file_name[];
extern char file_name[][60];

extern char change_file_name[];
extern line[];
extern change_line;
extern boolean input_has_ended;
extern boolean changing;

/*:9*//*10:*/
#line 124 "common.h"

#line 125 "common.h"
typedef unsigned short sixteen_bits;
extern sixteen_bits module_count;
extern boolean changed_module[];
extern boolean print_where;

/*:10*//*11:*/
#line 131 "common.h"

#line 132 "common.h"
extern int argc;
extern char * *argv;
extern no_xref;

/*:11*//*12:*/
#line 144 "common.h"

FILE *C_file;
FILE *tex_file;
#line 81 "tangle.web"

/*:12*/
#line 46 "tangle.web"

/*14:*/
#line 107 "tangle.web"

#line 108 "tangle.web"
typedef struct{
eight_bits *tok_start;
sixteen_bits text_link;
}text;
typedef text *text_pointer;

/*:14*//*25:*/
#line 254 "tangle.web"

#line 255 "tangle.web"
typedef struct{
eight_bits *end_field;
eight_bits *byte_field;
name_pointer name_field;
text_pointer repl_field;
sixteen_bits mod_field;
}output_state;
typedef output_state *stack_pointer;

/*:25*/
#line 47 "tangle.web"

/*15:*/
#line 114 "tangle.web"

#line 115 "tangle.web"
text text_info[2000];
text_pointer text_info_end= text_info+2000-1;
text_pointer text_ptr;
eight_bits tok_mem[150000];
eight_bits *tok_mem_end= tok_mem+150000-1;
eight_bits *tok_ptr;

/*:15*//*21:*/
#line 185 "tangle.web"

text_pointer last_unnamed;

/*:21*//*26:*/
#line 270 "tangle.web"

output_state cur_state;

output_state stack[50+1];
stack_pointer stack_ptr;
stack_pointer stack_end= stack+50;

/*:26*//*37:*/
#line 413 "tangle.web"

int cur_val;


/*:37*//*46:*/
#line 520 "tangle.web"

#line 521 "tangle.web"
short balances[128];
/*:46*//*50:*/
#line 583 "tangle.web"

#line 584 "tangle.web"
name_pointer parm_ptr;

/*:50*//*62:*/
#line 706 "tangle.web"

eight_bits out_state;
boolean protect;

/*:62*//*64:*/
#line 735 "tangle.web"

name_pointer output_files[256];
name_pointer *cur_out_file, *end_output_files, *an_output_file;
char cur_module_char;
char output_file_name[400];

/*:64*//*77:*/
#line 142 "outtoks.web"
char C_file_extension[]= "c";
/*:77*//*79:*/
#line 147 "outtoks.web"
char the_at_sign= 64;

/*:79*//*85:*/
#line 943 "tangle.web"

eight_bits ccode[128];

/*:85*//*87:*/
#line 975 "tangle.web"
short tracing;
#line 976 "tangle.web"
/*:87*//*90:*/
#line 1009 "tangle.web"

#line 1010 "tangle.web"
boolean comment_continues= 0;

/*:90*//*92:*/
#line 1043 "tangle.web"

name_pointer cur_module;

/*:92*//*107:*/
#line 1310 "tangle.web"

text_pointer cur_text;
eight_bits next_control;

/*:107*//*110:*/
#line 1373 "tangle.web"

ASCII param_name_texts[256];
ASCII *param_name_texts_end= param_name_texts+256;
ASCII *param_names[32];
short next_param_name;
ASCII *next_param_name_text;

/*:110*//*131:*/
#line 1693 "tangle.web"

#line 1694 "tangle.web"
extern sixteen_bits module_count;

/*:131*/
#line 48 "tangle.web"


main(ac,av)
char * *av;
{
argc= ac;argv= av;
program= 0;
/*16:*/
#line 122 "tangle.web"

#line 123 "tangle.web"
text_info->tok_start= tok_ptr= tok_mem;
text_ptr= text_info+1;text_ptr->tok_start= tok_mem;


/*:16*//*18:*/
#line 132 "tangle.web"

name_dir->equiv_or_xref= (ASCII *)text_info;

/*:18*//*22:*/
#line 188 "tangle.web"
last_unnamed= text_info;text_info->text_link= 0;
#line 189 "tangle.web"

/*:22*//*47:*/
#line 522 "tangle.web"

#line 523 "tangle.web"
{int i;
for(i= 0;i<128;i++)balances[i]= 0;
/*48:*/
#line 529 "tangle.web"

#line 530 "tangle.web"
balances[40]= 1;
balances[41]= -1;
balances[91]= 1;
balances[93]= -1;
balances[123]= 1;
balances[125]= -1;

/*:48*/
#line 525 "tangle.web"
;
}
/*:47*//*65:*/
#line 745 "tangle.web"

#line 746 "tangle.web"
cur_out_file= end_output_files= output_files+256;

/*:65*//*86:*/
#line 946 "tangle.web"
{
#line 947 "tangle.web"
int c;
for(c= 0;c<=127;c++)ccode[c]= 0;
ccode[' ']= ccode[011]= ccode['*']= 255;
ccode['@']= '@';
ccode['=']= 2;
ccode['d']= ccode['D']= 252;
ccode['f']= ccode['F']= 251;
ccode['c']= ccode['C']= 253;
ccode['u']= ccode['U']= 253;
ccode['^']= ccode[':']= ccode['.']= ccode['t']= ccode['T']= 250;
ccode['&']= 127;
ccode['<']= ccode['(']= 254;
ccode['`']= 249;
ccode['\'']= 5;
ccode['"']= 6;



ccode['@']= ccode[64];
ccode[64]= 64;

#ifdef DEBUG
ccode['0']= ccode['1']= ccode['2']= ccode['3']= ccode['4']= 248;
#endif DEBUG

}

/*:86*//*88:*/
#line 976 "tangle.web"
tracing= 0;
#line 977 "tangle.web"

/*:88*//*103:*/
#line 1239 "tangle.web"
mod_text[0]= ' ';
#line 1240 "tangle.web"

/*:103*//*112:*/
#line 1385 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1385 "tangle.web"
;
#line 1386 "tangle.web"

/*:112*/
#line 55 "tangle.web"
;
common_init();
printf("This is C TANGLE (generated at 3:23 PM on January 16, 1991)\n");
phase_one();
phase_two();
wrap_up();
}

/*:1*//*19:*/
#line 138 "tangle.web"

#line 139 "tangle.web"
names_match(p,first,l)
name_pointer p;
ASCII *first;
int l;
{
if(((p+1)->byte_start-(p)->byte_start)!=l)return 0;
return!strncmp(first,p->byte_start,l);
}

/*:19*//*20:*/
#line 149 "tangle.web"

#line 150 "tangle.web"
init_node(node)
name_pointer node;
{
node->equiv_or_xref= (ASCII *)text_info;

}
init_p(p,t)
name_pointer p;
eight_bits t;
{
p->dummy.Ilk= t;
}



/*:20*//*24:*/
#line 219 "tangle.web"
store_two_bytes(x)
sixteen_bits x;
{
if(tok_ptr+2>tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};};
 *tok_ptr++= x>>8;
 *tok_ptr++= x&255;
}


/*:24*//*28:*/
#line 294 "tangle.web"
push_level(p)
#line 295 "tangle.web"
name_pointer p;
{
/*29:*/
#line 306 "tangle.web"

#line 307 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>0){
printf("\nPushing ");fflush(stdout),write(1,(p)->byte_start,(((p)+1)->byte_start-((p))->byte_start));
printf(" =nd[%d]",p-name_dir);
}
#endif TRACE_MACROS

/*:29*/
#line 297 "tangle.web"
;
if(stack_ptr==stack_end){{printf("\n! Sorry, capacity exceeded: ");err_print("stack");history= 3;wrap_up();};};
 *stack_ptr= cur_state;
stack_ptr++;
cur_state.name_field= p;cur_state.repl_field= (text_pointer)p->equiv_or_xref;
cur_state.byte_field= cur_state.repl_field->tok_start;cur_state.end_field= (cur_state.repl_field+1)->tok_start;
cur_state.mod_field= 0;
}

/*:28*//*30:*/
#line 321 "tangle.web"
pop_level()
#line 322 "tangle.web"
{int number_of_parameters;
/*33:*/
#line 363 "tangle.web"

#line 364 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>0){
printf("\nPopping ");fflush(stdout),write(1,(cur_state.name_field)->byte_start,(((cur_state.name_field)+1)->byte_start-((cur_state.name_field))->byte_start));
printf(" =nd[%d]",cur_state.name_field-name_dir);
}

#endif TRACE_MACROS



/*:33*/
#line 323 "tangle.web"
;
if(cur_state.repl_field->text_link==0){
if(cur_state.name_field->dummy.Ilk==1){
/*31:*/
#line 338 "tangle.web"

#line 339 "tangle.web"
number_of_parameters=  *(cur_state.repl_field->tok_start);
/*32:*/
#line 357 "tangle.web"

#line 358 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>1){
printf("\nUnstacking %d parameters",number_of_parameters);
}
#endif TRACE_MACROS
/*:32*/
#line 340 "tangle.web"
;
while(number_of_parameters-->0){
name_ptr--;text_ptr--;
#ifdef TRACE_MACROS
byte_ptr-= 2;
#endif TRACE_MACROS
}
#ifdef STAT
#ifdef STAT_HAS_BEEN_FIXED
if(tok_ptr>max_tok_ptr)max_tok_ptr= tok_ptr;


#endif STAT_HAS_BEEN_FIXED
#endif STAT
tok_ptr= text_ptr->tok_start;


/*:31*/
#line 326 "tangle.web"
;
}
}else if(cur_state.repl_field->text_link<2000){
cur_state.repl_field= cur_state.repl_field->text_link+text_info;
cur_state.byte_field= cur_state.repl_field->tok_start;cur_state.end_field= (cur_state.repl_field+1)->tok_start;
return;
}
stack_ptr--;
if(stack_ptr>stack)cur_state=  *stack_ptr;
}


/*:30*//*38:*/
#line 418 "tangle.web"
sixteen_bits
#line 419 "tangle.web"
 get_output()
{
sixteen_bits a;
restart:if(stack_ptr==stack)return 0;
if(cur_state.byte_field==cur_state.end_field){
cur_val= -((int)cur_state.mod_field);
pop_level();
if(cur_val==0)goto restart;
out_char(129);return;
}
a=  *cur_state.byte_field++;
if(a<128)
if(a==7){
/*40:*/
#line 454 "tangle.web"

#line 455 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf(" [#%d]", *cur_state.byte_field);
}
#endif TRACE_MACROS

/*:40*/
#line 432 "tangle.web"
;
/*39:*/
#line 452 "tangle.web"

#line 453 "tangle.web"
push_level(name_ptr- *cur_state.byte_field++);goto restart;
/*:39*/
#line 434 "tangle.web"
;
}else
out_char(a);
else{
a= (a-128) *256+ *cur_state.byte_field++;
switch(a/10240){
case 0:
/*41:*/
#line 461 "tangle.web"

#line 462 "tangle.web"
if(name_dir[a].dummy.Ilk==1){
/*42:*/
#line 475 "tangle.web"

#line 476 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf("\nExpanding macro (");fflush(stdout),write(1,(name_dir+a)->byte_start,(((name_dir+a)+1)->byte_start-((name_dir+a))->byte_start));
printf("=nd[%d])",a);
}
#endif TRACE_MACROS

/*:42*/
#line 463 "tangle.web"
;
/*44:*/
#line 492 "tangle.web"

#line 493 "tangle.web"
{int number_of_parameters;
while(cur_state.byte_field==cur_state.end_field&&stack_ptr>stack)pop_level();
number_of_parameters=  *(((text_pointer)name_dir[a].equiv_or_xref)->tok_start);
if(number_of_parameters>0){
if(stack_ptr==stack|| *cur_state.byte_field!=40){
printf("\n! No parameters given for ");
fflush(stdout),write(1,(a+name_dir)->byte_start,(((a+name_dir)+1)->byte_start-((a+name_dir))->byte_start));
err_print("");
goto restart;
}
cur_state.byte_field++;
parm_ptr= name_ptr;
while(number_of_parameters-->0){
/*49:*/
#line 537 "tangle.web"

#line 538 "tangle.web"
{int bal;
eight_bits b,oldb;
sixteen_bits c;
bal= 0;
/*59:*/
#line 647 "tangle.web"

#line 648 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf("\nScanning #%d...",number_of_parameters+1);
}
#endif TRACE_MACROS
/*:59*/
#line 542 "tangle.web"
;
while(1){
b=  *cur_state.byte_field++;
if(b==7){
b=  *cur_state.byte_field++;
/*56:*/
#line 613 "tangle.web"

#line 614 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf(" <#%d=",b);fflush(stdout),write(1,(name_ptr-b)->byte_start,(((name_ptr-b)+1)->byte_start-((name_ptr-b))->byte_start));printf("=nd[%d]>",
name_ptr-b-name_dir);
}
#endif TRACE_MACROS

/*:56*/
#line 547 "tangle.web"
;
c= name_ptr-name_dir-b;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 128+(c/256);};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= c%256;};
}else{
if(b>=128){
/*57:*/
#line 621 "tangle.web"

#line 622 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
int c;
printf(" <");
c= (b-128) *256+ *cur_state.byte_field;
switch(c/10240){
case 0:fflush(stdout),write(1,(name_dir+c)->byte_start,(((name_dir+c)+1)->byte_start-((name_dir+c))->byte_start));
printf(" =nd[%d]",c);
break;
case 1:printf("MODULE");break;
default:printf("CONTEXT");break;
}
printf(">");
}
#endif TRACE_MACROS

/*:57*/
#line 553 "tangle.web"
;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= b;};
b=  *cur_state.byte_field++;
}else if(bal==0&&((number_of_parameters==0&&b==41)
||(number_of_parameters>0&&b==44))){
goto done;
}else if(/*51:*/
#line 586 "tangle.web"
(b==2||b==3)
#line 587 "tangle.web"
/*:51*/
#line 559 "tangle.web"
){
/*52:*/
#line 587 "tangle.web"

#line 588 "tangle.web"
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= b;};
oldb= b;
/*53:*/
#line 601 "tangle.web"

#line 602 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2)printf(" <");
#endif TRACE_MACROS
/*:53*/
#line 590 "tangle.web"
;
while((b=  *cur_state.byte_field++)!=oldb){
/*54:*/
#line 605 "tangle.web"

#line 606 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2)printf("%c",b);
#endif TRACE_MACROS
/*:54*/
#line 592 "tangle.web"
;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= b;};
if(cur_state.byte_field>=cur_state.end_field)
{printf("\n! This can't happen: ");err_print("string or constant didn't end in token list");history= 3;wrap_up();};
}
/*55:*/
#line 609 "tangle.web"

#line 610 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2)printf(">");
#endif TRACE_MACROS
/*:55*/
#line 597 "tangle.web"
;



/*:52*/
#line 560 "tangle.web"
;
}else{
/*58:*/
#line 638 "tangle.web"

#line 639 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf(" <");
if(31<b&&b<127)printf("%c",b);
printf(">");
}
#endif TRACE_MACROS

/*:58*/
#line 562 "tangle.web"
;
bal+= balances[b];
}
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= b;};
}
}
done:
parm_ptr->equiv_or_xref= (ASCII *)text_ptr;
text_ptr->text_link= 0;
parm_ptr->dummy.Ilk= 2;
#ifdef TRACE_MACROS
if(byte_ptr+2>=byte_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("byte memory");history= 3;wrap_up();};};
 *byte_ptr++= 35; *byte_ptr++= number_of_parameters+1+48;
#endif TRACE_MACROS
if(parm_ptr>=name_dir_end){{printf("\n! Sorry, capacity exceeded: ");err_print("name");history= 3;wrap_up();};};
(++parm_ptr)->byte_start= byte_ptr;
if(text_ptr>=text_info_end){{printf("\n! Sorry, capacity exceeded: ");err_print("text");history= 3;wrap_up();};};
(++text_ptr)->tok_start= tok_ptr;
/*60:*/
#line 653 "tangle.web"

#line 654 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>1){
printf("\nStacked ");fflush(stdout),write(1,(parm_ptr-1)->byte_start,(((parm_ptr-1)+1)->byte_start-((parm_ptr-1))->byte_start));
printf("=nd[%d]",parm_ptr-1-name_dir);
}
#endif TRACE_MACROS

/*:60*/
#line 580 "tangle.web"
;
}

/*:49*/
#line 507 "tangle.web"
;
}
name_ptr= parm_ptr;

}
}

/*:44*/
#line 465 "tangle.web"
;
push_level(name_dir+a);
cur_state.byte_field++;
goto restart;
}else if(name_dir[a].dummy.Ilk==2){
/*43:*/
#line 483 "tangle.web"

#line 484 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf("\nExpanding parameter (");fflush(stdout),write(1,(name_dir+a)->byte_start,(((name_dir+a)+1)->byte_start-((name_dir+a))->byte_start));
printf("=nd[%d])",a);
}
#endif TRACE_MACROS


/*:43*/
#line 470 "tangle.web"
;
push_level(name_dir+a);
goto restart;
}

/*:41*/
#line 441 "tangle.web"
;
cur_val= a;out_char(130);break;
case 1:/*61:*/
#line 664 "tangle.web"

#line 665 "tangle.web"
a-= 10240;
if((a+name_dir)->equiv_or_xref!=(ASCII *)text_info)push_level(a+name_dir);
else if(a!=0){
printf("\n! Not present: <");fflush(stdout),write(1,(a+name_dir)->byte_start,(((a+name_dir)+1)->byte_start-((a+name_dir))->byte_start));err_print(">");

}
goto restart;

/*:61*/
#line 443 "tangle.web"
;
default:cur_val= a-20480;if(cur_val>0)cur_state.mod_field= cur_val;
out_char(129);
}
}
return 1;
}


/*:38*//*63:*/
#line 714 "tangle.web"
flush_buffer()
#line 715 "tangle.web"
{
putc('\n',C_file);
if(line[include_depth]%100==0){
printf(".");
if(line[include_depth]%500==0)printf("%d",line[include_depth]);
fflush(stdout);
}
line[include_depth]++;
}

/*:63*//*67:*/
#line 764 "tangle.web"

#line 765 "tangle.web"
phase_two(){
line[include_depth]= 1;
if(text_info->text_link==0){
if(end_output_files==cur_out_file){
printf("\n! No program text was specified.");{if(history==0)history= 1;};

}
}else{
printf("\nWriting the output files: (%s)",C_file_name);fflush(stdout);
/*27:*/
#line 283 "tangle.web"

#line 284 "tangle.web"
stack_ptr= stack+1;cur_state.name_field= name_dir;cur_state.repl_field= text_info->text_link+text_info;
cur_state.byte_field= cur_state.repl_field->tok_start;cur_state.end_field= (cur_state.repl_field+1)->tok_start;cur_state.mod_field= 0;

/*:27*/
#line 774 "tangle.web"
;
while(stack_ptr>stack)get_output();
flush_buffer();
}
if(end_output_files>cur_out_file){
if(text_info->text_link==0){
printf("\nWriting the output files: ");fflush(stdout);
}
/*68:*/
#line 790 "tangle.web"

#line 791 "tangle.web"
for(an_output_file= end_output_files;an_output_file>cur_out_file;){
an_output_file--;
strncpy(output_file_name,( *an_output_file)->byte_start,400);
output_file_name[(( *an_output_file+1)->byte_start-( *an_output_file)->byte_start)]= '\0';
fclose(C_file);
C_file= fopen(output_file_name,"w");
if(C_file<=0){
{printf("! Cannot open output file:");err_print(output_file_name);history= 3;wrap_up();}
}else{
printf(" (%s)",output_file_name);fflush(stdout);
}
stack_ptr= stack+1;
cur_state.name_field= ( *an_output_file);
cur_state.repl_field= (text_pointer)cur_state.name_field->equiv_or_xref;
cur_state.byte_field= cur_state.repl_field->tok_start;
cur_state.end_field= (cur_state.repl_field+1)->tok_start;
cur_state.mod_field= 0;
while(stack_ptr>stack)get_output();
flush_buffer();
}



/*:68*/
#line 782 "tangle.web"

}
printf("\nDone.");
}

/*:67*//*69:*/
#line 816 "tangle.web"
out_char(cur_char)
#line 817 "tangle.web"
eight_bits cur_char;
{
ASCII *j;
/*70:*/
#line 841 "tangle.web"

#line 842 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
switch(cur_char){
case 10:printf(" [\\n]");break;
case 2:
printf("[STRING]");break;
case 127:
printf("[JOIN]");break;
case 3:
printf("[CONSTANT]");break;
case 130:
printf(" [");fflush(stdout),write(1,(cur_val+name_dir)->byte_start,(((cur_val+name_dir)+1)->byte_start-((cur_val+name_dir))->byte_start));printf("]");
break;
case 129:
if(cur_val>0){
printf(" [%d:]",cur_val);
}else if(cur_val<0){
printf(" [:%d]",-cur_val);
}else{
printf("[LINE NUMBER]");
}
break;

default:
if(31<cur_char&&cur_char<127){
printf(" [%c]",cur_char);
}else{
printf(" [\\%3o]",cur_char);
}
}
}
#endif TRACE_MACROS




/*:70*/
#line 820 "tangle.web"
;
switch(cur_char){
case 10:if(protect)putc(' ',C_file);
if(protect||out_state==4)putc('\\',C_file);

flush_buffer();if(out_state!=4)out_state= 0;break;
/*71:*/
#line 878 "tangle.web"

#line 879 "tangle.web"
case 130:
if(out_state==1)putc(' ',C_file);
for(j= (cur_val+name_dir)->byte_start;j<(name_dir+cur_val+1)->byte_start;
j++)putc( *j,C_file);
out_state= 1;break;

/*:71*/
#line 826 "tangle.web"
;
/*72:*/
#line 885 "tangle.web"

#line 886 "tangle.web"
case 129:
if(cur_val>0){
fprintf(C_file,"%s","/*");
fprintf(C_file,"%d:",cur_val);
fprintf(C_file,"%s","*/");
}else if(cur_val<0){
fprintf(C_file,"%s","/*");
fprintf(C_file,":%d",-cur_val);
fprintf(C_file,"%s","*/");
}else{
sixteen_bits a;
a= 256 * *cur_state.byte_field++;
a+=  *cur_state.byte_field++;
fprintf(C_file,"\n%s","#line");
fprintf(C_file," %d \"",a);
cur_val=  *cur_state.byte_field++;
cur_val= 256 *(cur_val-128)+ *cur_state.byte_field++;
for(j= (cur_val+name_dir)->byte_start;j<(name_dir+cur_val+1)->byte_start;
j++)putc( *j,C_file);
fprintf(C_file,"\"%s\n",""
#line 910 "tangle.web"
);
}
break;

#line 1 "outtoks.web"
/*:72*/
#line 827 "tangle.web"
;
/*74:*/
#line 57 "outtoks.web"

#line 58 "outtoks.web"
case 23:
fprintf(C_file,"%s","->");
if(out_state!=4)out_state= 0;
break;
case 21:
fprintf(C_file,"%s","<<");
if(out_state!=4)out_state= 0;
break;
case 28:
fprintf(C_file,"%s","<=");
if(out_state!=4)out_state= 0;
break;
case 26:
fprintf(C_file,"%s","==");
if(out_state!=4)out_state= 0;
break;
case 27:
fprintf(C_file,"%s",">=");
if(out_state!=4)out_state= 0;
break;
case 22:
fprintf(C_file,"%s",">>");
if(out_state!=4)out_state= 0;
break;
case 25:
fprintf(C_file,"%s","&&");
if(out_state!=4)out_state= 0;
break;
case 31:
fprintf(C_file,"%s","++");
if(out_state!=4)out_state= 0;
break;
case 30:
fprintf(C_file,"%s","--");
if(out_state!=4)out_state= 0;
break;
case 29:
fprintf(C_file,"%s","!=");
if(out_state!=4)out_state= 0;
break;
case 20:
if(out_state==4){
fprintf(C_file,"%s","===>");
}else{
fprintf(C_file,"%s"," ");
}
if(out_state!=4)out_state= 0;
break;
case 24:
fprintf(C_file,"%s","||");
if(out_state!=4)out_state= 0;
break;
/*:74*//*75:*/
#line 110 "outtoks.web"

#line 111 "outtoks.web"
case'=':
if(out_state==4){
fprintf(C_file,"%s","=");
}else{
fprintf(C_file,"%s","= ");
}
if(out_state!=4)out_state= 0;
break;
case'*':
if(out_state==4){
fprintf(C_file,"%s","*");
}else{
fprintf(C_file,"%s"," *");
}
if(out_state!=4)out_state= 0;
break;
/*:75*/
#line 828 "tangle.web"

case 127:out_state= 3;break;
case 3:if(out_state==4){
out_state= 1;break;
}
if(out_state==1)putc(' ',C_file);out_state= 4;break;
case 2:if(out_state==4)out_state= 0;
else out_state= 4;break;
default:putc(cur_char,C_file);if(out_state!=4)out_state= 0;
break;
}
}

/*:69*//*89:*/
#line 981 "tangle.web"
eight_bits skip_ahead()
#line 982 "tangle.web"
{
eight_bits c;
while(1){
if(loc>limit&&(get_line()==0))return(255);
 *(limit+1)= 64;
while( *loc!=64)loc++;
if(loc<=limit){
loc++;c= ccode[ *loc];
#ifdef DEBUG
if(c==248){
tracing=  *loc-48;c= 0;
}
#endif DEBUG
loc++;
if(c!=0|| *(loc-1)=='>')return(c);
}
}
}

/*:89*//*91:*/
#line 1012 "tangle.web"

#line 1013 "tangle.web"
skip_comment()
{
ASCII c;
if(0){
get_line();
return(comment_continues= 0);
}else{
while(1){
if(loc>limit)
if(get_line())return(comment_continues= 1);
else{
err_print("! Input ended in mid-comment");

return(comment_continues= 0);
}
c=  *(loc++);
/*81:*/
#line 162 "outtoks.web"

{int len;len= strlen("*/");
if(loc+len-1<=limit&&!strncmp(loc-1,"*/",len)){
loc+= len-1;return(comment_continues= 0);}}
/*:81*/
#line 1029 "tangle.web"

if(c==64){
if(ccode[ *loc]==255){
err_print("! Section name ended in mid-comment");loc--;

return(comment_continues= 0);
}
else loc++;
}
}
}
}
/*:91*//*94:*/
#line 1052 "tangle.web"
eight_bits get_next()
#line 1053 "tangle.web"
{
eight_bits c;
while(1){
if(loc>limit){
if(get_line()==0)return(255);
else if(print_where){
print_where= 0;
/*124:*/
#line 1586 "tangle.web"

#line 1587 "tangle.web"
store_two_bytes(53248);
if(changing)id_first= change_file_name;
else id_first= file_name[include_depth];
id_loc= id_first+strlen(id_first);
if(changing)store_two_bytes((sixteen_bits)change_line);
else store_two_bytes((sixteen_bits)line[include_depth]);
{int a= id_lookup(id_first,id_loc,0)-name_dir;{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= (a/256)+128;};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a%256;};}

/*:124*/
#line 1060 "tangle.web"
;
}
else return(10);
}
c=  *loc;
if(comment_continues){
skip_comment();
if(comment_continues||0)return(10);
else continue;
}
/*80:*/
#line 150 "outtoks.web"

#line 151 "outtoks.web"
{int len;len= strlen("/*");
if(loc+len<=limit&&!strncmp(loc,"/*",len)){
loc+= len;
skip_comment();
if(comment_continues||0)
return('\n');
else continue;
}
}
/*:80*/
#line 1070 "tangle.web"

loc++;
if(isdigit(c)||c=='\\'||c=='.')/*96:*/
#line 1092 "tangle.web"
{
#line 1093 "tangle.web"
id_first= loc-1;
if( *id_first=='.'&&!isdigit( *loc))goto mistake;
if( *id_first=='\\')while(isdigit( *loc))loc++;
else{
if( *id_first=='0'){
if( *loc=='x'|| *loc=='X'){
loc++;while(isxdigit( *loc))loc++;goto found;
}
}
while(isdigit( *loc))loc++;
if( *loc=='.'){
loc++;
while(isdigit( *loc))loc++;
}
if( *loc=='e'|| *loc=='E'){
if( *++loc=='+'|| *loc=='-')loc++;
while(isdigit( *loc))loc++;
}
}
found:
id_loc= loc;
return(3);
}

/*:96*/
#line 1072 "tangle.web"

else if(isalpha(c)||c=='_'||c=='$')/*95:*/
#line 1084 "tangle.web"
{
#line 1085 "tangle.web"
id_first= --loc;
while(isalpha( *++loc)||isdigit( *loc)|| *loc=='_');
if( *loc=='$')while(isdigit( *++loc)|| *loc=='$');

id_loc= loc;return(130);
}

/*:95*/
#line 1073 "tangle.web"

else if(c=='\''||c=='\"')/*97:*/
#line 1122 "tangle.web"
{
#line 1123 "tangle.web"
ASCII delim= c;


if(delim=='\''&&(loc+1>=limit||
( *loc!='\\'&& *loc!=64&&loc[1]!='\'')||
( *loc=='\\'&&(loc+2>=limit||loc[2]!='\''))||
( *loc==64&&
(loc+2>=limit||loc[1]!=64||loc[2]!='\''))
))goto mistake;
id_first= mod_text+1;
id_loc= mod_text; *++id_loc= delim;
while(1){
if(loc>=limit){
if( *(limit-1)!='\\'){
err_print("! String didn't end");loc= limit;break;

}
if(get_line()==0){
err_print("! Input ended in middle of string");loc= buffer;break;

}
else if(++id_loc<=mod_text_end) *id_loc= 10;

}
if((c=  *loc++)==delim){
if(++id_loc<=mod_text_end) *id_loc= c;
break;
}
if(c=='\\'){
if(loc>=limit)continue;
if(++id_loc<=mod_text_end) *id_loc= '\\';
c=  *loc++;
}
if(++id_loc<=mod_text_end) *id_loc= c;
}
if(id_loc>=mod_text_end){
printf("\n! String too long: ");

fflush(stdout),write(1,mod_text+1,25);
printf("...");history= 2;
}
id_loc++;
return(2);
}

/*:97*/
#line 1074 "tangle.web"

else if(c==64)/*98:*/
#line 1171 "tangle.web"
{
#line 1172 "tangle.web"
c= ccode[ *loc++];
switch(c){
case 0:continue;
case 250:while((c= skip_ahead())==64);

if( *(loc-1)!='>')err_print("! Improper @ within control text");

continue;
case 254:
cur_module_char=  *(loc-1);
/*102:*/
#line 1221 "tangle.web"
{
#line 1222 "tangle.web"
ASCII *k;
/*104:*/
#line 1241 "tangle.web"

#line 1242 "tangle.web"
k= mod_text;
while(1){
if(loc>limit&&get_line()==0){
err_print("! Input ended in section name");

loc= buffer+1;break;
}
c=  *loc;
/*105:*/
#line 1265 "tangle.web"

#line 1266 "tangle.web"
if(c==64){
c=  *(loc+1);
if(c=='>'){
loc+= 2;break;
}
if(ccode[c]==255){
err_print("! Section name didn't end");break;

}
 *(++k)= 64;loc++;
}

/*:105*/
#line 1250 "tangle.web"
;
loc++;if(k<mod_text_end)k++;
if(c==' '||c==011){
c= ' ';if( *(k-1)==' ')k--;
}
 *k= c;
}
if(k>=mod_text_end){
printf("\n! Section name too long: ");

fflush(stdout),write(1,mod_text+1,25);
printf("...");{if(history==0)history= 1;};
}
if( *k==' '&&k>mod_text)k--;

/*:104*/
#line 1223 "tangle.web"
;
if(k-mod_text>3&&strncmp(k-2,"...",3)==0)cur_module= prefix_lookup(mod_text+1,k-3);
else cur_module= mod_lookup(mod_text+1,k);
if(cur_module_char=='('){
/*66:*/
#line 749 "tangle.web"

#line 750 "tangle.web"
{
if(cur_out_file>output_files){
for(an_output_file= cur_out_file;
an_output_file<end_output_files;an_output_file++)
if( *an_output_file==cur_module)break;
if(an_output_file==end_output_files)
 *--cur_out_file= cur_module;
}else{
{{printf("\n! Sorry, capacity exceeded: ");err_print("output files");history= 3;wrap_up();};};
}
}

/*:66*/
#line 1228 "tangle.web"

}
return(254);
}

/*:102*/
#line 1182 "tangle.web"
;
case 2:/*106:*/
#line 1283 "tangle.web"
{
#line 1284 "tangle.web"
id_first= loc++; *(limit+1)= 64; *(limit+2)= '>';
while( *loc!=64|| *(loc+1)!='>')loc++;
if(loc>=limit)err_print("! Verbatim string didn't end");

id_loc= loc;loc+= 2;
return(2);
}

/*:106*/
#line 1183 "tangle.web"
;
#ifdef DEBUG
case 248:tracing=  *(loc-1)-'0';continue;
#endif DEBUG
case 249:/*99:*/
#line 1194 "tangle.web"

#line 1195 "tangle.web"
id_first= loc;
if( *loc=='\\')loc++;
while( *loc!='\''){
loc++;
if(loc>limit){
err_print("! String didn't end");loc= limit-1;break;
}
}
loc++;
return(249);

/*:99*/
#line 1187 "tangle.web"
;
case 5:/*100:*/
#line 1206 "tangle.web"
{
#line 1207 "tangle.web"
id_first= loc;
while('0'<= *loc&& *loc<'8')loc++;
id_loc= loc;
return(5);
}

/*:100*/
#line 1188 "tangle.web"
;
case 6:/*101:*/
#line 1213 "tangle.web"
{
#line 1214 "tangle.web"
id_first= loc;
while(isxdigit( *loc))loc++;
id_loc= loc;
return(6);
}


/*:101*/
#line 1189 "tangle.web"
;
default:return(c);
}
}

/*:98*/
#line 1075 "tangle.web"

else if(c==' '||c==011){
continue;
}
mistake:/*73:*/
#line 2 "outtoks.web"

#line 3 "outtoks.web"
if(loc+3<=limit){
if(strncmp("===>",loc-1,4)==0){
loc+= 3;
return 20;
}
}
if(loc+2<=limit){
}
if(loc+1<=limit){
if(strncmp("->",loc-1,2)==0){
loc+= 1;
return 23;
}
else if(strncmp("<<",loc-1,2)==0){
loc+= 1;
return 21;
}
else if(strncmp("<=",loc-1,2)==0){
loc+= 1;
return 28;
}
else if(strncmp("==",loc-1,2)==0){
loc+= 1;
return 26;
}
else if(strncmp(">=",loc-1,2)==0){
loc+= 1;
return 27;
}
else if(strncmp(">>",loc-1,2)==0){
loc+= 1;
return 22;
}
else if(strncmp("&&",loc-1,2)==0){
loc+= 1;
return 25;
}
else if(strncmp("++",loc-1,2)==0){
loc+= 1;
return 31;
}
else if(strncmp("--",loc-1,2)==0){
loc+= 1;
return 30;
}
else if(strncmp("!=",loc-1,2)==0){
loc+= 1;
return 29;
}
else if(strncmp("||",loc-1,2)==0){
loc+= 1;
return 24;
}
}
/*:73*/
#line 1079 "tangle.web"

return(c);
}
}

/*:94*//*108:*/
#line 1314 "tangle.web"
scan_repl(t)
#line 1315 "tangle.web"
eight_bits t;
{
sixteen_bits a;
int set_print_where;
if(t==254){/*124:*/
#line 1586 "tangle.web"

#line 1587 "tangle.web"
store_two_bytes(53248);
if(changing)id_first= change_file_name;
else id_first= file_name[include_depth];
id_loc= id_first+strlen(id_first);
if(changing)store_two_bytes((sixteen_bits)change_line);
else store_two_bytes((sixteen_bits)line[include_depth]);
{int a= id_lookup(id_first,id_loc,0)-name_dir;{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= (a/256)+128;};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a%256;};}

/*:124*/
#line 1319 "tangle.web"
;}


while(1){
if(t==1){
print_where= 0;
}
a= get_next();
if(t==1){
set_print_where= print_where;
}
switch(a){
/*123:*/
#line 1529 "tangle.web"

#line 1530 "tangle.web"
case 130:
{short n;
if((n= parameter_number(id_first,id_loc))!=0){
#ifdef TRACE_MACROS
if(tracing>1){
printf("\nIdentified ");fflush(stdout),write(1,id_first,id_loc-id_first);
printf(" as parameter number %d (%d from back)",n,next_param_name-n+1);
}
#endif TRACE_MACROS
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 7;};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= next_param_name-n+1;};
}else{
a= id_lookup(id_first,id_loc,0)-name_dir;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= (a/256)+128;};{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a%256;};
}
}
break;
case 254:if(t!=254)goto done;
else{
/*125:*/
#line 1596 "tangle.web"
{
#line 1597 "tangle.web"
ASCII *try_loc= loc;
while( *try_loc==' '&&try_loc<limit)try_loc++;
if( *try_loc=='+'&&try_loc<limit)try_loc++;
while( *try_loc==' '&&try_loc<limit)try_loc++;
if( *try_loc=='=')err_print("! Nested named modules.  Missing @?");

}

/*:125*/
#line 1549 "tangle.web"
;
a= cur_module-name_dir;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= (a/256)+168;};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a%256;};
/*124:*/
#line 1586 "tangle.web"

#line 1587 "tangle.web"
store_two_bytes(53248);
if(changing)id_first= change_file_name;
else id_first= file_name[include_depth];
id_loc= id_first+strlen(id_first);
if(changing)store_two_bytes((sixteen_bits)change_line);
else store_two_bytes((sixteen_bits)line[include_depth]);
{int a= id_lookup(id_first,id_loc,0)-name_dir;{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= (a/256)+128;};
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a%256;};}

/*:124*/
#line 1553 "tangle.web"
;break;
}
case 3:case 2:
/*126:*/
#line 1605 "tangle.web"

#line 1606 "tangle.web"
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a;};
while(id_first<id_loc){
if( *id_first==64)id_first++;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++=  *id_first++;};
}
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a;};break;

/*:126*/
#line 1556 "tangle.web"
;
case 249:
/*127:*/
#line 1613 "tangle.web"
{
#line 1614 "tangle.web"
int c;
if( *id_first==64){
c= xchr[ *id_first++];
if( *id_first!=64)err_print("! Double @ within string");
}
else if( *id_first=='\\'){
id_first++;
switch( *id_first){
case't':c= 9;break;
case'n':c= 10;break;
case'b':c= 8;break;
case'0':c= 0;break;
case'\\':c= 92;break;
default:err_print("! Unrecognized escape sequence");
}
}
else c= xchr[ *id_first];
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};


app_decimal((long)c);
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};
}
break;

/*:127*/
#line 1558 "tangle.web"
;
case 5:
/*128:*/
#line 1640 "tangle.web"
{
#line 1641 "tangle.web"
long sum= 0;
while(id_first<id_loc){
sum= 8 *sum+ *id_first++-'0';
if(sum>67108864)err_print("! Octal constant exceeds @\"04000000");
}
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};
app_decimal(sum);
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};
}

/*:128*/
#line 1560 "tangle.web"
;break;
case 6:
/*129:*/
#line 1651 "tangle.web"
{
#line 1652 "tangle.web"
long sum= 0;
while(id_first<id_loc){
sum= 16 *sum+
(isdigit( *id_first)
? *id_first-'0'
:isupper( *id_first)
? *id_first-'A'+10
: *id_first-'a'+10
);
id_first++;
if(sum>67108864)err_print("! Hex constant exceeds @\"04000000");
}
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};
app_decimal(sum);
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= 3;};
}

/*:129*/
#line 1562 "tangle.web"
;break;
case 10:
#ifdef NEWLINES_IN_MACROS
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a;};
#else
if(t==1)continue;
else{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a;};
#endif NEWLINES_IN_MACROS
break;
case 252:case 251:case 253:
if(t!=254)goto done;
else{
err_print("! @d, @f and @u are ignored in C text");continue;

}
case 255:goto done;

/*:123*/
#line 1334 "tangle.web"

default:{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= a;};
}
}
done:next_control= (eight_bits)a;
if(text_ptr>text_info_end){{printf("\n! Sorry, capacity exceeded: ");err_print("text");history= 3;wrap_up();};};
if(t==1){
/*109:*/
#line 1358 "tangle.web"

#line 1359 "tangle.web"
tok_ptr-= 2;
while( *tok_ptr<128&& *(tok_ptr+1)==10)tok_ptr--;
tok_ptr+= 2;

/*:109*/
#line 1341 "tangle.web"
;
}
cur_text= text_ptr;(++text_ptr)->tok_start= tok_ptr;
print_where= set_print_where;
}

/*:108*//*115:*/
#line 1408 "tangle.web"

#line 1409 "tangle.web"
int parameter_number(first,loc)
ASCII *first, *loc;
{
ASCII *f, *p;
int n;
for(n= 0;n<next_param_name;n++){
if(loc-first==param_names[n+1]-param_names[n]){

for(f= first,p= param_names[n];f<loc;)
if( *f++!= *p++)goto nomatch;
return n+1;
}
nomatch:continue;
}
return 0;
}


/*:115*//*130:*/
#line 1670 "tangle.web"

#line 1671 "tangle.web"
app_decimal(c)
long c;
{long power;
if(c==0){{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= '0';};return;}
if(c<0){{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= '-';};c= -c;}
for(power= 1;c>=power;power *= 10);

for(power/= 10;power>=1;power/= 10){
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= '0'+c/power;};
c%= power;

}
}



/*:130*//*132:*/
#line 1697 "tangle.web"
scan_module()
#line 1698 "tangle.web"
{
name_pointer p;
text_pointer q;
sixteen_bits a;
module_count++;
if( *(loc-1)=='*')
printf("*%d",module_count);fflush(stdout);
/*133:*/
#line 1714 "tangle.web"

next_control= 0;
while(1){
done_scanning:
while(next_control<=251)
if((next_control= skip_ahead())==254){

loc-= 2;next_control= get_next();
}
if(next_control!=252)break;
/*116:*/
#line 1433 "tangle.web"

#line 1434 "tangle.web"
/*122:*/
#line 1521 "tangle.web"

#line 1522 "tangle.web"
while((next_control= get_next())==10);

/*:122*/
#line 1434 "tangle.web"

/*120:*/
#line 1484 "tangle.web"

#line 1485 "tangle.web"
if(next_control!=130){
err_print("! Macro name must be an identifier");

/*134:*/
#line 1732 "tangle.web"

#line 1733 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1733 "tangle.web"
;
p->dummy.Ilk= 0;
goto done_scanning;


/*:134*/
#line 1488 "tangle.web"
;
}else{
p= id_lookup(id_first,id_loc,1);
if(p->dummy.Ilk!=1){
#ifdef WARN_USE_BEFORE_DEF
printf("\n! Warning: macro name ");
fflush(stdout),write(1,(p)->byte_start,(((p)+1)->byte_start-((p))->byte_start));
printf(" was used before it was defined");
{if(history==0)history= 1;};
#endif WARN_USE_BEFORE_DEF
p->dummy.Ilk= 1;
}else if(p+1!=name_ptr){
err_print("! Macro name is multiply defined: ");
}
}

/*:120*/
#line 1436 "tangle.web"
;
/*119:*/
#line 1469 "tangle.web"

#line 1470 "tangle.web"
/*122:*/
#line 1521 "tangle.web"

#line 1522 "tangle.web"
while((next_control= get_next())==10);

/*:122*/
#line 1470 "tangle.web"

if(next_control==40){
do{
/*121:*/
#line 1504 "tangle.web"

#line 1505 "tangle.web"
/*122:*/
#line 1521 "tangle.web"

#line 1522 "tangle.web"
while((next_control= get_next())==10);

/*:122*/
#line 1505 "tangle.web"
;
if(next_control!=130){
err_print("! Macro parameter name not an identifier");

/*134:*/
#line 1732 "tangle.web"

#line 1733 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1733 "tangle.web"
;
p->dummy.Ilk= 0;
goto done_scanning;


/*:134*/
#line 1509 "tangle.web"
;
}else{
if(parameter_number(id_first,id_loc)!=0){
err_print("! Duplicate parameters in macro definition");

/*134:*/
#line 1732 "tangle.web"

#line 1733 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1733 "tangle.web"
;
p->dummy.Ilk= 0;
goto done_scanning;


/*:134*/
#line 1514 "tangle.web"
;
}else{
/*113:*/
#line 1387 "tangle.web"

#line 1388 "tangle.web"
/*114:*/
#line 1393 "tangle.web"

#line 1394 "tangle.web"
if(next_param_name==32)
{{printf("\n! Sorry, capacity exceeded: ");err_print("parameter names");history= 3;wrap_up();};};
if(id_loc-id_first>
param_name_texts_end-next_param_name_text)
{{printf("\n! Sorry, capacity exceeded: ");err_print("parameter name texts");history= 3;wrap_up();};};


/*:114*/
#line 1388 "tangle.web"
;
while(id_first<id_loc)
 *next_param_name_text++=  *id_first++;
param_names[++next_param_name]= next_param_name_text;

/*:113*/
#line 1516 "tangle.web"
;
}
}


/*:121*/
#line 1473 "tangle.web"
;
/*122:*/
#line 1521 "tangle.web"

#line 1522 "tangle.web"
while((next_control= get_next())==10);

/*:122*/
#line 1474 "tangle.web"

}while(next_control==44);
if(next_control!=41){
err_print("! Macro parameter list must end with )");
/*134:*/
#line 1732 "tangle.web"

#line 1733 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1733 "tangle.web"
;
p->dummy.Ilk= 0;
goto done_scanning;


/*:134*/
#line 1478 "tangle.web"
;
}
next_control= get_next();
}


/*:119*/
#line 1439 "tangle.web"
;
if(next_control!=61){
err_print("! You must put an = sign before the macro replacement text");
/*134:*/
#line 1732 "tangle.web"

#line 1733 "tangle.web"
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1733 "tangle.web"
;
p->dummy.Ilk= 0;
goto done_scanning;


/*:134*/
#line 1442 "tangle.web"
;
}
/*117:*/
#line 1451 "tangle.web"

#line 1452 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>1){
printf("\nScanning definition of macro ");fflush(stdout),write(1,(p)->byte_start,(((p)+1)->byte_start-((p))->byte_start));
}
#endif TRACE_MACROS

/*:117*/
#line 1444 "tangle.web"
;
{if(tok_ptr==tok_mem_end){{printf("\n! Sorry, capacity exceeded: ");err_print("token");history= 3;wrap_up();};}; *tok_ptr++= next_param_name;};
scan_repl(1);
p->equiv_or_xref= (ASCII *)cur_text;
/*118:*/
#line 1458 "tangle.web"

#line 1459 "tangle.web"
#ifdef TRACE_MACROS
if(tracing>2){
printf("\nMacro ");fflush(stdout),write(1,(p)->byte_start,(((p)+1)->byte_start-((p))->byte_start));
printf("'s replacement text is in text_info[%d]",cur_text-text_info);
}
#endif TRACE_MACROS


/*:118*/
#line 1448 "tangle.web"
;
/*111:*/
#line 1380 "tangle.web"

#line 1381 "tangle.web"
next_param_name= 0;
next_param_name_text= param_name_texts;
param_names[next_param_name]= next_param_name_text;

/*:111*/
#line 1449 "tangle.web"
;

/*:116*/
#line 1724 "tangle.web"
;
cur_text->text_link= 0;
}

/*:133*/
#line 1705 "tangle.web"
;
/*135:*/
#line 1738 "tangle.web"

#line 1739 "tangle.web"
switch(next_control){
case 253:p= name_dir;break;
case 254:p= cur_module;
/*136:*/
#line 1750 "tangle.web"

#line 1751 "tangle.web"
while((next_control= get_next())=='+');
if(next_control!='='){
err_print("! C text flushed, = sign is missing");

while((next_control= skip_ahead())!=255);
return;
}

/*:136*/
#line 1742 "tangle.web"
;
break;
default:return;
}
/*137:*/
#line 1759 "tangle.web"

#line 1760 "tangle.web"
store_two_bytes((sixteen_bits)(53248+module_count));

/*:137*/
#line 1746 "tangle.web"
;
scan_repl(254);
/*138:*/
#line 1762 "tangle.web"

#line 1763 "tangle.web"
if(p==name_dir||p==0){
(last_unnamed)->text_link= cur_text-text_info;last_unnamed= cur_text;
}
else if(p->equiv_or_xref==(ASCII *)text_info)p->equiv_or_xref= (ASCII *)cur_text;

else{
q= (text_pointer)p->equiv_or_xref;
while(q->text_link<2000)q= q->text_link+text_info;
q->text_link= cur_text-text_info;
}
cur_text->text_link= 2000;

/*:138*/
#line 1748 "tangle.web"
;

/*:135*/
#line 1706 "tangle.web"
;
}

/*:132*//*139:*/
#line 1775 "tangle.web"
phase_one(){
#line 1776 "tangle.web"
phase= 1;
module_count= 0;
reset_input();
while((next_control= skip_ahead())!=255);
while(!input_has_ended)scan_module();
check_complete();
phase= 2;
}

/*:139*//*140:*/
#line 1785 "tangle.web"
print_stats(){
#line 1786 "tangle.web"
printf("\nMemory usage statistics:\n");
printf("%d names (out of %d)\n",name_ptr-name_dir,4000);
printf("%d replacement texts (out of %d)\n",text_ptr-text_info,2000);
printf("%d bytes (out of %d)\n",byte_ptr-byte_mem,90000);
printf("%d tokens (out of %d)\n",tok_ptr-tok_mem,150000);
}

/*:140*/
