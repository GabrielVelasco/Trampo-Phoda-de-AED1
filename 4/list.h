typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int, char*);
int emptyList(List);
int insertOrd(List, char);
int removeOrd(List, char);
int getSize(List);
int comparaLista(List, List);
int maiorElem(List, char*);
void imprimiLista(List);
void intercalar(List, List, List);
int esvaziaLista(List);