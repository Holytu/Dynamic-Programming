#include <iostream>

using namespace std;
int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}
void PermutationCoef(int n, int k)
{
	int P[n+1][k+1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= min(i, k); j++)
		{
			if (j == 0)
			{
				P[i][j] = 1;
			}
			else 
			{
				P[i][j] = P[i - 1][j] + j * P[i - 1][j - 1];
			}
		}
	}

	cout<<P[n][k]<<"\n";
}
int main(void)
{
	int n = 10, k = 3;
	PermutationCoef(n,k);
	return 0;
}