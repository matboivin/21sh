### Notepad

### Lexer, Parser, AST

Le plus gros du travail.  
Objectif : générer l'AST.

- Le lexer gère l'escaping et ignore les caractères inutiles.  
Stocker les tokens dans tableau dynamique (doubler taille si taille insuffisante) :
  - O(log(n)) allocations, alors que liste chaînée -> O(n) allocations.
  - Procédure debug : affiche les tokens
- Le parser avec AST. Itérer sur les tokens pour construire l'arbre.
  - Procédure debug : affiche l'arbre (format .dot)

Exemples de structure de noeud :

- type de noeud
- enfant gauche
- enfant droite
- data

Ou :

- type de noeud
- expression

### Exécution

- Pour chaque commande, créer un processus.
- Créer des pipes pour communiquer l'output d'un processus au suivant.
- Gérer les redirections.
- Quand tous les processus enfants sont terminés, réafficher le prompt.

exécuter une fonction -> famille des fonctions `exec`

`execve`
- param 1 : path du programme que l'on souhaite lancer
- param 2 : tableau de chaînes qui sont les arguments qui seront passés à la commande que l'on souhaite exécuter
- param 3 : environnement où exécuter le programme

appel système `fork` : moyen sous Unix de créer de nouveaux processus

le processus cloné hérite de toutes les propriétés de son processus parent  
les processus héritent des mêmes environnements, et donc des mêmes fd ouverts

le processus parent doit attendre la fin de tous ses processus enfants  
le processus parent récupère la valeur de retour du processus enfant  
synchroniser les processus avec l'appel système wait

### Env

`PATH` = où se trouvent tous les dossiers contenant des binaires dans le système

### Pipes

`pipe()` prend en param fildes[2]
- fildes[0] = côté où on lit `READ_END`
- fildes[1] = côté où on écrit `WRITE_END`

`dup2()` prend 2 fd en param

fermer côté du pipe inutile afin d'éviter les broken pipes
