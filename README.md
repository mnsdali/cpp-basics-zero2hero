
# Act7: Vehicule
### Exercice
![image](https://github.com/mnsdali/cpp-basics-zero2hero/assets/91077017/3adf9cda-c31d-40e4-93f1-629a2134d07c)
![image](https://github.com/mnsdali/cpp-basics-zero2hero/assets/91077017/0b02afe6-69c2-4a1a-9f0b-018c3437819f)
![image](https://github.com/mnsdali/cpp-basics-zero2hero/assets/91077017/af5a5728-27e4-4221-87ca-80fd4fb6b344)

```cpp
int main()
{
  vector<Voiture> garage;
  vector<Avion> hangar;
  garage.push_back(Voiture("Peugeot", 1998, 147326, 2.5, 5, 180.0, 12000));
  garage.push_back(Voiture("Porsche", 1985, 250000.00, 6.5, 2, 280.0, 81320));
  garage.push_back(Voiture("Fiat", 2001, 7327.30, 1.6, 3, 65.0, 3000));
  hangar.push_back(Avion("Cessna", 1972, 1230673.90, HELICES, 250));
  hangar.push_back(Avion("Nain Connu", 1992, 4321098.00, REACTION, 1300));
  for (auto voiture : garage) {
    voiture.calculePrix();
    voiture.affiche(cout);
  }
  for (auto avion : hangar) {
    avion.calculePrix();
    avion.affiche(cout);
  }
  return 0;
}
```

# Act8: TasksQueue
### Exercice
```
Nous souhaitons modéliser la gestion des files de tâches dans un système donné. Pour ce faire, nous
considèrerons tout d’abord les constituants d’une queue (les tâches), puis créerons la structure d'une 
queue elle-même à l'aide d’un vecteur dynamique de tâches. 
Question 1 :
  Nous allons créer une classe Task pour représenter des tâches à accomplir. Cette classe comportera un 
  seul attribut à savoir le nom, de type string, qui stocke le nom de la tâche.
  a. Écrivez deux constructeurs pour la classe Task, l'un sans argument spécifiant une tâche vide et l'autre avec un paramètre pour initialiser le nom. 
  b. Ajoutez une méthode permettant d'obtenir le nom d’une tâche.
Question 2 :
  Nous allons créer une classe TaskQueue pour gérer les tâches. Cette classe comportera des fonctions 
  pour ajouter, retirer et gérer des tâches dans une queue.
  On admettra qu’on a un vecteur de taille maximale, dans lequel on rangera les tâches à la suite dans 
  leur ordre d’arrivée dans la queue. On adoptera ici la représentation circulaire d’une file de tâches.
  Pour ce faire, la classe TaskQueue possède trois membres de données :
  • tasks, qui représente un vecteur d'objets de type Task.
  • maxSize de type int, qui indique la taille maximale possible pour la liste de tâches.
  • maxSizeValue qui est une valeur maximale constante que maxSize ne doit pas dépasser.
  a. Ecrire les fonctions membres nécessaires suivantes :
    • Constructeur par défaut : Il permet de créer une liste de tâches vide ayant la taille maximale définie.
    • Constructeur avec un paramètre indiquant l’entier représentant la taille de la queue.
    • Constructeur de copie : Vous devriez implémenter une fonction qui copie une liste de tâches existante en créant une nouvelle liste de tâches avec les mêmes éléments.
    • Destructeur.
  b. Surchargez les opérateurs suivants :
    • L'opérateur [] pour accéder à une tâche dans la file : Task& operator[] (int i). 
    • L'opérateur -- pour retirer la première tâche de la file : void operator--()
    • L'opérateur + pour ajouter une tâche non vide à la fin de la file s'il y a de la place. Affichez un message approprié pour indiquer si la tâche a été ajoutée ou non : void operator+ (const Task& tache)
    • L’opérateur d’affichage << pour afficher une queue de tâches, il servira alors à afficher les noms des tâches contenues dans la queue.
Question 3 : Utilisation de la Classe TaskQueue
  Dans la fonction principale (main), créez une file de tâches avec une capacité spécifiée.
  • Ajoutez plusieurs tâches à la file.
  • Accédez à des tâches spécifiques en utilisant l'opérateur [].
  • Retirez des tâches de la file en utilisant l'opérateur --.
  • Copiez la file de tâches dans une nouvelle instance de TaskQueue en utilisant le constructeur de copie.
Note : Assurez-vous de gérer correctement les cas où la file est pleine ou où vous essayez d'accéder à 
une tâche qui n'existe pas.
```
Voici un petit exemple de la fonction main :
```cpp
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
 cout << taskQueue[0].getNom();
 // Copie de la file de tâches
 TaskQueue taskQueueCopy = taskQueue;
 cout << taskQueueCopy;
 --taskQueueCopy;
 cout << taskQueueCopy; //Affiche Queue vide
 -- taskQueue_2;
 cout << taskQueue_2; //Affiche Queue vide
 cout << taskQueue_2[2].getNom(); //arrête l'exécution et lance une exception out_of_range
 return 0;
}
```
