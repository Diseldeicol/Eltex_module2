#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <string.h>

#define MAX_CONTACTS 500
#define MAX_TELEPHONE_NUMBERS 5
#define MAX_EMAILS 5
#define MAX_SOCIAL_MEDIAS 5

typedef struct Contact_list {
char name[100];//ФИО
char place_of_work[50];//место работы
char function[20];//должность
char telephone_number[MAX_TELEPHONE_NUMBERS][15];
char email[MAX_EMAILS][20];
char social_media[MAX_SOCIAL_MEDIAS][50];
} Contacts;

Contacts add();
void print_contact(Contacts contact);
int delete_contact(Contacts* contacts_list, int count);
void edit(Contacts* contacts_list, int count);
void menu(Contacts* contact_list, int count);



int main()
{
Contacts my_list[MAX_CONTACTS];
menu(my_list, 0);

}

Contacts add()
{
Contacts new_contact;
printf("Enter your fullname(For example: Petrov Petya)\n=>");
while (1) {
fgets(new_contact.name, sizeof(new_contact.name), stdin);
if (new_contact.name[0]=='\n') {
// Введена пустая строка или произошла ошибка при вводе
printf("This item is required to be completed! Please try again: ");
// Очистка буфера ввода
//int c;
//while ((c = getchar()) != '\n' && c != EOF);
}
else {
new_contact.name[strcspn(new_contact.name, "\n")] = '\0';
break;
}
}

printf("Enter your place of work\n=>");
fgets(new_contact.place_of_work, sizeof(new_contact.place_of_work), stdin);
new_contact.place_of_work[strcspn(new_contact.place_of_work, "\n")] = '\0';

printf("Enter your job function\n=>");
fgets(new_contact.function, sizeof(new_contact.function), stdin);
new_contact.function[strcspn(new_contact.function, "\n")] = '\0';


printf("Enter your phone numbers\n=>");
int phone_count = 0;
while (phone_count < MAX_TELEPHONE_NUMBERS) {
printf("Number#%d (or write 'stop'): ", phone_count + 1);
fgets(new_contact.telephone_number[phone_count], sizeof(new_contact.telephone_number[phone_count]), stdin);
//new_contact.telephone_number[phone_count][strcspn(new_contact.telephone_number[phone_count], "\n")] = '\0';
size_t length = strlen(new_contact.telephone_number[phone_count]);
new_contact.telephone_number[phone_count][length - 1] = '\0';
if (strcmp(new_contact.telephone_number[phone_count], "stop") == 0) {
strcpy(new_contact.telephone_number[phone_count], "\0");
break;
}
phone_count++;
}
printf("Enter your emails\n=>");
int email_count = 0;
while (email_count < MAX_EMAILS) {
printf("Email#%d (or write 'stop'): ", email_count + 1);
scanf("%s", new_contact.email[email_count]);
if (strcmp(new_contact.email[email_count], "stop") == 0) {
strcpy(new_contact.email[email_count], "\0");
break;
}
email_count++;
}
printf("Enter your social medias\n=>");
int link_count = 0;
while (link_count < MAX_SOCIAL_MEDIAS) {
printf("Link#%d (or write 'stop'): ", link_count + 1);
scanf("%s", new_contact.social_media[link_count]);
if (strcmp(new_contact.social_media[link_count], "stop") == 0) {
strcpy(new_contact.social_media[link_count], "\0");
break;
}
link_count++;
}
int c;
while ((c = getchar()) != '\n' && c != EOF);

return new_contact;
}

void print_contact(Contacts contact)
{
printf("Your name:%s\n", contact.name);
printf("Your place of work:%s\n", contact.place_of_work);
printf("Your job function:%s\n", contact.function);
printf("Your phone numbers:\n");
for (int i = 0; i < sizeof(contact.telephone_number) / sizeof(contact.telephone_number[0]); i++) {
if (contact.telephone_number[i][0] != '\0') {
printf("%s ", contact.telephone_number[i]);
/*for (int j = 0; contact.telephone_number[i][j] != '\0'; j++)
{
printf("%c", contact.telephone_number[i][j]);
}
printf(" ");*/
}
else break;
}
printf("\n");
printf("Your emails:\n");
for (int i = 0; i < sizeof(contact.email) / sizeof(contact.email[0]); i++) {
if (contact.email[i][0] != '\0') {
printf("%s ", contact.email[i]);
}
else break;
}
printf("\n");
printf("Your social medias:\n");
for (int
i = 0; i < sizeof(contact.social_media) / sizeof(contact.social_media[0]); i++) {
if (contact.social_media[i][0] != '\0') {
printf("%s ", contact.social_media[i]);
}
else break;
}
printf("\n");
}
int findContact(Contacts* list, char fullname[100], int count)
{
int index;
for (int i = 0; i < count; i++)
{
if (strcmp(list[i].name, fullname) == 0)
{
index = i;
return index;
}

}
return -1;
}
int delete_contact(Contacts* contacts_list, int count)
{
char fullname[100];
printf("Enter fullname of contact you want to delete: ");
while (1) {
fgets(fullname, sizeof(fullname), stdin);
if (fullname[0] == '\n') {
printf("Please try again: ");
}
else {
fullname[strcspn(fullname, "\n")] = '\0';
break;
}
}
int index = findContact(contacts_list, fullname, count);
if (index <= count && index >= 0)
{
for (int i = index; i < count; i++)
{
contacts_list[i] = contacts_list[i + 1];
}
}
else return -1;
return 1;

}

void edit(Contacts* contacts_list, int count)
{
char fullname[100];
printf("Enter fullname of contact you want to edit: ");
while (1) {
fgets(fullname, sizeof(fullname), stdin);
if (fullname[0] == '\n') {
printf("Please try again: ");
}
else {
fullname[strcspn(fullname, "\n")] = '\0';
break;
}
}
int index = findContact(contacts_list, fullname, count);
if (index > 0) contacts_list[index] = add();
else printf("Not fount that contact\n");
}

void menu(Contacts* contact_list, int count)
{
int choice=0;
int flag;
do
{
printf("\t\t\t***Menu***\n");
printf("--Add new contact-->press 1\n");
printf("--Delete contact-->press 2\n");
printf("--Edit contact-->press 3\n");
printf("--Exit-->press 4\n");
printf("Your choice: ");
scanf("%d", &choice);
int c;
while ((c = getchar()) != '\n' && c != EOF);

switch (choice)
{
case 1:
if (count < MAX_CONTACTS)
{
contact_list[count] = add();
count++;
}
else printf("Too many contacts...\n");
system("clear");
for (int i = 0; i < count; i++)
{
printf("Contact #%d\n", i+1);
print_contact(contact_list[i]);
printf("\n");
}
break;
case 2:
flag=delete_contact(contact_list, count);
if (flag > 0) count--;
for (int i = 0; i < count; i++)
{
printf("Contact #%d\n", i + 1);
print_contact(contact_list[i]);
printf("\n");
}
break;
case 3:
edit(contact_list, count);
system("clear");
for (int i = 0; i < count; i++)
{
printf("Contact #%d\n", i + 1);
print_contact(contact_list[i]);
printf("\n");
}
break;
case 4:
break;
default:
break;
}
} while (choice != 4);
}