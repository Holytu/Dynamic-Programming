#include <iostream>

using namespace std;
void FibonacciNum(int n)
{
	int *f = new int[n+1];
	f[0] =0;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	cout<<"Fibonacci Number : "<<f[n]<<"\n";
}
int main(void)
{
	int n = 7;
	FibonacciNum(n);
	return 0;
}