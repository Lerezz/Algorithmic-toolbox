#include<iostream>
#include<vector> 
using namespace std;

vector<int> vec;

long long fab(long long m)
{
	long long a=0,b=1,c=a+b;
	for(int i=0;i<m*m;i++)
	{
		c=(a+b)%m;
		a=b;
		b=c;
		if(a==0 && b==1)
			return i+1;
	}
}

long long get_fab(long long reminder, int m)
{
	long long a=0,b=1,c=reminder;
	for(int i=1;i<reminder;i++)
	{
		c=(a+b)%m;
		a=b;
		b=c;
	}
	return c%m;
}

int main()
{
	long long n;
	int m; 
	cin>>n>>m;
	long long periodic=(long long)fab(m);
	long long reminder=n%periodic;
	long long res=get_fab(reminder, m);
	cout<<res;
}
