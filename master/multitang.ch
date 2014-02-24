@x 423
output:
@y
output.
We have made some modifications to \.{TANGLE} so it will write output
on multiple files.
We do this very simply: if a module name is introduced by \.{@@(}
instead of \.{@@<}, we treat it as the name of a file.
All these special modules are saved on a stack, |output_files|.
We write them out after we've done the unnamed module.
@z
@x 425
@c
@y
@d max_files 256
@<Glob...@>=
name_pointer output_files[max_files];
name_pointer *cur_file, *end_output_files;
char cur_module_char; /* is it |'<'| or |'('| */
char output_file_name[longest_name]; /* name of the file */

@ We make |end_output_files| point jsut beyond the end of
|output_files|.
|cur_file| starts out there. Every time we see a new file, we
decrement |cur_file| and then write it in.
@<Set initial...@>=
cur_file=end_output_files=output_files+max_files;

@ @<Add |cur_module| to the output file stack, or complain we're out
of room@>=
{
if (cur_file>output_files) 
	*--curfile=cur_module;
else {
	overflow("output files");
}
}

@ Here is the output switch, then...

@c
@z
@x 434
    printf("\nWriting the output file"); update_terminal;
@y
    printf("\nWriting the output files: (%s)",C_file_name); update_terminal;
@z
@x 438
    printf("\nDone.");
@y
    @<Write all the named output files@>
    printf("\nDone.");
@z
@x 442
@ First we go through the list of replacement texts and copy the ones
@y
@ To write the named output files, we proceed as for the unnamed
module.
The only subtlety is that we have to open each one.
@<Write all the named output files@>=
for (;cur_file<end_output_files; cur_file++) {
	strncpy(output_file_name,(*curfile)->byte_start, longest_name);
	output_file_name[length(*curfile)]='\0';
	fclose(C_file);
	C_file=fopen(output_file_name,"w");
	if (C_file <=0) {
		fatal("! Cannot open output file:",output_file_name)
	} else {
		printf("(%s)",output_file_name); update_terminal;
	}
	stack_ptr=stack+1;
	cur_name= (*cur_file);
	cur_repl= cur_name->equiv_or_xref;
	cur_byte=cur_repl->tok_start;
	cur_end=(cur_repl+1)->tok_start;
	/* cur_mod=  it */;
	while (stack_ptr > stack) get_output();
	flush_buffer();
}	



@ First we go through the list of replacement texts and copy the ones
@z
@x 575
  ccode['&']=join; ccode['<']=module_name;
@y
  ccode['&']=join; 
  ccode['<']=ccode['(']=module_name; 
@z
@x 778
    case module_name: @<Scan the module name and make |cur_module|
      point to it@>;
@y
    case module_name: 
	cur_module_char=*(loc-1);
	@<Scan the module name and make |cur_module| point to it@>;
@z
@x 803
  return(module_name);
@y
  if (cur_module_char=='(') {
	@<Add |cur_module| to the output file stack, or complain we're out
	of room@>
  }
  return(module_name);
@z
