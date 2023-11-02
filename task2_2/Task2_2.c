#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double sum(double x, double y)
{
return x + y;
}
double sub(double x, double y)
{
return x - y;
}
double multi(double x, double y)
{
return x * y;
}
double div(double x, double y)
{
return x/y;
}
double factorial(double x)
{
if (x < 0) {
return 0;
}
else if (x == 0) {
return 1;
}
else {
return (double)x * factorial(x - 1);
}
}
void menu()
{
char choice='d';
double x;
double y;
do
{
printf("Enter operation(Possible opirations:<+>,<->,<*>,</>,<!>) OR enter <n> to exit\n->");
scanf("%c", &choice);
switch (choice)
{
case ('+'):
printf("x: ");
scanf("%lf", &x);
printf("y: ");
scanf("%lf", &y);
printf("x + y = %.*lf\n",3, sum(x, y));
break;
case '-':
printf("x: ");
scanf("%lf", &x);
printf("y: ");
scanf("%lf", &y);
printf("x - y = %.*lf\n", 3, sub(x, y));
break;
case '*':
printf("x: ");
scanf("%lf", &x);
printf("y: ");
scanf("%lf", &y);
printf("x * y = %.*lf\n", 3, multi(x, y));
break;
case '/':
printf("x: ");
scanf("%lf", &x);
printf("y: ");
scanf("%lf", &y);
printf("x / y = %.*lf\n", 5, div(x, y));
break;
case '!':
printf("x: ");
scanf("%lf", &x);
printf("x! = %.*lf\n", 0, factorial(x));
break;
case 'n':
break;
case 'N':
break;
default:
printf("OOOPS... This operation isn't exist yet\n");
break;
}
int c;
while ((c = getchar()) != '\n' && c != EOF);

} while (choice != 'n' && choice != 'N');
}

int main()
{
menu();
}