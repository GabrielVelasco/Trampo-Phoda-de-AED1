typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista);
int libera_lista(Lista *lista);
int insere_elemento(Lista *lst,int elem);
int get_elemento(Lista lista, int pos, int *numero);
int tamanho(Lista lista);
int remove_elemento(lista *lst,int elem)
int remove_maior_elemento(Lista *lista);
int remove_todos(Lista *lista,int elem);
int esvazia(Lista *lista);
Lista multiplo_de_3(Lista);
