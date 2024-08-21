#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool valid(int n1, string n) // check bin,hex,oct and dec valid
{
    if (n1 == 1) // binvalid
    {
        for (char digit : n)
        {
            if (digit != '1' && digit != '0')
            {
                return false;
            }
        }
        return true;
    }
    else if (n1 == 2) // decvalid
    {
        for (char digit : n)
        {
            if (!(digit >= '0' && digit <= '9'))
            {
                return false;
            }
        }
        return true;
    }
    else if (n1 == 3) // octvalid
    {
        for (char digit : n)
        {
            if (!(digit >= '0' && digit <= '7'))
            {
                return false;
            }
        }
        return true;
    }
    else // hexvalid
    {
        for (char digit : n)
        {
            if (!((digit >= '0' && digit <= '9') || (digit >= 'A' && digit <= 'F')))
            {
                return false;
            }
        }
        return true;
    }
}

int todecimal(int num, string nnum) //covert to decimal
{
    int ans=0;
    if (num == 1)
    {
        int rem, i = 0;
        int n = stoi(nnum);
        while (n > 0)
        {
            rem = n % 10;
            n = n / 10;
            ans = rem * pow(2, i) + ans;
            i++;
        }
        cout << "Decimal Number is :- " << ans<<endl;
    }
    else if (num == 3)
    {
        int rem,  i = 0;

        int n = stoi(nnum);
        while (n > 0)
        {
            rem = n % 10;
            ans = rem * pow(8, i) + ans;
            i++;
            n = n / 10;
        }
        cout << "Decimal Number is :- " << ans<<endl;
    }
    else
    {
        int len = nnum.size();
        int  rem;

        for (int i = 0; i < len; i++)
        {
            char digit = nnum[(len - 1) - i];
            if (digit >= '0' && digit <= '9')
            {
                rem = digit - '0';
            }
            else
            {
                rem = digit - 'A' + 10;
            }
            ans += rem * pow(16, i);
        }
        cout << "Decimal Number is :- " << ans<<endl;
    }
return ans;    
}

int fromdecimal(int num, string num2) //covert to bin , oct and hex
{
    int rem, ans = 0, mul = 1;
    if (num == 1) // binary
    {
        int n10 = stoi(num2);
        while (n10 > 0)
        {
            rem = n10 % 2;
            n10 = n10 / 2;
            ans = rem * mul + ans;
            mul = mul * 10;
        }
        cout << "Binary Number is :- " << ans;
    }
    else if (num == 3) // octal
    {
        int n11 = stoi(num2);
        while (n11 > 0)
        {
            rem = n11 % 8;
            n11 = n11 / 8;
            ans = rem * mul + ans;
            mul = mul * 10;
        }
        cout << "Octal Number is :- " << ans;
    }
    else // hexadecimal
    {
        char hex[100];
        int rem = 0, i = 0;
        int n12 = stoi(num2);
        while (n12 > 0)
        {
            rem = n12 % 16;
            n12 = n12 / 16;
            if (rem < 10)
            {
                hex[i] = 48 + rem;
                i++;
            }
            else
            {
                hex[i] = 55 + rem;
                i++;
            }
        }
        cout<<"Hexadecimal Number is:- ";
        for (int j = i - 1; j >= 0; j--)
        {
            cout  <<hex[j];
        }
    }
return 0;    
}

string baseNumber(int bn)
{
    switch (bn)
    {
    case 1:
        return "Binary";
        break;
    case 2:
        return "Decimal";
        break;
    case 3:
        return "Octal";
        break;
    case 4:
        return "Hexadecimal";
        break;
    default:
        return "Unknown";
        break;
    }
}

void same(string nnn3) // for same to same
{
    cout << nnn3;
}

int check(int number) // for default
{
    if (!(number >= 1 && number <= 4))
    {
        cout << "Invalid Input" << endl;
        exit(1);
    }
    return true;
}

int main()
{
    int n1, n2;
    string num;
    cout << "Choose the input base (1: Binary, 2: Decimal, 3: Octal, 4: Hexadecimal): ";
    cin >> n1;
    check(n1);

    cout << "Enter " << baseNumber(n1) << " :- ";
    cin >> num;
    if (!valid(n1, num)) // check bin,dec,oct and hex
    {
        cout << "Invalid Input" << endl;
        exit(1);
    }

    cout << "Convert to (1: Binary, 2: Decimal, 3: Octal, 4: Hexadecimal): ";
    cin >> n2;
    check(n2);

    cout << "Converting " << baseNumber(n1) << " to " << baseNumber(n2) << endl;
    if (n1 == n2)
    {
        same(num);
    }
    else if (n1 == 2)
    {
        fromdecimal(n2, num);
    }
    else if (n2 == 2)
    {
        todecimal(n1, num);
    }
    else 
    {
        int var = todecimal(n1,num);
        fromdecimal(n2,to_string(var));
    }
return 0;
}