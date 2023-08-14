#include<iostream>
using namespace std;
int n;
template<typename T>
void inSort(T A[100])
 {
   int i,j;
   T key;
   for(int i=1;i<n;i++)
    {
      key=A[i];
      j=i-1;
      while(j>=0&&A[j]>key)
       {
         A[j+1]=A[j];
         j=j-1;
      }
      A[j+1]=key;
    }
cout<<"\nSorted array: ";
 for(i=0;i<n;i++)
 {
 cout<<" "<<A[i];

    }}
int main()
{
 int option;
 char C[100];
 int A[100];
 float B[100];

 int i;

 cout<<"******************";
 do
 {
 cout<<"\n 1. Integer : ";
 cout<<"\n 2. Float : ";
 cout<<"\n 3. char:";
 cout<<"\n 4. Exit : "<<endl;
 cout<<"\n Enter option : ";
 cin>>option;
 switch(option)
 {
 case 1:
 {
 cout<<"\nEnter Total Number Of Integer Elements:";
 cin>>n;
 cout<<"\nEnter Integer Elements:";
 for(i=0;i<n;i++)
 {
 cin>>A[i];
 }
 inSort(A);

 break;
 }
 case 2:
 {
 cout<<"\nEnter Total Number Of Float Elements:";
 cin>>n;
 cout<<"\nEnter Float Elements:";
 for(i=0;i<n;i++)
 {
 cin>>B[i];
 }
 inSort(B);

 break;
 }
case 3:
 {
 cout<<"\nEnter Total Number Of char Elements:";
 cin>>n;
 cout<<"\nEnter char Elements:";
 for(i=0;i<n;i++)
 {
 cin>>C[i];
 }
 inSort(C);

 break;
 }
 case 4:

 default:
 {
 cout<<"End";
 }
 }
 }
 while(option!=4);
return 0;
}


