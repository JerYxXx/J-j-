#include <SFML/Graphics.hpp>
#include <iostream>
#include "menus.h"
#include "objets SFML.h"

using namespace std;


//variables globales :
string menu;
string menuPrecedent;
int a;
sf::Font font;
sf::RenderWindow window(sf::VideoMode(1200, 800), "Bouton SFML");

int main()
{


    // Charger une police
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erreur : Impossible de charger la police.\n";
        return -1;
    }



    menu = "acceuil";//ici on crée la variable menu qui doit afficher le menu
    while (menu!="ecran aurevoir") {
       if (menu=="acceuil") {acceuil();}
       else if (menu=="demarrer le jeu") {demarrerLeJeu();}
       else if (menu=="generation de grille") {generationDeGrille();}
       //else if (menu=="importer une grille") {importerUneGrille();}
       else if (menu=="parametre predefini") {parametrePredefini();}
       //else if (menu=="nouveau parametre") {nouveauParametre();;}
       else if (menu=="credits") {credits();}
       else{erreurMenuIndefini();}
         window.display();

            }

    window.close();
    menuAurevoir();
    return 0;
    }


