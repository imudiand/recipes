#include "func.h"

int main(void) {
	char *name = "Harshit Imudianda";
	char dummy[18];

	mem_move(dummy, name, 18);

	printf("%s\n", name);
	printf("%s\n", dummy);	

	int retval;
	retval = atoi("-11");
	printf("%d\n", retval);


	char src[5]={'s','a','\0','c','h'};
    char strbuff[5];
    memset(strbuff, 0, 5);
    str_cpy(strbuff,src);
    printf("%s\n", strbuff);


    char *dupstr = str_dup(strbuff);
    printf("%s\n", dupstr);


    char strbuff2[5];
    memset(strbuff2, 0, 5);
    str_cpy(strbuff2,src);


    int res = str_cmp(strbuff, strbuff2);
    if (0 == res)
    	printf("%s\n", "Strings are equal");

    printf("%d\n", str_len(strbuff));

    char ch = 'f';
    char new_ch;
    new_ch = upper_case(ch);
    printf("%c\n", new_ch);

    if (is_upper_case(new_ch))
    	printf("%s\n", "Upper case");
   	if (!is_upper_case(ch))
    	printf("%s\n", "Lower case");

	return 0;
}