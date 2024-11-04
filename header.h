#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

void menudujeu(){}
//Choix Jouer ou quitter
//Choix grille aléatoire ou manuel
//choix dimension grille

bool nbAleatoire(double proba){}
//permettera une configuration "aléatoire", par contre comme c'est quelque chose qui va permettre de générer dans la grille, il y a moyen que la fonction sera à mettre directement dans la classe grille.

void sauvegarde(){}
//Une fonction qui sauvegardera les tableaux dans d'aure tableau

// Je pense qu'il n'y a pas besoin de la classe cellule vu qu'on les crées dans la grille directement.
/*class cellule{
private:
    int x, y;
    bool vivante;
public:
    int getX();
    int getY();

friend cellule operator+(const cellule&,const cellule&);
friend cellule operator-(const cellule&,const cellule&);
};*/

//Il faut savoir que quand on initie la grille toute les 
class grille{
private:
    int largeur, hauteur;
    vector<vector<bool>> cellules;//Tableau vecteur d'un même vecteur soit 2 dimensions. Sinon on peut faire un tableau normale pour plus de transparence
public:
    grille(int largeur,int hauteur) : largeur(largeur), hauteur(hauteur) { //Donc ce que j'ai fais en détails, 1 je crée un tableau(la largeur) d'un autre tableau(la hauteur) qui contient un bool. Je set les valeurs que le joueurs va renseigner plus tard et j'initialise tout les cellules en morte.
        cellules.resize(largeur, vector<bool>(hauteur, false)  );
    }
    bool IsTrue(int x, int y);//Connaitre l'état d'une cellule
    void Etat(int x, int y, bool vivante);//Pour changer l'état de la cellule
    int ScanCellule(int x, int y); //Fonction pour scanner tout autour de la cellule
    void affichage();
};
//affichage grille, initialisation grille
class jeu{//la classe Jeu sera plus faite pour les annexes (revenir en arrière, les boutons?, etc) à ton besoin d'une classe pour cela ?
private:
int generation=0; 
public:
    int population();//affiche nombre cellule vivante
    int iteration();//affiche iteration
    int getGeneration() const {
        return generation;
    }
    //void analysecellule(int x, int y); Pareille tout ce fait dans la classe Grille je pense ?

};//rajouter population
//méthodes pour chaque itération(règles du jeu)

class bouton{ //On va crée plusieurs bouton en SFML mais on n'y connait pas grand chose pour le moment. On verra plus tard.
private:
public:
};

#endif // HEADER_H_INCLUDED
