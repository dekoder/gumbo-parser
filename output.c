/*************************************************************************
	> File Name: my_test_gumbo.c
	> Author: 
	> Mail: 
	> Created Time: 2015年08月17日 星期一 13时57分17秒
 ************************************************************************/

#include "gumbo.h"
#include <stdio.h>
#include <string.h>

#define slen 200

int main(int argc, char **argv) {

    int flags[slen] = {0};
    char s[slen] = {0};

    char *black_script = "</noscript";
    char *p_black = NULL;
    char *cur_black = NULL;

    int cur = 0;
    int index;
    for (int i = 1; i < argc; i++) {
        index = 0;
        while (cur < slen) {
            if (argv[i][index])
                s[cur++] = argv[i][index++];
            else {
                s[cur++] = ' ';
                break;
            }
        }
    }
    
    //防止最后有一个空格
    s[cur-1] = '\0';

    //过滤 </noscript ,注意要过滤全部
    cur_black = s;
    while (true) {
        p_black = strstr(cur_black, black_script);
        if (p_black == NULL)
            break;
        *(++p_black) = 'x';
        cur_black = p_black;
    }
    p_black = NULL;

    GumboOutput* output = gumbo_parse(s, flags);
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    for (int i = 0; i < slen && s[i]; i++) {
        if (flags[i] == 1)
            printf("x");
        else
            printf("%c", s[i]);

    }
    //printf("\n");
}

