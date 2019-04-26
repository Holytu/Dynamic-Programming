#include <iostream>

using namespace std;
int Binomial(int n, int k)
{
	if( (n == k) || (k == 0) )
	{
		return 1;
	}
	else 
	{
		return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
	}
}
int main(void)
{
	int n = 10, k = 3;

	cout<<Binomial(n, k)<<"\n";

	return 0;
}