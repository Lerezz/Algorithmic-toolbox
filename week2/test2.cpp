#include<iostream>
using namespace std;

int fab(long long n)
{
	int a=0;
	int b=1;
	int c;
	if(n<=1)
		return n;
	for(long long i=2;i<=n;i++)
	{
		c=(a+b)%10;
		a=b%10;
		b=c%10;
	}
	return c;
}

int main()
{
	long long n;
	cin>>n;
	int res=fab(n);
	cout<<res;
}
