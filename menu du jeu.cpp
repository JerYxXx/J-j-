#include <iostream>

using namespace std;

int a;
string menu;
string menuPrecedent;

void changerMenu(string nouveauMenu){
    menuPrecedent = menu;
    menu = nouveauMenu;
}
/* fonction retour compliquée a faire plus tard
void retour(){
    changerMenu(menuPrecedent);
}*/

void ecranAurevoir(){
    cout<<"ceci est l'ecran de fin du jeu";
}

void demarrerLeJeu(){
    cout<<"generer une grille : 1, importer une grille : 2"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("generation de grille");
    }else{changerMenu("importer une grille");}
}

void generationDeGrille(){
    cout<<"parametres predefinis : 1 nouveau parametre : 2"<<endl;
    cin>> a;
    if (a == 1 ){
        changerMenu("parametre predefini");
    }else{changerMenu("nouveau parametre");}
}

void importerUneGrille(){
    cout<<"menu pas fait"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("kj");
    }else{changerMenu("klhg");}
}

void parametrePredefini(){
    cout<<"menu pas fait"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("kj");
    }else{changerMenu("klhg");}
}

void nouveauParametre(){
    cout<<"menu pas fait"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("kj");
    }else{changerMenu("klhg");}
}

void credits(){
    cout<<"jeu fait par Jerome Kounde, Elsa Rolland et Arthur Hooper"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("kj");
    }else{changerMenu("klhg");}
}

void erreurMenuIndefini(){
    cout<<"vous ne devirez pas etre ici"<<endl<<"retour a l'acceuil"<<endl;
    changerMenu("acceuil");
}

void menuAurevoir(){
    cout<<"Aurevoir!";
}

void acceuil(){
    cout<<"jouer au jeu de la vie : 1, quitter : 2"<<endl;
    cin>>a;
    if (a == 1 ){
        changerMenu("demarrer le jeu");
    }else{changerMenu("ecran aurevoir");}

}

int main()
{
    menu = "acceuil";//ici on crée la variable menu qui doit afficher le menu
    while (menu!="ecran aurevoir") {
       if (menu=="acceuil") {acceuil();}
       else if (menu=="demarrer le jeu") {demarrerLeJeu();}
       else if (menu=="generation de grille") {generationDeGrille();}
       else if (menu=="importer une grille") {importerUneGrille();}
       else if (menu=="parametre predefini") {parametrePredefini();}
       else if (menu=="nouveau parametre") {nouveauParametre();;}
       else if (menu=="credits") {credits();}
       else{erreurMenuIndefini();}


            }


    menuAurevoir();
    return 0;
    }

