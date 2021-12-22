#include "facilities.h"
#include <Windows.h>

bool isPowerOf(int num, int pwr)
{
    if (num % pwr == 0)
    {
        if (num / pwr == 1)
        {
            return true;
        }
        return isPowerOf(num / pwr, pwr);
    }
    return false;
}

std::string tolower(std::string s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool check(char name[261])
{
    int o = 0;
    bool flag;
    while (name[o] != '\000' && o < 261)
    {
        o++;
    }
    while (name[o] != '.' && o > 0)
    {
        o--;
    }

    if (name[o] == '.')
    {
        std::string s;
        while (name[o] != 0)
        {
            s += name[o];
            o++;
        }
        if (s == ".mp3" || s == ".wav")
        {
            return true;
        }
    }
    return false;
}

void refresh()
{
    Sleep(10);
    keybd_event(0x36, 0, KEYEVENTF_UNICODE, 0);
    Sleep(1);
    keybd_event(0x36, 0, KEYEVENTF_KEYUP, 0);
    Sleep(1);
    keybd_event(0x0D, 0, KEYEVENTF_UNICODE, 0);
    Sleep(1);
    keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0);
    Sleep(10);
}