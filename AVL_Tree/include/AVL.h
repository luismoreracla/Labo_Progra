// Luis Morera Claramunt. B44726.

#include <iostream>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;

enum errors{
    E_NOT_NUM=-1,
    E_OUT_OF_BOUND=-2,
    E_INVALID_NAME=-3,
    E_NULL_ROOT=-4,
    E_NOT_FOUND=-5,
    E_WRITING_FILE=-6,
};

enum success{
    VALID_FORMAT=1,
    ROOT_NOT_NULL=2,
    FOUND_IT=3,
    SUCCESS_FILE=4,
    FREE=5,
};

// Estructura de los nodos
struct node {
    uint32_t id;
    uint32_t h;
    string name;
    node* l;
    node* r;
};

// Prototipo de las funciones a utilizar
node* build_tree(string list);
int check_format(string name, string id_string);
node* insert(node* root, string name, string id_string);
node* create_node(string name, string id_string);
int get_height(node* root);
int max_value(int a, int b);
int isBalanced(node* root);
node* Rot_RR(node* root);
node* Rot_LL(node* root);
node* Rot_RL(node* root);
node* Rot_LR(node* root);
int delete_tree(node* root);
int search(node* root, uint32_t id);
int build_all_trees();
int print_root(node* root);
void print_height(node* root);
int get_max_height(node* root);
int search(node* root, uint32_t id);
int count_nodes(node* root);
int write_max_and_min(node* max, node* min, string list);
int write_runnning_times(double time, string list);
node* get_max(node* root);
node* get_min(node* root);