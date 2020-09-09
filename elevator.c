#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"
#include"person.h"


Elevator *create_elevator(int capacity, int currentFloor,  PersonList *persons){
  
  Elevator* ascenseur = (Elevator*) malloc(sizeof(Elevator));
  ascenseur -> capacity =  capacity;
  ascenseur -> currentFloor =  currentFloor;
  ascenseur -> persons =  persons; 
  return ascenseur; 
 



}
Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){

  Building *immeuble = ( Building*) malloc(sizeof(Building));
  immeuble -> nbFloor = nbFloor;
  immeuble -> elevator = elevator;
  immeuble -> waitingLists = waitingList;
  return immeuble; 




PersonList* exitElevator ( Elevator *e) {
   
       int current = e->currentFloor; 
       int destination = e->persons->person->dest;
   
       // création d'une liste 
       PersonList* sort = (PersonList*) malloc(sizeof(PersonList));
   
       // il faut vérifier si la destination des personnes correspondent au 'currentFloor'
       if ( current != destination ){
   
           // Dans ce cas, on passe directement à la prochaine personne 
           e->persons = e ->persons->next;
           exitElevator(e);
   
       } else {
   
           sort = e->persons->person;
 --        // pointer sur la prochaine person 
           e->persons = e ->persons->next;
           sort = sort -> next;         
           // on fait un rappel récursif 
           exitElevator(e);
   
       }
   
       return sort;
   
   }


PersonList* enterElevator ( Elevator *e, PersonList *list) {


}



void stepElevator( Building *b){

  int current = ascenseur -> currentFloor; 
  int target  = ascenseur -> targetFloo
  Elevator* ascenseur = (acsenseur*) malloc(sizeof(Elevator)); 
  
  if ( current == target ) {
   
  
  } else { 
   if ( target - current > 0 ){
    ascenseur -> currentFloor += 1; 
   } else { 
    ascenseur -> currentFloor -= 1; 
   }
  }


}

