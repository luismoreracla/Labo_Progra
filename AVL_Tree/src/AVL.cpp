// Luis Morera Claramunt. B44726.
// En este archivo se define lo que hace cada funcion de la biblioteca

//Observaciones: EN el .h solo se incluyen las funciones que van a utilizar los usuarios, las funciones intermedias no se 
// incluyen:
// Los unittest son los primero que se hacen.
// Los unittest se agrupan, uno solo negativos, otros solo positivos, etc.
// 

#include "AVL.h"

using namespace std;


// Funcion para crear el arbol
node* build_tree(string list){

    int elements=0, total=0;
    string input_line, name, id_string;
    node* root=new node;
    root=nullptr;

    ifstream file(list);

    if(!file){
        cout << "Error opening file" << endl;
        return root;
    }

    while(getline(file, input_line)){

        // Stream con 
        stringstream linestream(input_line);

        // Ingresando nombre y cedula en variables string
        getline(linestream, name, ',');
        getline(linestream, id_string, ',');

        // Probando si el formato es correcto para crear un nodo
        if(check_format(name, id_string)>0){
  
        root=insert(root, name, id_string);
        elements++;
        }

        total++;
    }

    file.close();

    cout << "Elements read: " << total << endl;
    cout << "Elements inserted correctly: " << elements << endl;
    cout << "Errors: " << total-elements << endl;
    return root;

}

//Funcion para comprobar si el formato ingresado es correcto
int check_format(string name, string id_string){

    int letters;
    long int id;
    char* end;
    long int max_val = 999999999;
    char buffer[name.size()];

    // Primero se prueba si la cedula es correcta
    id=strtol(id_string.c_str(), &end, 10);

    // Solamente numerico y positivo
    if(*end != '\0' || id<=0){
        //cout << "Formato invalido en cedula" << endl;
        return E_NOT_NUM;
    }

    // No excede 9 digitos
    else if(id>max_val){
        //cout << "Cedula invalida" << endl;
        return E_OUT_OF_BOUND;
    }

    // Probar si el nombre es adecuado
    strcpy(buffer, name.c_str());
    letters=name.size();

    // Recorre el string viendo si solo son letras
    for(int i=0; i<letters; i++){
        if(!isalpha(buffer[i]) && buffer[i]!= ' '){
            return E_INVALID_NAME;
        }
    }

    return VALID_FORMAT;
}

// Funcion para insertar
node* insert(node* root, string name, string id_string){

    uint32_t id;
    char* end;
    int balance;

    // Probando si tiene formato correcto
    if(check_format(name, id_string)<0){
        return root;
    }

    id=strtol(id_string.c_str(), &end, 10);

    // Crear un nuevo nodo
    if(root==nullptr){
        root=create_node(name, id_string);
        return root;
    }

    else if(id < root->id){
        root->l=insert(root->l, name, id_string);
    }

    else if(id > root->id){
        root->r=insert(root->r, name, id_string);
    }

    else{
        cout << "El numero ya se encuentra en la lista" << endl;
        return root;
    }

    // Encontrar las alturas del arbol
    root->h=max_value(get_height(root->l), get_height(root->r))+1;

    balance=isBalanced(root);

    // Caso que se tenga que hacer rotacion RR
    if (balance<-1 && id > root->r->id){
        root=Rot_RR(root);
        return root;
    }

    // Caso rotacion LL
    else if(balance>1 && id<root->l->id){
        root=Rot_LL(root);
        return root;
    }

    // Caso rotacion RL
    else if(balance<-1 && id<root->r->id){
        root=Rot_RL(root);
        return root;
    }

    // Caso rotacion LR
    else if(balance>1 && id>root->l->id){
        root=Rot_LR(root);

        return root;
    }

    return root;
}


// Funcion para crear nodo
node* create_node(string name, string id_string){

    node* new_node= new node;
    uint32_t id;
    char* end;

    id=strtol(id_string.c_str(), &end, 10);

    new_node->name=name;
    new_node->id=id;
    new_node->h=1;
    new_node->r=nullptr;
    new_node->l=nullptr;

    return new_node;
}


// Funcion para encontrar la altura de un nodo
int get_height(node* root){

    if(root==nullptr) return 0;

    return root->h;
}

// Funcion que devuelve numero mayor entre a y b
int max_value(int a, int b){

    if(a>b) return a;
    else if(b>a) return b;
    else return a;

}

// Imprimir alturas del arbol
void print_height(node* A){

    if(A != nullptr){
    cout << "The h of: "<<A->id<<" is: ";
    cout <<A->h<<endl;
    print_height(A->l);
    print_height(A->r);
    }
}

// Funcion para comprobar si el arbol es balanceado
int isBalanced(node* root){

    int left_h, right_h, k;

    if(root==nullptr) return 0;

    left_h=get_height(root->l);
    right_h=get_height(root->r);

    k=left_h-right_h;

    return k;

}

// Rotacion RR
node* Rot_RR(node* root){

    node* x=root->r;
    node* temp=x->l;

    x->l=root;
    root->r=temp;

    root->h=max_value(get_height(root->l), get_height(root->r))+1;
    x->h=max_value(get_height(x->l), get_height(x->r))+1;
    x->r->h=max_value(get_height(x->l->l), get_height(x->r->r))+1;


    return x;
}

// Rotacion LL
node* Rot_LL(node* root){

    node* x=root->l;
    node* temp=x->r;

    x->r=root;
    root->l=temp;

    root->h=max_value(get_height(root->l), get_height(root->r))+1;
    x->h=max_value(get_height(x->l), get_height(x->r))+1;
    x->l->h=max_value(get_height(x->l->l), get_height(x->r->r))+1;

    return x;
}

// Rotacion RL
node* Rot_RL(node* root){

    node* y=root->r;
    node* x=y->l;

    // Primera rotacion
    y->l=x->r;
    x->r=y;

    //Segunda rotacion
    root->r=x->l;
    x->l=root;

    root->h=max_value(get_height(root->l), get_height(root->r))+1;
    y->h=max_value(get_height(y->l), get_height(y->r))+1;
    x->h=max_value(get_height(x->l), get_height(x->r))+1;

    return x;
}

// Rotacion LR
node* Rot_LR(node* root){

    node* y=root->l;
    node* x=y->r;

    // Primera rotacion
    y->r=x->l;
    x->l=y;

    // Segunda rotacion
    root->l=x->r;
    x->r=root;

    y->h=max_value(get_height(y->l), get_height(y->r))+1;
    root->h=max_value(get_height(root->l), get_height(root->r))+1;
    x->h=max_value(get_height(x->l), get_height(x->r))+1;

    return x;
}

// Escoger lista
int build_all_trees(){

    string input_line, chosen;
    string list, str;
    int counter=0;
    node* root=new node;
    node* max=new node;
    node* min=new node;

    ifstream file("../DataBase/control_parameters.txt");

    while(getline(file, input_line)){

        stringstream linestream(input_line);

        list="../DataBase/";
        getline(linestream, chosen);
        cout << "Building tree for: " << chosen << endl;
        list.append(chosen);

        int start_s=clock();
        root=build_tree(list);
        max=get_max(root);
        min=get_min(root);
        int stop_s=clock();

        double time=(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000;
        write_runnning_times(time, chosen);
        write_max_and_min(max, min, chosen);

        cout << endl;
        list.clear();
        counter++;
    }

    cout << "Number of lists read: " << counter<<endl;
    return 0;
}

//Imprimir el valor de root
int print_root(node* root){

    if(root==nullptr){
        cout << "Root es nulo" << endl;
        return E_NULL_ROOT;
    }

    else{
        cout << "The root is: ";
        cout << root->name;
        cout << ", " << root->id << endl;
    }

    return ROOT_NOT_NULL;
}

//Obtener altura maxima
int get_max_height(node* root){

    if(root==nullptr){
        return E_NULL_ROOT;
    }
    return root->h;
}

// Buscar cedula
int search(node* root, uint32_t id){

    while(root!=nullptr){
        if(root->id == id){
            return FOUND_IT;
        }
        else if(id<root->id) root=root->l;
        else root=root->r;
    }

    return E_NOT_FOUND;
}

// Contador de nodos
int count_nodes(node* root){
    int count=1;

    if(root->l!=nullptr){
        count+=count_nodes(root->l);
    }

    if(root->r!=nullptr){
        count+=count_nodes(root->r);
    }
    return count;
}

// Obtener el valor maximo
node* get_max(node* root){

    while(root->r != nullptr){
        root=root->r;
    }

    return root;
}

// Obtener el valor minimo
node* get_min(node* root){

    while(root->l != nullptr){
        root=root->l;
    }
    return root;
}

// Escribir archivo de texto
int write_max_and_min(node* max, node* min, string list){

    ofstream output;

    output.open("../misc/output/max_and_min_id.txt", ofstream::app);

    if(!output){
        cout << "No se pudo escribir el archivo de texto." << endl;
        return E_WRITING_FILE;
    }

    output << "Para la lista " << list << " los valores maximos y minimos son:" << endl;
    output << "El valor maximo es: " << max->name << ", cedula: " << max->id << endl;
    output << "El valor minimo es: " << min->name << ", cedula: " << min->id << endl;
    output << endl;

    output.close();

    return SUCCESS_FILE;
}

// Escribir archivo de texto
int write_runnning_times(double time, string list){

    ofstream output;

    output.open("../misc/output/running_times.txt", ofstream::app);

    if(!output){
        cout << "No se pudo escribir el archivo de texto." << endl;
        return E_WRITING_FILE;
    }

    output << "El tiempo de ejecucion de la lista " << list << " es " << time << " ms." << endl;

    output.close();

    return SUCCESS_FILE;
}

// Borrar el arbol
int delete_tree(node* root){

    node* left_child= root->l;
    node* right_child=root->r;

    if(left_child!=nullptr) delete_tree(left_child);
    if(right_child!=nullptr) delete_tree(right_child);

    delete root;

    return FREE;
}