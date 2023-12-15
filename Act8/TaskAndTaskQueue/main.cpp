#include <iostream>
#include "Task.h"
#include "TaskQueue.h"

using namespace std;

int main() {
 // Crée une file de tâches avec une capacité ne dépassant pas maxSizeValue
 TaskQueue taskQueue(10);
 TaskQueue taskQueue_2(1);
 // Ajouter des tâches à la file
 taskQueue + Task("Task 1");
 taskQueue + Task("Task 2");
 taskQueue + Task(); //la tâche ne peut pas être ajoutée car vide
 cout << taskQueue;
 // Retirer une tâche
 --taskQueue;
 cout << taskQueue[0].getName();
 // Copie de la file de tâches
 TaskQueue taskQueueCopy = taskQueue;
 cout << taskQueueCopy;
 --taskQueueCopy;
 cout << taskQueueCopy; //Affiche Queue vide
 --taskQueue_2;
 cout << taskQueue_2; //Affiche Queue vide
 cout << taskQueue_2[2].getName(); //arrête l'exécution et lance une exception out_of_range
 return 0;
}
