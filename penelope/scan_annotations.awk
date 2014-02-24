# used to print the code that ignores <<nl annotation>> in annotations
#  and ignores <<nl virtual>> in virtual text
# Assumes the following categories
#	nl == newline token (closes virtual text and annotations) 
#	sp == suspend parse -- used to suspend parsing of virtual
#			       text while we scan an annotation
#	virtual = --: (opens virtual text)
#	annotation = --| (opens annotations)
#

# copy everything
{ print } 

# Announce ourselves

/^#scan_annotations [0-9]*$/ { 
  print ""
  print "# automatically generating productions..."
  print ""
  }

#
# ignore <<nl annotation>> in annotations
#
/^#scan_annotations [0-9]*$/ { 
  print ""
  print "# \"annotation\" expansion sequence"
  print ""
  $nlsp = ""
  for (i = 2; i <= $2; i++) 
  {
    printf "annotation " $nlsp 
    printf "[ !(nl|sp) nl annotation ] --> annotation " 
    printf $nlsp "#" i
    printf "\n"
    $nlsp = $nlsp "!(nl|sp) "
  }
}
#
# ignore <<nl virtual>> in virtual text
#
/^#scan_annotations [0-9]*$/ { 
  print ""
  print "# \"virtual\" expansion sequence"
  print ""
  $nlsp = ""
  for (i = 2; i <= $2; i++) 
  {
    printf "virtual " $nlsp 
    printf "[ !(nl|sp) nl virtual ] --> virtual " 
    printf $nlsp "#" i
    printf "\n"
    $nlsp = $nlsp "!(nl|sp) "
  }
}
#
# suspend parsing of virtual text when an annotation is encountered
#
/^#scan_annotations [0-9]*$/ { 
  print ""
  print "# \"virtual\" -- \"annotation\" expansion sequence"
  print ""
  $nlsp = ""
  for (i = 2; i <= $2; i++) 
  {
    $nlsp = $nlsp "!(nl|sp) "
    printf "virtual " $nlsp 
    printf "[ nl ] annotation --> virtual " 
    printf $nlsp "sp annotation"
    printf "\n"
  }
  print ""
}

# Announce our passing

/^#scan_annotations [0-9]*$/ { 
  print ""
  print "# end of automatically generated productions"
  print ""
  }
