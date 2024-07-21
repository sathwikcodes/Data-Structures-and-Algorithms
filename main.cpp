#include <windows.h>
#include <stdio.h>

int main()
{
    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    GetLocalTime(&lt);

    printf("The system time is: %02d-%02d-%02d %02d:%02d:%02d\n",
           st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond);
    printf("The local time is: %02d-%02d-%02d %02d:%02d:%02d\n",
           lt.wDay, lt.wMonth, lt.wYear, lt.wHour, lt.wMinute, lt.wSecond);

    return 0;
}
