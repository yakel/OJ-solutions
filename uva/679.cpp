#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;

struct bign
{
    int d[maxn];
    int len;

    bign()
    {
        memset(d, 0, sizeof(d));
        len = 1;
    }

    bign(int num)
    {
        *this = num;
    }

    bign(char * num)
    {
        *this = num;
    }

    bign operator = (const char * num)
    {
        len = strlen(num);
        for(int i = 0; i < len; i++)
            d[i] = num[len-1-i] - '0';
        return *this;
    }

    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    bign operator + (const bign& b) const
    {
        bign c;
        c.len = 0;
        int g = 0;
        for(int i = 0; i < max(len, b.len) || g; i++)
        {
            int x = g;
            if(i < len)   x += d[i];
            if(i < b.len)   x += b.d[i];
            c.d[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    bign operator += (const bign& b)
    {
        *this = *this + b;
        return *this;
    }

    void clean()
    {
        while(len > 1 && !d[len-1])
            len--;
    }
    
    bign operator - (const bign& b)
    {
        bign c;
        c.len = 0;
        int g = 0;
        for(int i = 0; i < len; i++)
        {
            int x = d[i] - g;
            if(i < b.len)   x -= b.d[i];
            if(x >= 0)   g = 0;
            else 
            {
                g = 1;
                x += 10;
            }
            c.d[c.len++] = x;
        }
        c.clean();
        return c;
    }

    bign operator * (const bign& b)
    {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < b.len; j++)
                c.d[i+j] += d[i] * b.d[j];
        for(int i = 0; i < c.len-1; i++)
        {
            c.d[i+1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
        c.clean();
        return c;
    }

    bool operator < (const bign& b) const
    {
        if(len != b.len)   return len < b.len;
        for(int i = len-1; i >= 0; i--)
            if(d[i] != b.d[i])   return d[i] < b.d[i];
        return false;
    }

    bool operator > (const bign& b) const
    {
        return b < *this;
    }

    bool operator <= (const bign& b) const
    {
        return !(b < *this);
    }

    bool operator >= (const bign& b) const
    {
        return !(*this < b);
    }

    bool operator != (const bign& b) const
    {
        return b < *this || *this < b;
    }

    bool operator == (const bign& b) const
    {
        return !(b < *this) && !(b > *this);
    }

    string str() const
    {
        string res = "";
        for(int i = 0; i < len; i++)
            res = (char)(d[i]+'0') + res;
        if(res == "")   res = "0";
        return res;
    }
};

istream& operator >> (istream &in, bign& x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream & out, const bign& x)
{
    out << x.str();
    return out;
}

int main()
{
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    bign ans = 0, x;
    while(cin >> x)
    {
        if(x == 0)   break;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
