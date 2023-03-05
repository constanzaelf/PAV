#include <stdio.h>
#include "fic_wave.h"
// esta funcion abre como fichero bianrio para lectura 

FILE    *abre_wave(const char *ficWave, float *fm) {
    FILE    *fpWave;

    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL;
    // va a la posicion 44 pq nos saltamos la cabecera 
    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;
    // frecuencia de muestreo
    fseek(fpWave,44,SEEK_SET);
    *fm = 16000;

    return fpWave;
}

size_t   lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave);
}

void    cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}
