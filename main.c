#include<stdio.h>
#include <string.h>


struct Mjek {
    int id;
    char emri[25];
    char specializimi[60];
};

void shtoni_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh);
void fshini_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh);
void ndryshoni_te_dhenat_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh);



int main()
{
    int max_mjek = 20;
    struct Mjek mjek[100]={{0}};
    int numerues_mjekesh = 3;
    //vlera per vektorin test
    mjek[0].id = 677;
    strcpy(mjek[0].emri, "ArjelFasliu");
    strcpy(mjek[0].specializimi, "eee");
    
    mjek[1].id = 678;
    strcpy(mjek[1].emri, "Arjel");
    strcpy(mjek[1].specializimi, "aaa");
      
        mjek[2].id = 679;
    strcpy(mjek[2].emri, "Egerta");
    strcpy(mjek[2].specializimi, "ooo");
    
    //afishojm vektorin mjek test
    for(int i=0; i<max_mjek;i++){
        printf("%d. %d %s %s \n",i,mjek[i].id,mjek[i].emri,mjek[i].specializimi);
    }
    
    // THERRIT FUNKSIONET.
    //shtoni_mjek(mjek,&numerues_mjekesh);
    //fshini_mjek(mjek,&numerues_mjekesh);
    //ndryshoni_te_dhenat_mjek(mjek,&numerues_mjekesh);

    //afishojm vektorin mjek test
    for(int i=0; i<max_mjek;i++){
        printf("%d. %d %s %s \n",i,mjek[i].id,mjek[i].emri,mjek[i].specializimi);
    }

    
    return 0;
}
void ndryshoni_te_dhenat_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh){
    struct Mjek mjek={0};
    int input;
    int index=-1;
    
    printf("-----Admin-----\n");
    printf("3. Ndryshoni të dhënat e një mjeku ekzistues.\n");
    printf("---------------\n"); 
    
    printf("Jep ID: (int)\n");
    scanf("%d",&input);
    
    for(int i=0;i<*numerues_mjekesh;i++){
        mjek = *(p_mjeket+i);
        if(mjek.id == input){ 
            index=i;//nese ekziston nje mjek e etikojm index dhe ndalojm bredhjen
            break;
        }
        
    }
    if(index == -1){
        printf("Mjeku me kete ID nuk egziston\n");
        return; // nese nuk ekziston nje mjek ndalojm f(x).
    } 
    
    printf("Te dhenat prezente: %d %s %s.\n",mjek.id,mjek.emri,mjek.specializimi);
    printf("Jep ID: (%d)\n",mjek.id);
    scanf("%d",&mjek.id);
    printf("Jep Emrin: (%s)\n",mjek.emri);
    scanf("%s",mjek.emri);
    printf("Jep Specializimin: (%s)\n",mjek.specializimi);
    scanf("%s",mjek.specializimi);
    
    *(p_mjeket+index) = mjek;
    printf("Te dhenat pas ndryshimit: %d %s %s\n",mjek.id,mjek.emri,mjek.specializimi);
}
void shtoni_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh){
    if(*numerues_mjekesh == 100){
        printf("Manual error: Nuk ka me vend per te ruajtur nje mjek te ri.");
        return;
    }
        
    struct Mjek mjek;
    printf("-----Admin-----\n");
    printf("1. Shtoni nje mjek te ri.\n");
    printf("---------------\n");
    
    printf("Jep ID: (int)\n");
    scanf("%d",&mjek.id);

    printf("Jep EMRIN: (String)\n");
    scanf("%s",mjek.emri);

    
    printf("Jep SPECIALIZIMIN: (String)\n");
    scanf("%s",mjek.specializimi);
    
    *(p_mjeket+*numerues_mjekesh) = mjek;
    *numerues_mjekesh++;
    printf("---Mjeku u shtua me sukses.\n");   

}
void fshini_mjek(struct Mjek *p_mjeket,int *numerues_mjekesh){

    int input;
    int flag=0;
    
    printf("-----Admin-----\n");
    printf("1. Fshini nje mjek.\n");
    printf("---------------\n"); 
    
    printf("Jep ID: (int)\n");
    scanf("%d",&input);
    
    for(int i=0;i<*numerues_mjekesh;i++){
        struct Mjek mjek_perkates = *(p_mjeket+i);
        struct Mjek mjek_pasardhes = *(p_mjeket+i+1);
        if(mjek_perkates.id==input)
            flag=1;
        if(flag){
            if(i==99){ //nese jemi ne index e fundit e fshijm
                mjek_perkates.id = 0;
                strcpy(mjek_perkates.emri,"");
                strcpy(mjek_perkates.specializimi,"");
                *(p_mjeket+i) = mjek_perkates;
            }else { //mbishkruajm mjekun perkates me te dhenat e mjekut pasardhes 
                mjek_perkates.id = mjek_pasardhes.id;
                strcpy(mjek_perkates.emri,mjek_pasardhes.emri);
                strcpy(mjek_perkates.specializimi,mjek_pasardhes.specializimi);
                *(p_mjeket+i) = mjek_perkates;
            }

        }
        
    }
    if(flag){
        *numerues_mjekesh--;
        printf("---Mjeku u fshi me sukses.\n");
    }else 
        printf("---Mjeku nuk u gjet.\n");
    
}
