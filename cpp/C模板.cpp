#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct GUAHAO{
	int hh;
	int mm;
	char *ss;
	char *nn;
	char *dd;
	int hh2;
	int mm2;
};
int main() {
    int n;
    scanf("%d",&n);
    struct GUAHAO a[n+1]; 
    for(int i = 1; i <= n; i++)
	{
		a[i].ss = (char*)malloc(12*sizeof(char));
		scanf("%d%d%s",&a[i].hh,&a[i].mm,a[i].ss);
	} 
    return 0;
}
