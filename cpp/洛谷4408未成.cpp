#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct I{
	int hh;
	int mm;
	char *ss;
	char *nn;
	char *dd;
	int hh2;
	int mm2;
};
struct P{
	int hh;
	int mm;
	char *nn;
	int hh2;
	int mm2;
	int ok;
	int late;
};
struct D{
	char *dd;
	int num;
	struct P p[1440];
};
void clear_stdin() {
    int c;
    // 只清空换行符，避免清空有效字符（关键修改！）
    while ((c = getchar()) != '\n' && c != EOF);
}
//int cmp(const void*a,const void*b)
//{
//    struct I *t1 = (struct I*)a;
//    struct I *t2 = (struct I*)b;
//    if(t1->hh*60+t1->mm!=t2->hh*60+t2->mm)
//    {
//    	return t1->hh*60+t1->mm-(t2->hh*60+t2->mm);
//	}
//	if(t1->hh*60+t1->mm==t2->hh*60+t2->mm) 
//	{
//		return 0;
//	}
//}


int main() {
    int n;
    scanf("%d",&n);
    clear_stdin();
    struct I *a = (struct I *)malloc((n+1)*sizeof(struct I)) ; 
    struct D *d = (struct D *)malloc((n+1)*sizeof(struct D));
    int o = 1;
    for(int i = 1; i <= n; i++)
    {
    	d[i].num = 0;
    	d[i].dd = NULL;
    	for (int j = 0; j < 1440; j++) {
            d[i].p[j].nn = NULL;
            d[i].p[j].ok = 0;
            d[i].p[j].late = 0;
        }
	}
    for(int i = 1; i <= n; i++)
	{
		a[i].hh = 0;
        a[i].mm = 0;
		a[i].ss = (char*)malloc(20*sizeof(char));
		a[i].nn = NULL;
        a[i].dd = NULL;
        a[i].hh2 = 0;
        a[i].mm2 = 0;
		scanf("%d %d %s", &a[i].hh, &a[i].mm, a[i].ss);
		if(strcmp(a[i].ss, "appointment") == 0)
		{
			a[i].nn = (char*)malloc(20*sizeof(char));
			a[i].dd = (char*)malloc(20*sizeof(char));
			scanf("%s %s %d %d", a[i].nn, a[i].dd,&a[i].hh2,&a[i].mm2);
		    int flag = 0,record = -1;
		    for(int j = 1; j < o; j++)
		    {
		    	if(d[j].dd!=NULL&&!strcmp(d[j].dd,a[i].dd))
		    	{
		    		flag = 1;
		    		record = j;
		    		break;
				}
			}
			if(!flag)
			{
			    int k = d[o].num+1;
				d[o].dd = (char*)malloc(20*sizeof(char));
				strcpy(d[o].dd,a[i].dd);
				d[o].p[k].nn = (char*)malloc(20*sizeof(char));
				strcpy(d[o].p[k].nn,a[i].nn);
				d[o].p[k].hh = a[i].hh;
				d[o].p[k].mm = a[i].mm;
				d[o].p[k].hh2 = a[i].hh2;
				d[o].p[k].mm2 = a[i].mm2; 
				
				d[o].num = k;
				o++;
			}else{
				int k = d[record].num+1;
				d[record].p[k].nn = (char*)malloc(20*sizeof(char));
				strcpy(d[record].p[k].nn,a[i].nn);
				d[record].p[k].hh = a[i].hh;
				d[record].p[k].mm = a[i].mm;
				d[record].p[k].hh2 = a[i].hh2;
				d[record].p[k].mm2 = a[i].mm2; 
				d[record].num = k;
			}
		} 
		if(strcmp(a[i].ss, "register") == 0)
		{
			a[i].nn = (char*)malloc(20*sizeof(char)); 
			scanf("%s",a[i].nn);
		}
		if(strcmp(a[i].ss, "query") == 0)
		{
			a[i].dd = (char*)malloc(20*sizeof(char));
			scanf("%s",a[i].dd);
			int flag = 0;
			for(int j = 1; j < o; j++)
			{
				if(strcmp(d[j].dd,a[i].dd)==0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				d[o].dd = (char*)malloc(20*sizeof(char));
				strcpy(d[o].dd,a[i].dd);
				o++;
			}
		}
		clear_stdin();
	}
//	qsort(a+1,n,sizeof(I),cmp); 
//    printf("\n"); 
//	for(int i = 1; i <= n; i++)
//	{
//		printf("%02d %02d ",a[i].hh,a[i].mm);
//		printf("%s ",a[i].ss);
//		if(strcmp(a[i].ss, "appointment") == 0)
//		{
//			printf("%s %s %02d %02d", a[i].nn, a[i].dd,a[i].hh2,a[i].mm2);
//		}
//		if(strcmp(a[i].ss, "register") == 0)
//		{
//			printf("%s",a[i].nn);
//		}
//		if(strcmp(a[i].ss, "query") == 0)
//		{
//			printf("%s",a[i].dd);
//		}
//		printf("\n");
//	}  
//	for(int i = 1;i < o; i++)
//	{
//		if (d[i].dd == NULL) continue;
//		printf("%d %s\n",d[i].num,d[i].dd);
//		for(int j = 1; j <= d[i].num; j++)
//		{
//			if (d[i].p[j].nn == NULL) continue;
//			printf("%02d %02d %s %02d %02d\n",d[i].p[j].hh,d[i].p[j].mm,d[i].p[j].nn,d[i].p[j].hh2,d[i].p[j].mm2);
//		}
//	} 
	for(int i = 1; i <= n; i++)
	{
		//printf("%d\n",i); 
		if(strcmp(a[i].ss, "register") == 0)
		{
			int find = 0;
			for(int j = 1; j < o; j++)
			{
				for(int k = 1; k <= d[j].num; k++)
				{
					if(strcmp(a[i].nn,d[j].p[k].nn)==0)
					{
						find = 1;
					    int timer = a[i].hh*60+a[i].mm;
					    int timea = d[j].p[k].hh2*60+d[j].p[k].mm2;
					    if(d[j].p[k].ok == 1)
					    {
					    	printf("Fail\n");
					    	break; 
						}
					    if(timer<timea-60)
					    {
					    	printf("Fail\n");
					    	break; 
						}else if(timer>=timea-60&&timer<=timea){
							d[j].p[k].ok = 1;
							printf("Success\n");
							break; 
						}else{
							d[j].p[k].ok = 1;
							d[j].p[k].late = 1;
							printf("Success\n");
							break;
						}
					}
				}	
			}
			if(find==0)
			{
				printf("Fail\n");
			}
		}
		if(strcmp(a[i].ss, "query") == 0) 
		{
			for(int j = 1; j < o; j++)
			{
				if(strcmp(a[i].dd, d[j].dd) == 0)
				{
					int flaglate = 0;
					int flag = 0;
					for(int k = 1; k <= d[j].num; k++)
					{
						if(d[j].p[k].late == 0)
						{
						    if(d[j].p[k].ok == 1)
						    {
							d[j].p[k].ok = 0;
							flag = 1;
							printf("%c",d[j].p[k].nn[0]);
							for(int l = 1; l < strlen(d[j].p[k].nn)-1; l++)
							{
								printf("*");
							}
							printf("%c\n",d[j].p[k].nn[strlen(d[j].p[k].nn)-1]);
							flaglate = 1;
							strcpy(d[j].p[k].nn,"0");
							break;
						    }
						}
					}
					if(flaglate == 0)
					{
						for(int k = 1; k <= d[j].num; k++)
				    	{
						    if(d[j].p[k].ok == 1)
						    {
							d[j].p[k].ok = 0;
							flag = 1;
							printf("%c",d[j].p[k].nn[0]);
							for(int l = 1; l < strlen(d[j].p[k].nn)-1; l++)
							{
								printf("*");
							}
							printf("%c\n",d[j].p[k].nn[strlen(d[j].p[k].nn)-1]);
							flaglate = 1;
							strcpy(d[j].p[k].nn,"0");
							break;
						    }
					    }
					}
					if(flag == 0)
					{
						printf("No patient\n");
					}
				}
			}
			
		}
	} 
    return 0;
}
