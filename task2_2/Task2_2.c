#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

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
double power(double x, double y) {
double result = 1.0;
for (double i = 0; i < y; i++) {
result *= x;
}
return result;
}
double logarithm(double base, double number) {
if (base <= 1 || number <= 0) {
printf("Логарифм не определен для заданных значений\n");
return -1.0;
}
double result = log10(number) / log10(base);

return result;
}
double cosine(double x)
{
double angle_radians = x * (3.14 / (double)180);

return cos(angle_radians);
}
double sinus(double x)
{
double angle_radians = x * (3.14 / (double)180);

return sin(angle_radians);
}


void menu()
{
char choice='d';
int flag = 0;
double x;
double y;
do
{
printf("Enter operation(Possible opirations:<+>,<->,<*>,</>,<!>,<^>,<log>,<sin>,<cos>) OR enter <n> to exit\n->");
scanf("%c", &choice);
int c;
while ((c = getchar()) != '\n' && c != EOF);
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
case '^':
printf("x: ");
scanf("%lf", &x);
printf("y(not fractional): ");
scanf("%lf", &y);
printf("x ^ y = %.*lf\n", 5, power(x, y));
break;
case 'l':
printf("x(base of logarithm): ");
scanf("%lf", &x);
printf("y(number): ");
scanf("%lf", &y);
printf("logx(y) = %.*lf\n", 5, logarithm(x, y));
break;
case 'c':
printf("x(degrees): ");
scanf("%lf", &x);
printf("cosx = %.*lf\n", 5, cosine(x));
break;
case 's':
printf("x(degrees): ");
scanf("%lf", &x);
printf("sinx = %.*lf\n", 5, sinus(x));
break;
case 'n':
flag = 1;
break;
case 'N':
flag = 1;
break;
default:
printf("OOOPS... This operation isn't exist yet\n");
flag = 1;
break;
}
if(flag!=1) while ((c = getchar()) != '\n' && c != EOF);

} while (choice != 'n' && choice != 'N');
}

int main()
{
menu();
}