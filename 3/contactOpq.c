#include "contactOpq.h"

struct contact {
   char* name; 
   char* surname;
   char* mobile;
   char* url;
};

ContactPtr mkContact(char* name, char* surname, char* mobile, char* url){
    if(name == NULL || surname == NULL){
        return NULL;
    }
    ContactPtr cnt = (ContactPtr)malloc(sizeof(Contact));
    if(cnt != NULL){
        cnt->name = name;
        cnt->surname = surname;
        cnt->mobile = mobile;
        cnt->url = url;
    }
    return cnt;
}

void dsContact(ContactPtr* cntptr) {
    if (*cntptr != NULL) {  // Verifica se il puntatore non è NULL
        free(*cntptr);       // Dealloca la memoria allocata per la struttura Contact
        *cntptr = NULL;      // Imposta il puntatore a NULL
    }
}

void updateMobile(ContactPtr cnt, char* newMobile){
    cnt->mobile = newMobile;
}

void updateUrl(ContactPtr cnt, char* newUrl){
    cnt->url = newUrl;
}

char* getName(const ContactPtr cnt){
    return cnt->name;
}

char* getSurname(const ContactPtr cnt){
    return cnt->surname;
}

char* getMobile(const ContactPtr cnt){
    return cnt->mobile;
}

char* getUrl(const ContactPtr cnt){
    return cnt->url;
}


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

_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2){
    int ret = 0;
    if(stricmp(cnt1->name, cnt2->name) == 0 && stricmp(cnt1->surname,cnt2->surname) == 0){
        ret = 1;
    }
    return ret;
}

int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2){
    int surnameComparison = stricmp(cnt1->surname, cnt2->surname);
    if (surnameComparison != 0) {
        return (surnameComparison < 0) ? -1 : 1;
    }

    int nameComparison = stricmp(cnt1->name, cnt2->name);
    return (nameComparison < 0) ? -1 : (nameComparison > 0) ? 1 : 0;
}