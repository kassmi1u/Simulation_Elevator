#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"
#include"person.h"



Elevator *create_elevator(int capacity, int currentFloor,  PersonList *persons){
  
  Elevator* ascenseur = (Elevator*) malloc(sizeof(Elevator));
  ascenseur->capacity =  capacity;
  ascenseur->currentFloor =  currentFloor;
  ascenseur->persons =  persons; 
  return ascenseur; 
}



Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){

  Building *immeuble = ( Building*) malloc(sizeof(Building));
  immeuble->nbFloor = nbFloor;
  immeuble->elevator = elevator;
  immeuble->waitingLists = waitingLists;
  return immeuble; 
}


PersonList* exitElevator ( Elevator *e) {
   
       int current = e->currentFloor; 
       int destination = e->persons->person->dest;
   
       PersonList* sort = (PersonList*) malloc(sizeof(PersonList));
   
       // il faut vérifier si la destination des personnes correspondent au 'currentFloor'
       if ( current != destination ){
   
           // Dans ce cas, on passe directement à la prochaine personne 
           e->persons = e->persons->next;
           exitElevator(e);
   
       } else {

           sort->person = e->persons->person;
           // pointer sur la prochaine person 
           e->persons = e->persons->next;
           sort = sort->next;         
           exitElevator(e);
       }
       return sort;
}



PersonList* enterElevator ( Elevator *e, PersonList *waitingList) {
  if((e->capacity > sizeof(e->persons)) ){
    e->persons = insert( waitingList->person , e->persons );
    return enterElevator(e,waitingList->next);
  }
  return waitingList;
}

  
void stepElevator( Building *b){

  int current = b->elevator->currentFloor; 
  int target  = b->elevator->targetFloor ; 

  if ( current == target ){

    PersonList* exitElevator ( Elevator *e);
    PersonList* enterElevator ( Elevator *e, PersonList *list);
  } else { 
    
    if ( target - current > 0 ){
      b->elevator->currentFloor ++ ;

   } else {
     b->elevator->currentFloor -- ; 

   }
  }


}

