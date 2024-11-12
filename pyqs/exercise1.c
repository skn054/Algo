#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct addr {
    char city[10];
    char street[30];
    int pin;
}p2;
struct {
    char name[30];
    int gender;
    struct addr locate;
} person, *kd = &person;


int main(){
         struct addr *p1 = (struct addr*)malloc(sizeof(struct addr));
         strcpy(p1->city,"hyd");
         strcpy(p1->street, "12345");
         p1->pin = 10;
        // printf("%s %s",p1->city,p1->street);

        p2.pin = 20;

        strcpy(person.name ,"hyderabad");
        person.gender = 1;
        strcpy(person.locate.city,"bangalore");
        strcpy(person.locate.street,"curch street");
        person.locate.pin = 30;

        // printf("%s %s",person.locate.city,person.name);
        printf("%s",kd->name);
        printf("%d",p2.pin);

         free(p1);

         return 0;
}