#include <iostream>
using namespace std;

void computeLpsArray(char* pat, int pat_length, int* lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while( i < pat_length )
    {
        if( pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len - 1];

            }
            else
            {
                lps[i] = len;
                i++;
            }

        }
    }
}
void KMPSearch(char* pat, char* txt)
{
    int pat_length = strlen(pat);
    int txt_length = strlen(txt);

    int *lps = new int[pat_length];

    computeLpsArray(pat, pat_length, lps);

    int i = 0;
    int j = 0;

    while(i < txt_length)
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }
        
        if(j == pat_length)
        {
            printf("Found index in %d\n", i - j);
            j = lps[j - 1];
        }
        else if( i < txt_length && txt[i] != pat[j])
        {
            if( j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }

}

int main()
{
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
    KMPSearch(pat, txt);

    return 0;
}