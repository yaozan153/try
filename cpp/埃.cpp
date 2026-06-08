//#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
char *a = (char*)malloc(sizeof(char)*1<<30);
int main(){
	long long l,r;
	scanf("%lld%lld",&l,&r);
	//printf("%lld%lld",l,r);
	for(long long i = 0; i <= r; i++)
	{
	    a[i] = 1;
	}
	a[0] = 0;a[1] = 0;
	for(long long i = 2; i <= r; i++)
	{
		if(a[i])
		{
			for(long long j = 2; j*i < r; j++)
			{
				a[i*j] = 0;
			}
		}
	}
	int count = 0;
	for(long long i = l; i < r; i++)
	{
		if(a[i])
		{
		    count++;
		}
	}
	printf("%d",count);
	return 0;
}  
