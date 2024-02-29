#include <iostream>

using namespace std;
struct cuvinte
{
    int len;
    char cuv[250];
}v[100];
int litera(char c)
{
    if ((c >= 'A' && c <='Z') || (c >= 'a'  && c <= 'z')) return 1;
    return 0;
}
int needswap(cuvinte c1, cuvinte c2)
{
    int n = c1.len;
    if (c1.len < c2.len) return 1;
    else if (c1.len == c2.len)
    {
        int swapneeded = 0;
        for (int i = 0; i < c1.len && swapneeded == 0; i++)
        {
            if (c1.cuv[i] < c2.cuv[i]) swapneeded = -1;
            else if (c1.cuv[i] > c2.cuv[i]) swapneeded = 1;
        }
        if (swapneeded == 1) return 1;
    }
    return 0;
}
char s[250];
int n,i;
void swapstruct(cuvinte &c1, cuvinte &c2)
{
    char aux1[250];
    for (int i = 0;i < c1.len;i++) aux1[i] = c1.cuv[i];
    for (int i = 0;i < c2.len;i++) c1.cuv[i] = c2.cuv[i];
    for (int i = 0;i < c1.len;i++) c2.cuv[i] = aux1[i];
    int aux2;
    aux2 = c1.len;
    c1.len = c2.len;
    c2.len = aux2;
    c1.cuv[c1.len] = '\0';
    c2.cuv[c2.len] = '\0';
}

int main()
{
    scanf_s(" %[^\n]", s,250);
    i = n = 0;
    while (s[i] != NULL)
    {
        if (litera(s[i]))
        {
            if (s[i] >= 'a' && s[i] <= 'z') v[n].cuv[v[n].len++] = s[i];
            else v[n].cuv[v[n].len++] = s[i] + 32;
        }
        else if (litera(s[i - 1])) n++;
        i++;
    }
    if (v[n].len > 0 || litera(s[i - 1])) n++;
    for (int i = 0;i < n - 1; i++)
        for (int j = i + 1;j < n;j++)
            if (needswap(v[i], v[j])) swapstruct(v[i], v[j]);
    for (int i = 0;i < n;i++)
        printf("%s\n", v[i].cuv);
        
}

