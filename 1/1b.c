/**
 * @brief Converte una stringa in naturale (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato tipicamente scorretto).
 */
int stoub(char *s, unsigned short b, int*r) {
    int ret = 0;
    if (b < 2 || b > 36) {
        return ret; // Se la base non è nel range valido, restituisce 0
    }
    
    int sign = 1;
    // Ignoriamo eventuali spazi bianchi iniziali
    while (isspace(*s)) {
        s++;
    }
    
    // Gestiamo il segno (+/-) se presente
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    
    int result = 0;
    bool specialCharacter = true; // Utilizziamo un flag per indicare la presenza di caratteri speciali (Non alfabeto :D)
    for (; *s != '\0' && specialCharacter; s++) {
        int digitValue = -1;
        if (isdigit(*s)) {
            digitValue = *s - '0';
            ret = 1; // Indica che almeno una cifra valida è stata trovata
        } else if (isalpha(*s)) {
            digitValue = toupper(*s) - 'A' + 10; // Conversion tramite valore ASCII
            ret = 1; // Indica che almeno una cifra valida è stata trovata
        }
        if (digitValue <= b && digitValue != -1) {
            result = result * b + digitValue;
        } else if (digitValue == -1) {
            specialCharacter = false; // Termina il ciclo se incontra un carattere non valido
        }
    }
    *r = result * sign; // Assegna il risultato al puntatore
    return ret; // Restituisce 1 se almeno una cifra valida è stata trovata, altrimenti 0
}