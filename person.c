#include<stdio.h>
#include<stdlib.h>
#include"person.h"



Person* createPerson(int src, int dest){
    
    Person* personne = (Person*) malloc(sizeof(Person));
    
    personne -> src = src;
    personne -> dest = dest;
    return personne; 
}

PersonList* insert (Person *p, PersonList *list){

    PersonList* personneliste = (PersonList*) malloc(sizeof(PersonList));

    personneliste -> person = p; 
    personneliste -> next = list; 
    return personneliste;
}
