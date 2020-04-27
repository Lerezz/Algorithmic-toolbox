#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void get_longest_common_sequences(vector<int> a, vector<int> b, vector<int> c, int lena, int lenb, int lenc)
{
	int score[lena+1][lenb+1][lenc+1];
	for(int i=0;i<lena+1;i++)
	{
		for(int j=0;j<lenb+1;j++)
		{
			for(int k=0;k<lenc+1;k++)
			{
				if(i==0 || j==0 || k==0) 
				{
					score[i][j][k]=0;
				}
				else if(a[i-1]==b[j-1] && b[j-1]==c[k-1]) 
				{
					score[i][j][k]=score[i-1][j-1][k-1]+1;
				} 
				else 
				{
					score[i][j][k]=max(score[i-1][j][k], max(score[i][j-1][k], score[i][j][k-1]));
				}
			}
		}
	}
	cout<<score[lena][lenb][lenc];
}

int main()
{
	int lena, lenb, lenc;
	
	cin>>lena;
	vector<int> a(lena);
	for(int i=0;i<lena;i++)
	{
		cin>>a[i];
	}
	
	cin>>lenb;
	vector<int> b(lenb);
	for(int i=0;i<lenb;i++)
	{
		cin>>b[i];
	}
	
	cin>>lenc;
	vector<int> c(lenc);
	for(int i=0;i<lenc;i++)
	{
		cin>>c[i];
	}
	get_longest_common_sequences(a, b, c, lena, lenb, lenc);
}
