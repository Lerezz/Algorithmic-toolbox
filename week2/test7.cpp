#include<iostream>
using namespace std;

int fab(long long n)
{
	int front=0,rear=1;
	int tmp;
	int sum=front+rear;
	if(n<2) return n;
	for(int i=2;i<=n;i++)
	{
		tmp=(front+rear)%10;
		front=rear%10;
		rear=tmp%10;
		sum=(sum+tmp)%10;
	}
	return sum;
} 

int periodic()
{
	int a=0,b=1;
	int c=(a+b)%10;
	for(int i=1;;i++)
	{
		c=(a+b)%10;
		a=b%10;
		b=c%10;
		if(a==0 && b==1)
			return i;
	}
}

int periodic_sum()
{
	int a=0,b=1;
	int sum=1;
	int c=0;
	for(int i=2;i<60;i++)
	{
		c=(a+b)%10;
		a=b%10;
		b=c%10;
		sum=(sum+c)%10;
	}
	return sum;
}

int main()
{
	long long n;
	long long m;
	cin>>n>>m;
	
	int p=periodic();
	n=n%p;
	int sum=periodic_sum();
	int divn=(n/p)*sum%10;
	int resA=fab(n-1);
	int r1=(divn+resA)%10;

	m=m%p;
	int divm=(m/p)*sum%10;
	int resB=fab(m);
	int r2=(divm+resB)%10;
	
	if(n==0)
		cout<<r2;
	else
		cout<<(r2-r1+10)%10;
}

