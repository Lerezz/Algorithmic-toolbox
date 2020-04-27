#include<iostream>
using namespace std;

void get_distance(string a, string b)
{
	int lena=a.length();
	int lenb=b.length();
	int score[lena+1][lenb+1]={10000};
	for(int i=0;i<lena+1;i++)
	{
		score[i][0]=i;
	}

	for(int j=0;j<lenb+1;j++)
	{
		score[0][j]=j;
	}
	
	for(int i=1;i<lena+1;i++)
	{
		for(int j=1;j<lenb+1;j++)
		{
			if(a[i-1]==b[j-1])
			{
				score[i][j]=score[i-1][j-1];
			}
			else
			{
				score[i][j]=min(score[i-1][j], min(score[i-1][j-1], score[i][j-1]))+1;
			}
		}
	}
	cout<<score[lena][lenb];
}

int main()
{
	string a,b;
	cin>>a>>b;
	get_distance(a,b);
}
