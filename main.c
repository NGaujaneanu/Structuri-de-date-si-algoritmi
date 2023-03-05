#include <stdio.h>
#include <stdlib.h>


typedef struct nodLista{

    int valoare;
    struct nodLista *Urm;

}nodLista;

nodLista *lista;
nodLista *prim, *curent, *ultim;

int adaugaPrimulNod(int n){

    nodLista *nod = NULL;

    nod = (nodLista *)malloc(sizeof(nodLista));
    if(!nod)
        return NULL;

    nod->valoare = n;
    nod->Urm = NULL;
    prim = ultim = curent = nod;

}

int adaugaElement(int n){

    nodLista *nod = NULL;

    nod =(nodLista *)malloc(sizeof(nodLista));
    if(!nod)
        return NULL;

    nod->valoare = n;
    nod->Urm = NULL;

    curent->Urm = nod;
    curent = ultim = nod;

}

void afiseazaLista(int nrElem){

    nodLista *nod;
    nod = prim;

    while(nrElem >= 3){

        printf("%d ", nod->Urm->Urm->valoare);

        printf("%d ", nod->Urm->valoare);

        printf("%d ", nod->valoare);

        prim = prim->Urm->Urm->Urm;
        nod = prim;
        nrElem -= 3;

    }

    if(nod == NULL)
        return;

    else{
        while(nod != NULL){

            printf("%d ", nod->valoare);
            nod = nod->Urm;

        }
    }
}

int main(){

    int n, nrElem = 0;

    int a;

    nodLista *prim = NULL;
    nodLista *ultim = NULL;

    printf("Introduceti primul element in lista? 1 - DA / 0 - NU");
    scanf("%d", &a);

    if(a){
        printf("Introduceti elementul: ");
        scanf(" %d", &n);
        adaugaPrimulNod(n);
        nrElem++;
    }
    else
        return 0;

    int ok = 1;



    while(ok){

        printf("Introduceti alt element in lista? 1 - DA / 0 - NU\n");
        scanf(" %d", &a);

        if(a){
            printf("Introduceti elementul: ");
            scanf(" %d", &n);
            adaugaElement(n);
            nrElem++;
        }


        else
            ok = 0;

    }

    afiseazaLista(nrElem);

    return 0;
}
