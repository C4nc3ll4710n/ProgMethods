#include "hlpr.h"


char* cp_str(const char *s)
{
    if (s == nullptr) return nullptr;
    char *nw = new char[strlen(s)+1];
    strcpy(nw, s);
    return nw;
}


unsigned int get_prime(unsigned int n)
{
    if (n < 2) return 2;
    unsigned int ans = n;
    while (true)
    {
        bool prime_fl = true;
        for (unsigned int i = 2; i*i <= ans; i++)
        {
            if (ans%i == 0)
            {
                prime_fl = false;
                break;
            }
        }
        if(prime_fl)
            return ans;
        ans++;
    }
}