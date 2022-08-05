#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define n strlen(g)

char cs[120], t[120], g[] = "100000111";
int len, c, e;

void xor () {
    for (c = 1; c < n; c++)
    {
        cs[c] = ((cs[c] == g[c]) ? '0' : '1');
    }
}

void crc()
{
    for(e=0;e<n;e++){
        cs[e]=t[e];
    }
    do{
        if(cs[0]=='1'){
            xor();
        }
        for(c=0;c<n-1;c++){
            cs[c] = cs[c+1];
        }
        cs[c]=t[e++];
    }while(e<=len+n-1);
}

int main()
{
    printf("Enter the polynomial");
    scanf("%s", t);
    len = strlen(t);
    for (int i = len; i < len + n - 1; i++)
    {
        t[i] = '0';
    }
    printf("Modified %s\n", t);
    crc();
    printf("Checksum %s\n", cs);
    for (int i = len; i < len + n - 1; i++)
    {
        t[i] = cs[i-len];
    }
    printf("Modified %s\n",t);
    crc();
    printf("Checksum %s\n", cs);
    for (e = 0; (e < n - 1) && (cs[e] != '1'); e++);
    if (e < n - 1)
        printf("error detected\n");
    else
        printf("error is not detected\n");

    t[4] = '1';
    crc();
    printf("Checksum %s\n", cs);
    for (e = 0; (e < n - 1) && (cs[e] != '1'); e++);
    if (e < n - 1)
        printf("error detected\n");
    else
        printf("error is not detected\n");
    return 0;
}