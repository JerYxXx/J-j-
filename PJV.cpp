//Travaille de Jérôme :

/* void grille::isTrue(int x,int y) {
        if (x >= 0 && x < grille.size() && y >= 0 && y < grille[0].size()){ //ici je dis juste de bien regarder dans le champs de la grille et pas au dela
            if (grille[x][y])//C'est un bool donc juste si grille x,y = true donc 1 donc vivante bah on push back les coords
            CellulesVivante.push_back({x,y});
        }
            
    }*/

//Ici je scan tout autour de la cellule considéré, puis j'appelle la fonction is true pour savoir si la cellule est vivante.
/*void grille::scanCellule(int x,int y) {
    for (int X=x-1;X<=x+1 ;X++) {
        for (int Y=y-1;Y<=y+1;Y++) {
            if (X < 0 || X >= grille.size() || Y < 0 || Y >= grille[0].size()) { //ça permet de gérer les bordures. là j'avoue j'ai utiliser le frérot
                continue;
            }
            if (X==x && Y == y) continue;
                isTrue(X,Y);
        }
    }
}*/

//Fonction pour changer l'etat d'une cellule, je pense que c'est dans cette fonction qu'on peut rajouter les règles du jeu, j'aimerais en discuter avec vous avant de le faire.
void grille::changeEtat(int x, int y) {
    if (cellules[x][y]) {
        cellules[x][y] = false;
    } else cellules[x][y] = true;
}

grille grille::generationSuivante() {
    grille nouvelleGrille(largeur, hauteur); // Nouvelle grille qui sera retournée

    // Parcourir la grille actuelle
    for (int x = 0; x < cellules.size(); x++) {
        for (int y = 0; y < cellules[0].size(); y++) {
            int voisinsVivants = 0;

            // Parcours des voisins
            for (int X = x - 1; X <= x + 1; X++) {
                for (int Y = y - 1; Y <= y + 1; Y++) {
                    if (X >= 0 && X < cellules.size() && Y >= 0 && Y < cellules[0].size() && !(X == x && Y == y)) {
                        if (cellules[X][Y]) { // Vérifie si la cellule est vivante
                            voisinsVivants++;
                        }
                    }
                }
            }

            // Application des règles du jeu
            if (cellules[x][y]) { // Si la cellule est vivante
                if (voisinsVivants == 2 || voisinsVivants == 3) {
                    nouvelleGrille.cellules[x][y] = true; // La cellule reste vivante
                }
            } else { // Si la cellule est morte
                if (voisinsVivants == 3) {
                    nouvelleGrille.cellules[x][y] = true; // La cellule devient vivante
                }
            }
        }
    }

    return nouvelleGrille;
}
