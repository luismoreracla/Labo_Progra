// Luis Morera Claramunt. B44726.
// Programa principal

#include "AVL.h"

using namespace std;

int main(){

    node* root= new node;

    build_all_trees();

    delete_tree(root);

    delete root;

}
