#include<stdio.h>
#include<stdlib.h>
#include"elevator.h"
#include<math.h>


PersonList* exitElevator ( Elevator *e) {
}

PersonList* enterElevator ( Elevator *e, PersonList *list) { 
}


Elevator *create_elevator(int capacity, int currentFloor, int targetFloor, PersonList *persons){
  
  Elevator* ascenseur = (Elevator*) malloc(sizeof(Elevator));
  ascenseur -> capacity =  capacity;
  ascenseur -> currentFloor =  currentFloor;
  ascenseur -> targetFloor =  targetFloor;
  ascenseur -> persons =  persons; 
  return ascenseur; 
 



}
Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){

  Building *immeuble = ( Building*) malloc(sizeof(Building));
  immeuble -> nbFloor = nbFloor;
  immeuble -> elevator = elevator;
  immeuble -> waitingLists = waitingList;
  return immeuble; 




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

