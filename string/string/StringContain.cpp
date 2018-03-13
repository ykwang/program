#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//直接遍历
bool StringContain(string &str1,string &str2){
	for(int i=0;i<str2.length();i++)
	{
		int j;
		for(j=0;j<str1.length()&&str2[i]!=str1[j];j++);
		if(j>=str1.length())
			return false;

	}
	return true;
}
//先排序，后遍历
bool StringContain(string &str1,string &str2){
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());

	for(int pa=0,pb=0;pb<str2.length();pb++){
		while(pa<str1.length()&&str1[pa]<str2[pb])
			pa++;
		if(pa>=str1.length()||str1[pa]>str2[pb])
			return false;

	}
	return true;

		
}
bool StringContain(string &strlong,string &strshort){
	int hash=0;
	for(int i=0;i<strlong.length();i++)
	{
		hash|=(1<<(strlong[i]-'A'));
	}
	for(int j=0;j<strshort.length();++j){
		if((hash&=(1<<(strshort[j]-'A')))==0)
			return false;
	}
	return true;
}