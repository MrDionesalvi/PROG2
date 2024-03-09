#include "contact.h"


/**
 * La funzione `stricmp` confronta due stringhe in modo non case-sensitive in C.
 * 
 * @param s1 Il parametro `s1` è un puntatore a un carattere costante (stringa) che rappresenta la prima
 * stringa da confrontare in modo non case-sensitive.
 * @param s2 La funzione `stricmp` fornita confronta due stringhe `s1` e `s2` in modo non case-sensitive.
 * Itera su ciascun carattere delle stringhe, convertendoli in minuscolo tramite la funzione `tolower`,
 * e quindi li confronta. Se viene trovata una differenza, restituisce il risultato.
 * 
 * @return La funzione `stricmp` è una funzione di confronto delle stringhe non case-sensitive.
 * Confronta due stringhe `s1` e `s2` in modo non case-sensitive. Se le stringhe sono uguali, restituisce 0.
 * Se `s1` è minore di `s2`, restituisce un valore negativo. Se `s1` è maggiore di `s2`, restituisce un valore positivo.
 */

int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int cmp = tolower(*s1) - tolower(*s2);
        if (cmp != 0)
            return cmp;
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}

_Bool contactEq(Contact c1, Contact c2){
    int ret = 0;
    if(stricmp(c1.name, c2.name) == 0 && stricmp(c1.surname,c2.surname) == 0){
        ret = 1;
    }
    return ret;
}

_Bool contactEqEff(const Contact const *pc1, const Contact const *pc2){
    int ret = 0;
    if(stricmp(pc1->name, pc2->name) == 0 && stricmp(pc1->surname,pc2->surname) == 0){
        ret = 1;
    }
    return ret;
}

int contactCmp(Contact c1, Contact c2) {
    int surnameComparison = stricmp(c1.surname, c2.surname);
    if (surnameComparison != 0) {
        return (surnameComparison < 0) ? -1 : 1;
    }

    int nameComparison = stricmp(c1.name, c2.name);
    return (nameComparison < 0) ? -1 : (nameComparison > 0) ? 1 : 0;
}

int contactCmpEff(const Contact const *pc1, const Contact const *pc2){
    int surnameComparison = stricmp(pc1->surname, pc2->surname);
    if (surnameComparison != 0) {
        return (surnameComparison < 0) ? -1 : 1;
    }

    int nameComparison = stricmp(pc1->name, pc2->name);
    return (nameComparison < 0) ? -1 : (nameComparison > 0) ? 1 : 0;
}

