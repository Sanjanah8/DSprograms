#include<iostream>
using namespace std;
int n;
template<class T>
void selsort(T A[100])
{
 int i,j,min;
 T temp;
 for(i=0;i<n-1;i++)
 {
 min=i;
 for(j=i+1;j<n;j++)
 {
 if(A[j]<A[min])
 min=j;
 }
 temp=A[i];
 A[i]=A[min];
 A[min]=temp;
 }
 cout<<"\nSorted array: ";
 for(i=0;i<n;i++)
 {
 cout<<" "<<A[i];
 }
}
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
 selsort(A);

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
 selsort(B);

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
 selsort(C);

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


