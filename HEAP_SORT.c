#include<stdio.h>
void heapify(int arr[],int n,int i)//arrange element in heap,check left and right children
{
   int mx=i;
   int l=2*i+1;
   int r=2*i+2;
   if(l<n&&arr[l]>arr[mx])
   {
     mx=l;
   }
   if(r<n&&arr[r]>arr[mx])
   {
     mx=r;
   }

   if(mx!=i)
   {
     int temp=arr[i];
     arr[i]=arr[mx];
     arr[mx]=temp;
     heapify(arr,n,mx);
   }
}
void build_heap(int arr[],int n)
{
   //build heap;
  for(int i=n/2;i>=0;i--)
  {
    heapify(arr,n,i);
  }
  //heap sort

  for(int i=n-1;i>=0;i--)
  {
    int  temp=arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    heapify(arr,i,0);//one element delete and arrange heap agian
  }
  for(int i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
}
int main()
{

  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);

  }
  build_heap(arr,n);
}

