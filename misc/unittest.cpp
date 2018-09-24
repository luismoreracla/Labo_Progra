// Luis Morera Claramunt. B44726.
// Programa principal

#include "AVL.h"

using namespace std;

int main(){

    node* root= new node;
    int error=0;

    // Prueba 1: Probar formato de nombre
    error=check_format("3steban Alvarado", "116067894");
    cout << "Prueba 1:" << endl;
    if(error==E_INVALID_NAME) cout << "El nombre ingresado no es válido." << endl;
    else cout << "EL nombre tiene el formato correcto." << endl;
    cout << endl;

    // Prueba 2: Probar formato de cedula
    error=check_format("Esteban Alvarado", "1160s7894");
    cout << "Prueba 2:" << endl;
    if(error==E_NOT_NUM) cout << "La cedula ingresada no es válida." << endl;
    else cout << "La cedula tiene el formato correcto." << endl;
    cout << endl;

    // Prueba 3: Probar cedula mayor al limite permitido
    error=check_format("Esteban Alvarado", "1160742342894");
    cout << "Prueba 3:" << endl;
    if(error==E_OUT_OF_BOUND) cout << "La cedula ingresada excede el limite." << endl;
    else cout << "La cedula tiene el formato correcto." << endl;
    cout << endl;

    // Prueba 4: Contar cantidad de nodos
    cout << "Prueba 4:" << endl;
    root=insert(root, "Mario Perez", "1234543");
    root=insert(root, "Adrian Barrantes", "4534543");
    root=insert(root, "Catalina Ortega", "3234543");
    root=insert(root, "Pedro Marin", "1234567");
    root=insert(root, "Luis Alvarado", "1233343");
    root=insert(root, "Matias Jimenez", "1230543");
    root=insert(root, "Silvana Morera", "1234003");
    root=insert(root, "Mauricio Alvarado", "1004543");
    int n=count_nodes(root);
    cout << "La cantidad de nodos en el arbol es: " << n-1 << endl;
    cout << endl;

    //Prueba 5: Buscar una cedula
    cout << "Prueba 5:" << endl;
    int srch= search(root, 1004543);
    if(srch==FOUND_IT) cout << "La cedula se encuentra en el arbol." << endl;
    else cout << "La cedula no se encuentra en el arbol." << endl;
    cout << endl;

    // Prueba 6: Obtener maxima altura del arbol
    cout << "Prueba 6:" << endl;
    int h=get_max_height(root);
    if(h==E_NULL_ROOT) cout << "La lista se encuentra vacia." << endl;
    else cout << "La maxima altura es: " << h << endl;
    cout << endl;

    // Prueba 7: Eliminar elementos del arbol
    cout << "Prueba 7:" << endl;
    int del=delete_tree(root);
    if(del==FREE) cout << "Memoria liberada exitosamente."<< endl;
    else cout << "Error al liberar memoria." << endl;

    return 0;
}

