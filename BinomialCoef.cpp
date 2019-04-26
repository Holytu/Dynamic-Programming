#include <iostream>

using namespace std;
int min(int x, int y)
{
	return (x > y) ? y : x;
}
void BinomialCoef(int n, int k)
{
	int c[n+1][k+1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(k, i); j++)
		{
			if(j == 0 || i == j)
			{
				c[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
	}
	cout<<c[n][k]<<endl;
}
int main()
{
	int n = 10, k = 4;
	BinomialCoef(n,k);
	return 0;
}