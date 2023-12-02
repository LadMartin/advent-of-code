#! /usr/bin/awk -f
BEGIN{
	p0 = "one|two|three|four|five|six|seven|eight|nine"
	p = "(" p0 "|[0-9])"
	#p = "([0-9])"
	split(p0, nums, "|")
}
{
	l = match($0, p ".*" p, arr) != 0 ? 2 : 1
	if (l == 1) match($0, p, arr)
	
	for (i in arr) {
		for (n in nums) if(gsub(nums[n], n, arr[i]) != 0) break
	}
	count += int(arr[1] arr[l])
} 
END { print count }
