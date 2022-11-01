#include <iostream>

bool bears(int n);

int main(int argc, char** argv) {
int number, sol;
scanf ("%d",&number);
printf("\nThe answer is %d",bears(number));
return 0;
}

bool bears (int n)
{
int temp;
if (n<42)
return 0;
else
{ if (n==42) return 1;
if ((n % 2) == 0)
{ temp=n-n/2;
if (bears(temp)==1) return 1;
}
if ((n % 3) == 0 || (n % 4) == 0)
{ temp=n-(n%10)*((n%100)/10);
if (temp!=n)
if (bears(temp)==1) return 1;
}
if ((n % 5) == 0 )
{ temp=n-42;
if (bears(temp)==1) return 1;
else return 0;
}
return 0;
}
}
