#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
//Ancienne Grille
/*class grille{
private:
    int largeur, hauteur;
    vector<vector<bool>> cellules;//Tableau vecteur d'un même vecteur soit 2 dimensions. Sinon on peut faire un tableau normale pour plus de transparence
    vector<pair<int, int>> CellulesVivante;
public:
    grille(int largeur,int hauteur) : largeur(largeur), hauteur(hauteur) { //Donc ce que j'ai fais en détails, 1 je crée un tableau(la largeur) d'un autre tableau(la hauteur) qui contient un bool. Je set les valeurs que le joueurs va renseigner plus tard et j'initialise tout les cellules en morte.
        cellules.resize(largeur, vector<bool>(hauteur, false)  );
    
    void configurationAleatoire(double proba);
    void isTrue(int x, int y);//Connaitre l'état d'une cellule
    void changeEtat(int x, int y);//Pour changer l'état de la cellule
    void scanCellule(int x, int y); //Fonction pour scanner tout autour de la cellule
    void affichage();
    int getLargeur() const{
        return largeur;}
    int getHauteur() const{
        return hauteur;}
    //Il manque la fontion la plus importante PTDR c'est celle qui renvoie la nouvelle grille de la génération suivante après avoir fait scan cellule
    grille generationSuivante(){} //Jérôme s'en occupe
};*/

//Code modifier
class grille {
private:
    int largeur, hauteur;
    vector<vector<bool>> cellules;

public:
    grille(int largeur, int hauteur);
    void configurationAleatoire(double proba);
    void importerDepuisFichier(const string &nomFichier); //Parti à finir
    bool isTrue(int x, int y) const;
    void changeEtat(int x, int y);
    int scanCellule(int x, int y) const; // Compte les voisins vivants
    void affichage() const;
    grille generationsuivante() ;
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }
};


//Ancien code 
/*
class jeu{
private:
    vector<grille> historique; 
    int generation; 
public:
    jeu() : generation(0){} //On initialise la première génération à 0 càd la génération de la configuration initiale des cellules
    void jouer(grille &grille1, int iterations); //méthode pour lancer le jeu (à appeler dans menuPrincipal)
    int population(grille &grille1);//affiche nombre cellule vivante (à appeler dans menuPrincipal
    void retour(); //affiche grille précédente (à appeler où??)
    int getGeneration() const {
        return generation;}
};
*/
//Code modifier
class jeu {
private:
    vector<grille> historique;
    int generation;

public:
    jeu();
    void jouer(grille &grille1, int iterations);
    int population(const grille &grille1) const;
    void retour();
    int getGeneration() const { return generation; }
};


int main() {
    system("chcp 1252"); 
    cout<< "Jeu de la vie";
    srand(time(0));
    menuPrincipal(); 
return 0; }

#endif // HEADER_H_INCLUDED
