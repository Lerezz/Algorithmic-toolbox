#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> vec;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string num;
		cin>>num;
		vec.push_back(num);
	}
	sort(vec.begin(),vec.end(),greater<string>());
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i];
	}
}
/*
int len=a.length()>b.length()?a:b;
	for(int i=0;i<len;i++)
	{
		if(a[i]>b[i])	return 1;
		else if(a[i]<b[i])	return -1;
	}
	if(a.length()>len)	return 1;
*/
