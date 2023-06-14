#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	// /***********ft_memcpy************/
	// printf("**********ft_memcpy************\n");

	// char str[] = "my name is huipark";
	// char str2[] = "ha jonna";
	// char str3[] = "my name is huipark";
	// char str4[] = "ha jonna";
	// char str5[] = "ha jonna";
	// char str6[] = "ha jonna";
	// int arr[21] = {0,1,2,3,-4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	// int arr2[21] = {0,1,2,3,-4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	// memcpy(str + 2, str2, sizeof(str2) + 1);
	// ft_memcpy(str3 + 2, str4, sizeof(str4) + 1);
	// printf("str memcpy = %s\n", str);
	// printf("str ft_memcpy = %s\n", str3);
	// memcpy(arr + 4 , arr , sizeof(int) * 15);
	// ft_memcpy(arr2 + 4 , arr2, sizeof(int) * 15);
	// printf("memcpy = ");
	// for(int i = 0 ; i <= 20 ; i++)
	// {
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");
	// printf("ft_memcpy = ");
	// for(int i = 0 ; i <= 20 ; i++)
	// {
	// 	printf("%d ", arr2[i]);
	// }
	// printf("\n");
	// memcpy(str5 + 4, str5, sizeof(char) * 2);
	// ft_memcpy(str6 + 4, str6, sizeof(char) * 2);
	// printf("str memcpy = %s\n", str5);
	// printf("str ft_memcpy = %s\n", str6);
	// printf("\n\n");


	// /*********ft_strncmp********/
	// printf("********ft_strncmp*********\n");

	// char	*s1 = "hello world";
	// char	*s2 = "hellow world";
	// char	*LONG_MAX = "9223372036854775807";
	// char	*LONG_MIN = "-9223372036854775809";

	// printf("%d     %d\n", strncmp(s1, s2, 4), ft_strncmp(s1, s2, 4));
	// printf("%d     %d\n", strncmp(s1, s2, 5), ft_strncmp(s1, s2, 5));
	// printf("%d     %d\n", strncmp(s1, s2, 11), ft_strncmp(s1, s2, 11));
	// printf("%d     %d\n", strncmp(s1, s2, 12), ft_strncmp(s1, s2, 12));
	// printf("%d     %d\n", strncmp(s1, s2, 15), ft_strncmp(s1, s2, 15));
	// printf("%d     %d\n", strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
	// printf("%d     %d\n", strncmp(s1, s2, 0), ft_strncmp(s1, s2, 0));
	// printf("\n\n");

	
	// /*********ft_atoi**********/
	// printf("********ft_atoi*********\n");

	// printf("%d     %d\n", atoi("-9223372036854775807"), ft_atoi("-9223372036854775807"));
	// printf("%d     %d\n", atoi("9223372036854775806"), ft_atoi("9223372036854775806"));

	// printf("\n\n");
	// /**********ft_itoa**********/
	// printf("********ft_itoa*********\n");

	// printf("123 = %s\n", ft_itoa(-123));
	// printf("123 = %s\n", ft_itoa(123));
	// printf("0 = %s\n", ft_itoa(0));
	// printf("0 = %s\n", ft_itoa(-0));
	// printf("2147483647 = %s\n", ft_itoa(2147483647));
	// printf("-2147483648 = %s\n", ft_itoa(-2147483648));
	// printf("-12345678 = %s\n", ft_itoa(-12345678));
	// printf("12345678 = %s\n", ft_itoa(12345678));
	// printf("49582839 = %s\n", ft_itoa(49582839));
	// printf("\n\n");

	// /**********ft_strchr***********/
	// printf("/***********ft_strchr**********/\n");

	// printf("%s      %s\n", strchr("hello world", 'w'), ft_strchr("hello world", 'w'));
	// printf("%s      %s\n", strchr("hello world", 3), ft_strchr("hello world", 3));
	// printf("%s      %s\n", strchr("hello world", 'q'), ft_strchr("hello world", 'q'));
	// printf("%s      %s\n",strchr("teste", 1024), ft_strchr("teste", 1024));
	// printf("%s\n", strchr("teste", 1024));
	// printf("%s\n", ft_strchr("teste", 1024));
	// printf("\n\n");

	// /**********ft_strrchr***********/
	// printf("/***********ft_strrchr**********/\n");
	// char *asd = "teste";
	
	// printf("%s    %s\n", strrchr("teste", 'e'), ft_strrchr("teste", 'e'));
	// printf("%s    %s\n", strrchr("teste", 'x'), ft_strrchr("teste", 'x'));
	// printf("%p\n", asd);
	// printf("%p    %p\n", strrchr(asd, '\0'), ft_strrchr(asd, '\0'));


	// /**********ft_strlcat**********/
	// printf("/************ft_strlcat***********/\n");

	// char a[20] = "123456";
	// char *b = "789";
	// char c[20] = "123456";
	// char *d = "789";
	// printf("dest = \"123456\" src = \"789\"\n");
	// printf("return = %ld      %ld\n", strlcat(a, b, 10), ft_strlcat(c,d, 10));
	// printf("         %s       %s\n", a,c);
	// printf("\n\n");

	// /**********ft_strnstr**********/
	// printf("/**********ft_strnstr************/\n");

	// printf("%s       %s\n", strnstr("hello huipark", "hui", 7), ft_strnstr("hello huipark", "hui", 7));
	// printf("%s       %s\n", strnstr("hello huipark", "hui", 6), ft_strnstr("hello huipark", "hui", 6));
	// printf("%s       %s\n", strnstr("hello huipark", "hui", 0), ft_strnstr("hello huipark", "hui", 0));
	// printf("%s       %s\n", strnstr("hello huipark", "hui", 8), ft_strnstr("hello huipark", "hui", 8));
	// printf("%s       %s\n", strnstr("hello huipark", "hui", 9), ft_strnstr("hello huipark", "hui", 9));
	// printf("%s       %s\n", strnstr("123", "1", 0), ft_strnstr("123", "1", 0));
	// printf("\n\n");

	/*********ft_split***********/
	printf("/*********ft_split***********/\n");

	char *qwe = "BHC.BBQ.NENE.PUREDARK.GOUBNE.HOSICK.RICECHICKEN..chicken.GOOD";
	char **res = ft_split(qwe, '.');
	printf("src = BHC.BBQ.NENE.PUREDARK.GOUBNE.HOSICK.....chicken.GOOD\n");
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}
	printf("\n");
	char **qw = ft_split("hello!", ' ');
	char **qwee = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^",'^');
	while (*qwee)
	{
		printf("%s\n", *qwee);
		qwee++;
	}
	while (*qw)
	{
		printf("%s\n", *qw);
		qw++;
	}

	printf("\n\n");
	/*********ft_strtrim***********/
	printf("/*********ft_strtrim***********/\n");
	printf("%s\n", ft_strtrim("144442345678714", "41"));
}