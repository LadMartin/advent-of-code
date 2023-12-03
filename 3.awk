#!/usr/bin/awk -f
function check(index2)
{
	m += "" != y[index2]
	if (y[index2] == "*") {
		ratio += x[i] * gears[index2]
		gears[index2] = x[i]
	}
}

function readall(r, arr) {
	 i = 1
	 while(1) {	
		 ret = match(substr(str, i, length(str)), r, nums);
		 if (ret == 0) break
		 arr[i+ret-1] = nums[1]
		 i += RSTART + RLENGTH
	}
}

{
	size = length($0)
	str = str $0
}
END{
	readall("([0-9]+)", x);
	readall("([^0-9.])", y);
	for (i in x) {
		m = 0
		l = length(x[i])

		check(i-1)
		check(i+l)

		for (j=-1;j<=l;++j) {
			check(i+j+size)
			check(i+j-size)
		}

		count += m * x[i]
	}
	 
	 print count, ratio
 }
