typedef struct no *Lista;

Lista cria_lista();
int get_pos(Lista lst, int *p, int *c, int pos);
int insere_termo(Lista *lst, int p, int c);
