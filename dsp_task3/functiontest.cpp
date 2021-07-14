#include <iostream>

extern "C"
{
void connect();
int add(int a, int b);
}

void connect()
{
printf("Connected to C extension...\n");
}

int add(int a, int b)
{
return a + b;
}