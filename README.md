# Tower Defense Game

Bonjour et bienvenue dans mon projet !

C'est un jeu de Tower Defense codé pendant les études universitaires pour apprendre le C++. Simple à prendre en main, je vous laisse découvrir ce jeu !

![](https://github.com/cyzu/Master1_Cpp_Vaisseaux/blob/master/doc/picture.png)

## Pour commencer

Suivez les instructions pour copier le projet dans votre machine locale.

### Prérequis

Disposez du logiciel ```Xcode``` pour lancer le jeu.

### Installation

Clonez ce projet depuis ce lien : https://github.com/cyzu/Master1_Cpp_Vaisseaux.git 

Ou bien téléchargez le dossier ```.zip```.

## Comment jouer

### But du jeu

Le but du jeu est de tuer un maximum d'astéroïdes dans une partie. 

### Vaisseaux

Il existe 4 types de vaisseaux permettant de détruire les astéroïdes. Ces vaisseaux se distinguent par leur prix et par la puissance-fréquence-vitesse de leurs missiles envoyés.

Pour poser un vaisseau il suffit de cliquer sur la case où vous voulez poser le vaisseau. Cliquer plusieurs fois sur la même case pour poser le vaisseau de votre choix et taper ```Entrée``` pour valider.

Une fois le vaisseau posé, il ne peut plus être supprimé. Il est impossibles de poser deux vaisseaux sur une même case. Attendez que celui-ci soit détruit pour poser un autre vaisseau par dessus.

### Astéroïdes

Les astéroïdes arrivent en vagues. Lancer une vague en appuyant sur ```Espace``` Vous ne pouvez pas lancer 2 vagues simultanément.
Plus vous lancez de vagues, plus le nombre d'astéroïdes augmentent de même que leur puissance.

Les astéroïdes sont détruits petit à petit en fonction de la puissance des missiles reçus.

### Vies

Vous commençez le jeu avec 20 vies. Le jeu se termine lorsqu'il ne reste plus de vie dans la partie.
Si un astéroïde atteint le coté gauche de la fenêtre, le nombre de vie réduit en fonction de la puissance restante de l'astéroïde.

### Argents

Chaque vaisseau possède un coût. Vous pouvez gagner des pièces en tuant les astéroïdes.

###### A tout moment de la partie appuyez sur ```Espace``` pour mettre sur pause.

## Rapport

Le rapport final du projet se trouve [ici](https://github.com/cyzu/Master1_Cpp_Vaisseaux/blob/master/doc/Projet_Cpp.pdf) !

## Auteur

* **Chloé Bensoussan** - [cyzu](https://github.com/cyzu), étudiante en master 1 IFI à l'Université de Nice Sophia-Antipolis

## Date

Novenbre/Decembre 2017

## Remerciements

* Professeur Jean-Charles Régin
* Pierre Tassel - [ingambe](https://github.com/ingambe) qui m'a beaucoup aidé et débuger plusieurs problèmes au cours de l'implémentation.
