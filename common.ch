% Change file to common.web for Spider Web generation for OS2
% To be used for research purposes only
% For more information, see file COPYRIGHT in the parent directory

% This file is part of Spidery WEB

% This program by Norman Ramsey is based on programs Silvio Levy
% and D. E. Knuth.  Silvio Levy wrote most of the code.
% It is distributed WITHOUT ANY WARRANTY, express or implied.
% Dec 1987

% Change file by Bruce Dubbs, Texas A&M University, bdubbs@neuron.tamu.edu


@x  Module  7  Sun Feb 14 01:12:22 1993
@ The \.{WEAVE} and \.{TANGLE} processors convert between ASCII code and
the user's external character set by means of arrays |xord| and |xchr|
that are analogous to PASCAL's |ord| and |chr| functions.

@<Definitions...@>=
ASCII xord[last_text_char]; /* specifies conversion of input characters */
outer_char xchr[@'200]; /* specifies conversion of output characters */
@y  Module  7  Sun Feb 14 01:12:22 1993
@ The \.{WEAVE} and \.{TANGLE} processors convert between ASCII code and
the user's external character set by means of arrays |xord| and |xchr|
that are analogous to PASCAL's |ord| and |chr| functions.

We have to change the size of xord to |last_text_char|+1 to cover the 
entire 128 byte ASCII array.

@<Definitions...@>=
ASCII xord[last_text_char+1]; /* specifies conversion of input characters */
outer_char xchr[@'200]; /* specifies conversion of output characters */
@z  Module  7  Sun Feb 14 01:12:22 1993

@x  Module  8  Sun Feb 14 01:16:14 1993
@ Every system supporting \cee\ must be able to read and write the 95
visible characters of standard ASCII above (although not necessarily using the
ASCII codes to represent them).  Conversely, these characters, plus
the newline, are sufficient to write any \cee\ program.  Other
characters are desirable mainly in strings, and they can be referred
to by means of escape sequences like \.{'\t'}.

The basic implementation of \.{WEB}, then, only has to assign an
|xord| to these 95 characters (newlines are swallowed by the reading
routines).  The easiest way to do this is to assign the characters to
their positions in |xchr| and then invert the correspondence:

@<Functions...@>=
common_init()
{
  strcpy(xchr,"                                 !\"#$%&'()*+,-./0123456789\
:;<=>?@@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ");
  @<System-dependent parts of character set@>;
  @<Invert |xchr| to get |xord|@>;
  @<Initialize pointers@>;
  setting_up=1;
  @<Scan arguments and open output files@>;
  setting_up=0;
}
@y  Module  8  Sun Feb 14 01:16:14 1993
@ Every system supporting \cee\ must be able to read and write the 95
visible characters of standard ASCII above (although not necessarily using the
ASCII codes to represent them).  Conversely, these characters, plus
the newline, are sufficient to write any \cee\ program.  Other
characters are desirable mainly in strings, and they can be referred
to by means of escape sequences like \.{'\t'}.

The basic implementation of \.{WEB}, then, only has to assign an
|xord| to these 95 characters (newlines are swallowed by the reading
routines).  The easiest way to do this is to assign the characters to
their positions in |xchr| and then invert the correspondence:

We make a change here so the string copy does not add a null to the |xchr|
array.

@<Functions...@>=
common_init()
{
  strncpy(xchr,"                                 !\"#$%&'()*+,-./0123456789\
:;<=>?@@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ ",128);
  @<System-dependent parts of character set@>;
  @<Invert |xchr| to get |xord|@>;
  @<Initialize pointers@>;
  setting_up=1;
  @<Scan arguments and open output files@>;
  setting_up=0;
}
@z  Module  8  Sun Feb 14 01:16:14 1993

@x  Module  28  Sun Feb 14 01:17:40 1993
@ When a \.{@@i} line is found in the |cur_file|, we must temporarily
stop reading it and start reading from the named include file.  The
\.{@@i} line should give a complete file name with or without \.{"..."};
\.{WEB} will look for include files in standard directories using
the |pathopen| module.
That is set up at the beginning using the {\tt -I} arguments 
and the {\tt WEBPATH} environment variable.
@<Add environment variable |"WEBPATH"| to search path@>=
	pathaddpath(getenv("WEBPATH"),':');
@y  Module  28  Sun Feb 14 01:17:40 1993
@ When a \.{@@i} line is found in the |cur_file|, we must temporarily
stop reading it and start reading from the named include file.  The
\.{@@i} line should give a complete file name with or without \.{"..."};
\.{WEB} will look for include files in standard directories using
the |pathopen| module.
That is set up at the beginning using the {\tt -I} arguments 
and the {\tt WEBPATH} environment variable.

We change the path delimeter to a semi-colon for OS/2.

@<Add environment variable |"WEBPATH"| to search path@>=
	pathaddpath(getenv("WEBPATH"),';');
@z  Module  28  Sun Feb 14 01:17:40 1993

@x  Module  70  Sun Feb 14 01:19:06 1993
@ @<Set up null...@>= 
#ifdef MSDOS
strcpy(change_file_name,"NUL");
#else
strcpy(change_file_name,"/dev/null");
#endif
@y  Module  70  Sun Feb 14 01:19:06 1993
@ OS/2 uses {\tt /dev/nul} instead of {\tt /dev/null}.

@<Set up null...@>= 
strcpy(change_file_name,"/dev/nul");  
@z  Module  70  Sun Feb 14 01:19:06 1993

