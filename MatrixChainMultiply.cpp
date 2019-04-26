#include <iostream>

using namespace std;

int MatrixChainOrder(int arr[], int x, int y)
{
	if(x == y)
		return 0;

	int min = INT_MAX, count;

	for (int k = x; k < y; k++)
	{
		count = MatrixChainOrder(arr, x, k) +
		 		MatrixChainOrder(arr, k+1, y) + 
		 		arr[ x - 1 ] * arr[ k ] * arr[ y ];
		if(count < min)
		{
			min = count;
		}
	}

	return min;
	
}

int main()
{
	int arr[] = {1, 2, 3, 4, 3};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout<<MatrixChainOrder(arr, 1, n -1);

	return 0;
}