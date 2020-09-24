// ex4
typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List _cria_lista();
int _lista_vazia(List);
int _insere_soldado(List*, char*);
void _printa_lista(List);
void _remove_cur_next(List);
void _contador_elimina(List*, List, int, int, char*);