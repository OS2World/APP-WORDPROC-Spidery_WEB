% Copyright 1989 by Norman Ramsey, Odyssey Research Associates
% To be used for research purposes only
% For more information, see file COPYRIGHT in the parent directory

% This file is part of Spidery WEB
% This program by Norman Ramsey is based on programs Silvio Levy
% and D. E. Knuth.  Silvio Levy wrote most of the code.
% It is distributed WITHOUT ANY WARRANTY, express or implied.
% Dec 1987

% Change made to overcome a small error.  There is a comment that 
% only use a single at-sign.  We change it here to at-at.

@x
@ Control codes in \.{WEB}, which begin with `\.{@@}', are converted
into a numeric code designed to simplify \.{CWEAVE}'s logic; for example,
larger numbers are given to the control codes that denote more significant
milestones, and the code of |new_module| should be the largest of
all. Some of these numeric control codes take the place of ASCII
control codes that will not otherwise appear in the output of the
scanning routines.
@^ASCII code@>

@d ignore = 0 /* control code of no interest to \.{CWEAVE} */
@d verbatim = @'2 /* extended ASCII alpha will not appear */
		 /* extended ASCII beta will not appear */
@d begin_comment = @'10 /* ASCII tab mark will not appear */
@d octal = @'14 /* ASCII carriage return will not appear */
@d hex = @'15 /* ASCII form feed will not appear */
@d switch_math_flag = @'175 /* this code will be intercepted without confusion */
@d underline = @'176 /* this code will be intercepted without confusion */
@d param = @'177 /* ASCII delete will not appear */
/* identifier =200 or octal @'310 */
@#/* following three must be conseccutive for indexing to work */
@d xref_roman = (identifier+roman) /* control code for `\.{@@\^}' */
@d xref_wildcard = (identifier+wildcard) /* control code for `\.{@@:}' */
@d xref_typewriter = (identifier+typewriter) /* control code for `\.{@@.}' */
@d TeX_string = @'356 /* control code for `\.{@@t}' */
@d ascii_constant = @'357 /* control code for `\.{@@`}' */
@d join = @'360 /* control code for `\.{@@\&}' */
@d thin_space = @'361 /* control code for `\.{@@,}' */
@d math_break = @'362 /* control code for `\.{@@\char'174}' */
@d line_force = @'363 /* control code for `\.{@@/}' */
@d line_break = @'364 /* control code for `\.{@@-}' */
@d big_line_break = @'365 /* control code for `\.{@@\#}' */
@d no_line_break = @'366 /* control code for `\.{@@+}' */
@d pseudo_semi = @'367 /* control code for `\.{@@;}' */
@d vertical_bar = @'370 /* The `\v' used to mark Ada text */
@d trace = @'371 /* control code for `\.{@@0}', `\.{@@1}' and `\.{@@2}' */
@d format = @'373 /* control code for `\.{@@f}' */
@d definition = @'374 /* control code for `\.{@@d}' */
@d begin_unnamed = @'375 /* control code for `\.{@@u}' */
@d module_name = @'376 /* control code for `\.{@@<}' */
@d new_module = @'377 /* control code for `\.{@@\ }' and `\.{@@*}' */
@y
@ Control codes in \.{WEB}, which begin with `\.{@@}', are converted
into a numeric code designed to simplify \.{CWEAVE}'s logic; for example,
larger numbers are given to the control codes that denote more significant
milestones, and the code of |new_module| should be the largest of
all. Some of these numeric control codes take the place of ASCII
control codes that will not otherwise appear in the output of the
scanning routines.
@^ASCII code@>

@d ignore = 0 /* control code of no interest to \.{CWEAVE} */
@d verbatim = @'2 /* extended ASCII alpha will not appear */
		 /* extended ASCII beta will not appear */
@d begin_comment = @'10 /* ASCII tab mark will not appear */
@d octal = @'14 /* ASCII carriage return will not appear */
@d hex = @'15 /* ASCII form feed will not appear */
@d switch_math_flag = @'175 /* this code will be intercepted without confusion */
@d underline = @'176 /* this code will be intercepted without confusion */
@d param = @'177 /* ASCII delete will not appear */

% This is where the change is

/* identifier =200 or octal @@'310 */

@#/* following three must be conseccutive for indexing to work */
@d xref_roman = (identifier+roman) /* control code for `\.{@@\^}' */
@d xref_wildcard = (identifier+wildcard) /* control code for `\.{@@:}' */
@d xref_typewriter = (identifier+typewriter) /* control code for `\.{@@.}' */
@d TeX_string = @'356 /* control code for `\.{@@t}' */
@d ascii_constant = @'357 /* control code for `\.{@@`}' */
@d join = @'360 /* control code for `\.{@@\&}' */
@d thin_space = @'361 /* control code for `\.{@@,}' */
@d math_break = @'362 /* control code for `\.{@@\char'174}' */
@d line_force = @'363 /* control code for `\.{@@/}' */
@d line_break = @'364 /* control code for `\.{@@-}' */
@d big_line_break = @'365 /* control code for `\.{@@\#}' */
@d no_line_break = @'366 /* control code for `\.{@@+}' */
@d pseudo_semi = @'367 /* control code for `\.{@@;}' */
@d vertical_bar = @'370 /* The `\v' used to mark Ada text */
@d trace = @'371 /* control code for `\.{@@0}', `\.{@@1}' and `\.{@@2}' */
@d format = @'373 /* control code for `\.{@@f}' */
@d definition = @'374 /* control code for `\.{@@d}' */
@d begin_unnamed = @'375 /* control code for `\.{@@u}' */
@d module_name = @'376 /* control code for `\.{@@<}' */
@d new_module = @'377 /* control code for `\.{@@\ }' and `\.{@@*}' */
@z
