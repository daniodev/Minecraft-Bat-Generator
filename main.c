#include <stdio.h>
#include <stdlib.h>

int main(){

    char nomeFile[50];
    printf("Inserisci il nome del file, estenzione in clusa: ");
    scanf("%s", nomeFile);

    char percorso[500];
    printf("Inserisci il percorso del file (inserisci . per impostare questa directory) : ");
    scanf("%s", percorso);

    char percorsoCompleto[500];
    if(percorso[0] == '.'){
        sprintf(percorsoCompleto, "%s", nomeFile);
    }else{
        sprintf(percorsoCompleto, "%s\\%s", percorso , nomeFile);
    }

    FILE *FileNuovo = fopen(percorsoCompleto, "a+");
    if(FileNuovo == NULL){
        printf("Impossibile generare il file.");
        exit(EXIT_FAILURE);
    }
    
    char gigaDiMemoria[4];
    printf("Inserisci i giga o megabyte di memoria ram che occuperera il server (esempio 2GB): ");
    scanf("%s", gigaDiMemoria);

    char nomeFileJar[50];
    printf("Inserisci il nome del file jar estenzione inclusa: ");
    scanf("%s", nomeFileJar);

    fprintf(FileNuovo, "java -Xmx%s -Xms%s -jar %s nogui \npause", gigaDiMemoria, gigaDiMemoria, nomeFileJar);

    fclose(FileNuovo);

}