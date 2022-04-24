#include<iostream>
#include<iomanip>

using namespace std;
 
void print(const int *v, const int size)
{
	int i;

	if (v != 0) 
	{
    		for ( i = 0; i < size; i++)
		{
			cout<<setw(4)<<v[i];
		}
		cout<<"\n";
	}
}
 
void Algo(int *Value, int N, int k)
{
	static int level = -1;
	int i;

	level = level+1; 
	Value[k] = level;
 
	if (level == N)
		print(Value, N);
	else
		for (i = 0; i < N; i++)

			if (Value[i] == 0)
				Algo(Value, N, i);
 

	level = level-1;
	Value[k] = 0;
}
 
int main()
{
	int i, N, count = 1;
	cout<<"Enter number: ";
	cin>>N;
	int Value[N];
 
	for (i = 0; i < N; i++)
	{
		Value[i] = 0;
		count *= (i+1);
	}
 
	cout<<"\nOutput: \n";
	Algo(Value, N, 0);
	
   return 0; 
 
	
}