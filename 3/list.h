// ex3
typedef struct node* List;

List createList();
int emptyList(List);
int insertOrd(List*, float);
int removeOrd(List*, float);
int clearList(List*);
int getElem(List, int, float*);
int getSize(List);
int getElem(List, int, float*);
int comparaLista(List, List);
void imprimiLista(List);
void intercalar(List, List, List*);