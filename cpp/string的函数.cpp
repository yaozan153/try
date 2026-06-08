#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//strcpy, strncpy, strcat, strncat
//strlen, strcmp, strchr, strrchr, strstr
//memset, memcpy strerror
#include<ctype.h>//isspace 
int main() {
	//isspace用于判断字符是不是空白字符
	//空白字符包括' '(空格符) '\f'（换页符）'\n'（换行符）
	//'\r'（回车符）'\t'（水平制表符）'\v'（垂直制表符） 
	system("pause"); 
	printf("isspace\n");
	char ch[] = "Hello\tWorld\n hi";
	printf("%s\n",ch);
    for (int i = 0; ch[i] != '\0'; i++) {
        if (isspace(ch[i])) {
            printf("字符 '%c' (ASCII: %d) 是空白字符\n", ch[i], ch[i]);
        } else {
            printf("字符 '%c' (ASCII: %d) 不是空白字符\n", ch[i], ch[i]);
        }
    }
    
    
    //strcpy, strncpy
    system("pause"); 
    printf("\nstrcpy, strncpy\n"); 
    printf("strcpy：\n");
    char dest[20];  // 目标数组需足够大
    const char *src = "Hello strcpy";
    
    strcpy(dest, src);  // 拷贝src到dest（含'\0'）
    printf("dest: %s\n", dest);  // 输出：dest: Hello strcpy
    
    printf("strncpy：\n");
    char dest2[10];
    const char *src2 = "Hi";  // 长度2（含'\0'）
    strncpy(dest2, src2, 5);   // 拷贝2字节+填充3个'\0'
    
    // 验证：dest[0]='H', dest[1]='i', dest[2]='\0', dest[3]='\0', dest[4]='\0'
    for (int i = 0; i < 5; i++) {
        printf("dest[%d] = %d\t", i, dest2[i]);
    }
    printf("\n%s\n",dest2); 
    printf("注意：cpy相比于cat会覆盖,cat是拼接\n\n");
    
	
	
	
	
	//strcat, strncat
	system("pause"); 
    printf("strcat, strncat\n");
    
    printf("strcat：\n");
    char dest3[20] = "Hello";  // 目标字符串（含'\0'，长度5）
    const char *src3 = "strcat";// 源字符串（长度6，含'\0'）
    
    strcat(dest3, src3);         // 从dest的'\0'位置（索引6）开始拼接
    printf("dest: %s\n", dest3);// 输出：Hello strcat
    
    // 验证内存：dest[6]='s', dest[7]='t', ..., dest[11]='\0'
    printf("dest长度：%zu\n", strlen(dest3)); // 输出：11（不含'\0'）
    
	printf("strncat：\n");
    char dest4[20] = "Hello ";  // 原有长度6（索引0-5：H e l l o 空格，索引6：'\0'）
    const char *src4 = "strncat test"; // 源字符串长度11
    strncat(dest4, src4, 4);     // 只拷贝src前4字节：s t r n
    
    printf("dest: %s\n", dest4); // 输出：Hello strn
    printf("dest长度：%zu\n", strlen(dest4)); // 输出：10（6+4，不含'\0'）
    
    // 验证终止符：dest[10] = '\0'
    printf("dest[10] = %d\n", dest4[10]); // 输出：0
    
    system("pause"); 
    printf("strcmp：\n");
    
    
    return 0;
} 
