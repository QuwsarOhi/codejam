#include<stdio.h>
#include<map>
#define max(a,b) a>b?a:b
using namespace std;
 
map<unsigned long,unsigned long>mp;
 
unsigned long f(unsigned long n)
{
	printf("%d\n", n);
if(n==0)
return 0;
if(mp[n]>0)
return mp[n];
else
{
unsigned long int c;
c=max(n,((f(n/2)+f(n/3)+f(n/4))));
mp[n]=c;
return mp[n];
}
}
 
 
int main()
{
unsigned int n;
while(scanf("%d",&n)>0)
{
printf("%lu\n",f(n));
}
return 0;
}
