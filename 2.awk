#!/usr/bin/awk -f
{
	split($0,f,/:/,k);
	match($0,/([0-9]+)/,foo);
	t=foo[1];
	delete c;
	$0=f[2];
	ret = patsplit($0,z,/([0-9]+ )/,x);
	for(i in x){
		j=substr(x[i],1,1);
		c[j] = c[j] < z[i] ? z[i] : c[j]
	}
	count += (c["b"] <= 14 && c["r"] <= 12 && c["g"] <= 13)?t:0
	count2+= c["b"]*c["r"]*c["g"]
}
 END{
	 print count
	 print count2
 }
