#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int *adresa;
typedef struct TNod
{
    int nr;
    TNod *urm;
}TNod;
TNod *lista;
TNod *prim, *ultim, *crt;
void init(TNod *primul, TNod *ultimul)
{
    ultimul = primul = NULL;
}
TNod *aloc_mem()
{
    TNod *p = NULL;
    p =(TNod *)malloc(sizeof(TNod));
    if(!p)
        return NULL;
    return p;
}
void adaug_prim(int n)
{
    TNod *nod;
    nod = aloc_mem();
    nod->nr = n;
    nod->urm = NULL;
    prim = ultim = crt = nod;
}
void adaug_elem(int n)
{
    TNod *nod;
    nod = aloc_mem();
    nod->nr = n;
    nod->urm = NULL;
    crt->urm = nod;
    crt = ultim = nod;
}
void afis_lista(int nr_elem)
{
    TNod *nod;
    nod = prim;
    while(nr_elem >= 3){
        cout << nod->urm->urm->nr << " ";
        cout << nod->urm->nr << " ";
        cout << nod->nr << " ";
        prim = prim->urm->urm->urm;
        nod = prim;
        nr_elem -= 3;
    }
    if(nod == NULL)
        return;
    else{
        while(nod != NULL){
            cout << nod->nr << " ";
            nod = nod->urm;
        }
    }
}
int main()
{
    int x, n, nr_elem = 0;
    init(prim, ultim);
    cout << "introduceti un prim elment? (tastati 1 pentru DA / 0 pentru NU)";
    cin >> x;
    if(x){
        cout<<"Introduceti elementul: ";
        cin >> n;
        adaug_prim(n);
        nr_elem++;
    }
    else
        return 0;
    int bec = 1;
    while(bec){
        cout << "Mai introduceti elemente in lista? (tastati 1 pentru DA / 0 pentru NU)";
        cin >> x;
        if(x){
            cout<<"Introduceti elementul: ";
            cin >> n;
            adaug_elem(n);
            nr_elem++;
        }
        else
            bec = 0;
    }
    afis_lista(nr_elem);
    return 0;
}
