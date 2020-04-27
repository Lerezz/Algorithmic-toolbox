#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v1;
	vector<int> v2;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			int num;
			cin>>num;
			if(i==0)
				v1.push_back(num);
			else
				v2.push_back(num);
		}
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=(long long)v1[i]*v2[i];
	}
	cout<<sum;
}
