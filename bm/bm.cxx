#include"bm.h"
#include<string.h>
int grepBm(char * str, char *pattern)
{
    if (!str || !pattern)
        return -1;
    int len = length(pattern);
    int preprocess[256];
    // initial preprocess
    // 坏字符  
    int i=0;
    for(;i<256;++i)
    {
        preprocess[i] = len;
    }
    for(i=0;i<len;++i)
    {
        preprocess[pattern[i]]=len-i-1;
    }
    char *p=pattern
    int i=0;
    for(;p;i++)
    {
        ++p;
    }
// 
    return -1;
}
