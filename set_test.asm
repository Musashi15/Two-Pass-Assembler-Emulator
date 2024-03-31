;NAME- 		Moulik Jain
;Roll Number- 	2201CS49
;Decaration of Authorship 
;Testing of SET instruction 
ldc     x
ldc     y
sub		; x - y
ldc res
stnl 0		; store result in res	
res: data 0
x: SET 96
y: SET 70
