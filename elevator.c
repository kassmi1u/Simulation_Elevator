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


PersonList* exitElevator ( Elevator *e,PersonList *previous) {
  PersonList *temp;
  if(e->persons!=NULL){
    if(previous==NULL){
      if(e->persons->person->dest != e->currentFloor){
        exitElevator(e,e->persons);
      }else{
        temp = e->persons;
        e->persons = e->persons->next;
        exitElevator(e,NULL);
      }
    }else{
      if(previous->next!=NULL){
        if(previous->next->person->dest != e->currentFloor){
        exitElevator(e,previous->next);
        }else{
          temp = previous->next;
          previous->next = previous->next->next;
          exitElevator(e,previous);
        }
      }
      
    }
    return NULL;
  }

}



PersonList* enterElevator ( Elevator *e, PersonList *waitingList) {
  PersonList *P;
  int count=0;
  if (waitingList!=NULL)
  {
    P = e->persons;
    while (P!=NULL)
    {
      P = P->next;
      count++;
    }

    if(e->capacity > count ){
      e->persons = insert( waitingList->person , e->persons );

      return enterElevator(e,waitingList->next);
    }
  }
  
  
  return waitingList;
}

  
void stepElevator( Building *b){

  int current = b->elevator->currentFloor; 
  int target  = b->elevator->targetFloor ; 

  if ( current == target ){

    exitElevator ( b->elevator,NULL);
    b->waitingLists[b->elevator->currentFloor] = enterElevator ( b->elevator, b->waitingLists[b->elevator->currentFloor]);
  } else { 
    
    if ( target - current > 0 ){
      b->elevator->currentFloor ++ ;

   } else {
     b->elevator->currentFloor -- ; 

   }
  }


}

