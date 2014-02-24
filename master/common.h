@ Here's stuff from the file |'common.web'| that has to be included in
|'tangle.web'| and |'weave.web'|.

General stuff:

@d tangle = 0
@d weave = 1

@<Common code for \.{WEAVE} and \.{TANGLE}@>=
typedef short boolean;
typedef char unsigned eight_bits;
extern boolean program; /* \.{WEAVE} or \.{TANGLE}? */
extern int phase; /* which phase are we in? */

@ @<Include files@>=
#include <stdio.h>

@ Code related to the character set:
@d tab_mark = 011 /* ASCII code used as tab-skip */
@d line_feed = 012 /* ASCII code thrown away at end of line */
@d form_feed = 014 /* ASCII code used at end of page */
@d carriage_return = 015 /* ASCII code used at end of line */

@<Common code...@>=
typedef char ASCII; /* type of characters inside \.{WEB} */
typedef char outer_char; /* type of characters outside \.{WEB} */
extern ASCII xord[]; /* specifies conversion of input characters */
extern outer_char xchr[]; /* specifies conversion of output characters */
ASCII mod_text[longest_name+1]; /* name being sought for */
ASCII *mod_text_end = mod_text+longest_name; /* end of |mod_text| */
ASCII *id_first; /* where the current identifier begins in the buffer */
ASCII *id_loc; /* just after the current identifier in the buffer */

@ Code related to input routines:
Killed |buf_size|; already in weave and tangle.

@<Common code...@>=
extern ASCII buffer[]; /* where each line of input goes */
extern ASCII *buffer_end; /* end of |buffer| */
extern ASCII *loc; /* points to the next character to be read from the buffer*/
extern ASCII *limit; /* points to the last character in the buffer */

@ Code related to identifier and module name storage:
Killed |max_bytes|, |max_names|, and |hash_size| --- all duplicated.

@d length(c) = ((c+1)->byte_start-(c)->byte_start) /* the length of a name */
@d print_id(c) = ASCII_write((c)->byte_start,length((c)))
  /* print identifier or module name */
@d llink = link /* left link in binary search tree for module names */
@d rlink = dummy.Rlink /* right link in binary search tree for module names */
@d ilk = dummy.Ilk /* ilk in checking identifiers */
@d root = name_dir->rlink /* the root of the binary search tree
  for module names */

@<Common code...@>=
typedef struct name_info {
  ASCII *byte_start; /* beginning of the name in |byte_mem| */
  struct name_info *link;
  union {
    struct name_info *Rlink; /* right link in binary search tree for module
      names */  
    eight_bits Ilk; /* used by identifiers in \.{WEAVE} (and for checking
                            macros in \.{TANGLE}?) */
  } dummy;
  ASCII *equiv_or_xref; /* info corresponding to names */
} name_info; /* contains information about an identifier or module name */
typedef name_info *name_pointer; /* pointer into array of |name_info|s */
typedef name_pointer *hash_pointer;
extern ASCII byte_mem[]; /* characters of names */
extern ASCII *byte_mem_end; /* end of |byte_mem| */
extern name_info name_dir[]; /* information about names */
extern name_pointer name_dir_end; /* end of |name_dir| */
extern name_pointer name_ptr; /* first unused position in |byte_start| */
extern ASCII *byte_ptr; /* first unused position in |byte_mem| */
extern name_pointer hash[]; /* heads of hash lists */
extern hash_pointer hash_end; /* end of |hash| */
extern hash_pointer h; /* index into hash-head array */
extern name_pointer id_lookup(); /* looks up a string in the identifier table */
extern name_pointer mod_lookup(); /* finds module name */
extern name_pointer prefix_lookup(); /* finds module name given a prefix */

@ Code related to error handling:
@d spotless = 0 /* |history| value for normal jobs */
@d harmless_message = 1 /* |history| value when non-serious info was printed */
@d error_message = 2 /* |history| value when an error was noted */
@d fatal_message = 3 /* |history| value when we had to stop prematurely */
@d mark_harmless = {if (history==spotless) history=harmless_message;}
@d mark_error = history=error_message
@d confusion(s) = fatal("\n! This can't happen: ",s)
@d fatal(s1,s2) = {
  printf(s1); err_print(s2);
  history=fatal_message; wrap_up();
}
@d overflow(s) = {
  fatal("\n! Sorry, capacity exceeded: ",s);
}

@<Common...@>=
extern history; /* indicates how bad this run was */

@ Code related to file handling:
@f line x /* make |line| an unreserved word */
@d max_file_name_length = 60
@d cur_file = file[include_depth] /* current file */
@d cur_file_name = file_name[include_depth] /* current file name */
@d web_file_name = file_name[0] /* main source file name */
@d cur_line = line[include_depth] /* number of current line in current file */

@<Common code...@>=
extern include_depth; /* current level of nesting */
extern FILE *file[]; /* stack of non-change files */
extern FILE *change_file; /* change file */
extern char C_file_name[]; /* name of |C_file| */
extern char tex_file_name[]; /* name of |tex_file| */
extern char file_name[][max_file_name_length];
  /* stack of non-change file names */
extern char change_file_name[]; /* name of change file */
extern line[]; /* number of current line in the stacked files */
extern change_line; /* number of current line in change file */
extern boolean input_has_ended; /* if there is no more input */
extern boolean changing; /* if the current line is from |change_file| */

@ Code related to module numbers:
@<Common code...@>=
typedef unsigned short sixteen_bits;
extern sixteen_bits module_count; /* the current module number */
extern boolean changed_module[]; /* is the module changed? */
extern boolean print_where; /* tells \.{TANGLE} to print line and file info */

@ Code related to command line arguments:
@<Common code...@>=
extern int argc; /* copy of |ac| parameter to |main| */
extern char **argv; /* copy of |av| parameter to |main| */
extern no_xref; /* should \.{WEAVE} print an index? */

@ Code relating to output:
@d update_terminal = fflush(stdout) /* empty the terminal output buffer */
@d new_line = putchar('\n') @d putxchar = putchar
@d ASCII_write(a,b) = fflush(stdout), write(1,a,b) /* write on the standard output */
@d line_write(c) = write(fileno(C_file),c) /* write on the C output file */
@d C_printf(c,a) = fprintf(C_file,c,a)
@d C_putc(c) = putc(c,C_file)

@<Common code...@>=
FILE *C_file; /* where output of \.{TANGLE} goes */
FILE *tex_file; /* where output of \.{WEAVE} goes */
