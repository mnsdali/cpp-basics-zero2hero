#include <iostream>
#include "Task.h"
#include "TaskQueue.h"

using namespace std;

int main() {
 // Cr�e une file de t�ches avec une capacit� ne d�passant pas maxSizeValue
 TaskQueue taskQueue(10);
 TaskQueue taskQueue_2(1);
 // Ajouter des t�ches � la file
 taskQueue + Task("Task 1");
 taskQueue + Task("Task 2");
 taskQueue + Task(); //la t�che ne peut pas �tre ajout�e car vide
 cout << taskQueue;
 // Retirer une t�che
 --taskQueue;
 cout << taskQueue[0].getName();
 // Copie de la file de t�ches
 TaskQueue taskQueueCopy = taskQueue;
 cout << taskQueueCopy;
 --taskQueueCopy;
 cout << taskQueueCopy; //Affiche Queue vide
 --taskQueue_2;
 cout << taskQueue_2; //Affiche Queue vide
 cout << taskQueue_2[2].getName(); //arr�te l'ex�cution et lance une exception out_of_range
 return 0;
}
