#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
	return (long long)(a/gcd(a,b)*b);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<lcm(a,b);
}
