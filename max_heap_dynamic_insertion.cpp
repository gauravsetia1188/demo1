#include<bits/stdc++.h>
using namespace std;
#define ll long long

int hsize;
int arr[100000];
arr[0]=INT_MAX;
void restoreUp()
{
	int i=hsize;
	int k=arr[hsize];
	int par=i/2;
	while(k>arr[par])
	{
		arr[i]=arr[par];
		i=par;
		par=i/2;
	}
	arr[i]=k;
}


// used to delete a node from the heap and heapify , returns the maximum node
int restoreDown() 
{
	int number = arr[1]; //1 based indexing, stores the maximum element
	arr[1]=arr[hsize];
	hsize--;

	int i=1;

	int lchild=2*i;
	int rchild=lchild+1;
	while(rchild<=hsize)
	{
		if(arr[i]>=arr[lchild] && arr[i]>=arr[rchild])
		{
			return arr[i];
		}
		else if(arr[lchild]>arr[rchild])
		{
			arr[i]=arr[lchild];
			i=lchild;
		}
		else
		{
			arr[i]=arr[rchild];
			i=rchild;
		}
		 lchild=2*i;
	rchild=lchild+1;
	}
	// if no of nodes is even
	if(lchild==hsize && num<arr[lchild])
	{
		arr[i]=arr[lchild];
		i=lchild;
	}
	arr[i]=num;
	return arr[1];
}



int main()
{
	
	cout<<"Enter no of elements to be inserted into the heap\n";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		hsize++;
		cin>>arr[hsize];
		restoreUp(); //This corresponds to heapify up
	}



}