#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void genJak(){
    /*grid init*/
    char** jak=malloc(sizeof(char*)*20);
    for(int i=0;i<20;++i){
        jak[i]=malloc(sizeof(char)*40);
        for(int j=0;j<40;++j)
            jak[i][j]='.';
    }
    /*choose a random outline*/
    /*deal with error*/
    FILE* file;
    file=fopen("outlines", "r");
    if(!file){
        printf("\e[1;31mSTUPID FUCKER MUST HAVE FILE CALLED 'outlines' IN THIS FOLDER. I WILL RAPE YOU BITCH. NEXT TIME I'LL PUT A RAT HERE FAG\e[0m\n");
        exit(-1);
    }
    /*read file*/
    int linenum=rand()%2,currline=1;
    linenum*=20;++linenum;
    int jline=0;
    char line[80];
    while(fgets(line, 80, file)!=NULL){
        if(currline >= linenum && currline < linenum+20){
            strcpy(jak[jline], line);
            ++jline;
        }
        ++currline;
    }
    /*add eyes to our outline*/
    /*file error again*/
    file=fopen("eyes", "r");
    if(!file)
        printf("\e[1;31mCUNT! I NEED THERE TO BE A FILE CALLED 'eyes' IN THIS FOLDER! I'M GONNA RAPE YOU SOON ENOUGH ;) HAVE FUN!\e[0m\n");
    /*reset vars*/
    linenum=rand()%2,currline=1;
    linenum*=4;++linenum;
    jline=0;
    char eline[10];
    /*read em*/
    while(fgets(eline, 10, file)!=NULL){
        if(currline >= linenum && currline < linenum+4)
            printf("%s",eline);
        ++currline;
    }
    /*print out our jak*//*
    for(int y=0;y<20;++y){
        for(int x=0;x<40;++x){
            printf("%c",jak[y][x]);
        }
        printf("\n");
    }*/
}
int main(){
    srand(time(NULL));
    genJak();
}
