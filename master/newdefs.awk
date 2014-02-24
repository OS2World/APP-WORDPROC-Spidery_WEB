## Used to convert old Levy CWEB style definitions to Spidery WEB definitions
/#d|@d/ {
	for (i=1; i<NF; i++) {
		if ($i=="#d"||$i=="@d") {
			$(i+1) =  $(i+1) " ="
		}
	}
	print
	next
}
{print}
