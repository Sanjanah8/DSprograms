#include <iostream>
using namespace std;
template<typename T>
int partition(T  A[100],int first,int last)
{
	int pivot = A[first];
	int count = 0;
	for (int i = first + 1; i <= last; i++) {
		if (A[i] <= pivot)
			count++;
	}
	int pivotIndex = first + count;
	swap(A[pivotIndex], A[first]);
	int i = first, j = last;
	while (i < pivotIndex && j > pivotIndex) {
		while (A[i] <= pivot) {
			i++;
		}
		while (A[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			swap(A[i++], A[j--]);
		}
	}
	return pivotIndex;
}
template<typename T>
void quickSort(T A[100], int first, int last)
{
    int i;
	if (first >= last)
		return;
	int p = partition(A, first, last);
	quickSort(A, first, p - 1);
	quickSort(A, p + 1, last);

}
int main()
{
int m;
char B[100];
 int A[100];
 int i,n;
 do
 {
 cout<<"\n1. Integer  ";
 cout<<"\n2. Char";
 cout<<"\n3. Exit"<<endl;
 cout<<"\nEnter option : ";
 cin>>m;
if(m==1)
{
cout<<"\nEnter value of n:"<<endl;
cin>>n;
cout<<"\nEnter the elements:"<<endl;
	for(i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"\nBEFORE SORTING"<<endl;
    for(i=0;i<n;i++)
    {
    cout<<A[i]<<" ";
    }
    cout<<"\n__________________"<<endl;
    cout<<"\nINTEGER ARRAY"<<endl;
	quickSort(A, 0, n - 1);

	for (int i = 0; i < n; i++)
        {
            cout<<A[i]<< " ";
	}
}
	if(m==2)
{
cout<<"Enter value of n:"<<endl;
cin>>n;
cout<<"\nEnter the elements:"<<endl;
	for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    cout<<"\nBEFORE QUICK SORT"<<endl;
    for(i=0;i<n;i++)
    {
    cout<<B[i]<<" ";
    }
    cout<<"\n__________________"<<endl;
    cout<<"\nCHARACTER ARRAY"<<endl;
	quickSort(B, 0, n - 1);

	for (int i = 0; i < n; i++)
        {
             cout<<B[i]<< " ";
        }
}
 }
while(m!=3);
	return 0;
}
