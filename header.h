#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


void menudujeu(){}
//Choix Jouer ou quitter
//Choix grille aléatoire ou manuel
//choix dimension grille
//choix de générations


bool nbAleatoire(double proba){}

void sauvegarde(){}

class cellule{
private:
public:
};//vivante/morte et la position

class grille{
private:
public:
    affichage();
};
//affichage grille, initialisation grille
//get set
class jeu{
private:
public:
    int population();//affiche nombre cellule vivante
    int iteration();//affiche iteration
    void analysecellule(int x, int y);

};//rajouter population
//méthodes pour chaque itération(règles du jeu)

class bouton{
private:
public:
};//SFML

#endif // HEADER_H_INCLUDED
