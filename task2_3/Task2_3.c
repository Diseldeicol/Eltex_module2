#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double culc_sum(double x, double y)
{
return x + y;
}
double culc_sub(double x, double y)
{
return x - y;
}
double culc_multi(double x, double y)
{
return x * y;
}
double culc_div(double x, double y)
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
double mistakeS(double x)
{
printf("OOOPS... This operation isn't exist yet\n");
return 0;
}
double mistakeB(double x, double y)
{
printf("OOOPS... This operation isn't exist yet\n");
return 0;
}
double (*ArithmeticSingleOperation(char choice)) (double) {
switch (choice) {
case '!': return factorial;
case 's': return sinus;
case 'c': return cosine;
default: return mistakeS;
}
}
double (*ArithmeticBinOperation(char choice)) (double, double) {
switch (choice) {
case '+': return culc_sum;
case '-': return culc_sub;
case '*': return culc_multi;
case '/': return culc_div;
case '^': return power;
case 'l': return logarithm;
default: return mistakeB;
}
}


void menu()
{
double (*B_operation)(double, double);
double (*S_operation)(double);
char choice='d';
int operands=0;
double result = 0;
double x;
double y;
do
{
int c;
printf("***All operations: <x+y>,<x-y>,<x*y>,<x/y>,<x!>,<x^y>,<logx(y)>,<sinx>,<cosx>***\n");
printf("Write how many operands do you need.For example:\n1+3 - you need 2 operands->press 2\ncos(90) - you need 1 operand->press 1\n-->");
scanf("%d", &operands);
while ((c = getchar()) != '\n' && c != EOF);
system("clear");
if (operands == 1)
{
printf("Enter operation(Possible single opirations:<!>,<sin>,<cos>) OR enter <n> to exit\n->");
scanf("%c", &choice);
if (choice != 'n' && choice != 'n')
{
S_operation = ArithmeticSingleOperation(choice);
while ((c = getchar()) != '\n' && c != EOF);
printf("x: ");
scanf("%lf", &x);
result = S_operation(x);
}

}
if (operands == 2)
{
printf("Enter operation(Possible opirations: <+>,<->,<*>,</>,<^>,<log>) OR enter <n> to exit\n->");
scanf("%c", &choice);
if (choice != 'n' && choice != 'n')
{
B_operation = ArithmeticBinOperation(choice);
while ((c = getchar()) != '\n' && c != EOF);
printf("x: ");
scanf("%lf", &x);
printf("y: ");
scanf("%lf", &y);
result = B_operation(x, y);
}

}
if (choice != 'n' && choice != 'N')
{
while ((c = getchar()) != '\n' && c != EOF);
printf("RESULT: %lf\n", result);
}

} while (choice != 'n' && choice != 'N');
}

int main()
{
menu();
}