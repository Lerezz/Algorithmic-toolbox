#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pairs
{
	int begin;
	int end;
};

bool fun(pairs i, pairs j)
{
	return i.end<j.end;
}

void display(vector<int> vec)
{
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
}

void collecting_signature(vector<pairs> vec)
{
	sort(vec.begin(),vec.end(),fun);
	vector<int> point;
	int temp=vec[0].end;
	point.push_back(temp);
	for(int i=1;i<vec.size();i++)
	{
		if(temp>=vec[i].begin && temp<=vec[i].end)
		{
			continue;
		}
		else
		{
			temp=vec[i].end;
			point.push_back(temp);
		}
	}
	cout<<point.size()<<endl;
	display(point);
}

int main()
{
	int n;
	cin>>n;
	pairs p;
	vector<pairs> vec;
	while(n--)
	{
		cin>>p.begin>>p.end;
		vec.push_back(p);
	}
	collecting_signature(vec);
}
