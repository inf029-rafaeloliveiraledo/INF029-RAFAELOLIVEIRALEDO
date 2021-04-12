#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 50
#define TAM2 40
#define TAM3 20
#define DISC 10
int counta1,countp1,countd1;
int countd11;
struct dados{
        char nome[TAM2],sexo,dataNascimento[TAM3],cpf[TAM3];
        int matricula,dia,mes,ano,data;
}aluno[TAM],professor[TAM];
struct disc{
    char nome[TAM2],semestre[TAM3],professor[TAM2],alunos[TAM][TAM2],codigo[TAM3];
}disciplina[DISC];
void CadastroAluno(char nome[TAM2],char sexo,char dataNascimento[TAM3],char cpf[TAM3], int matricula){
    setlocale(LC_ALL,"Portuguese");
    int i=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,dia,mes,ano,contcpf=0,cont=0;
    int h=11,result=0,result2,aux=0,z=1,a=12,b=1,resultado=0,resultado2,e=1;
    int l,k,j,t;
    do{
    if(cont==0){
        printf("Digite uma das opções do menu secundário do aluno %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Sexo\n3- Inserir ou modificar Data de Nascimento\n4- Inserir ou modificar Cpf\n"
        "5- Gerar matrícula\n6- Exluir cadastro do aluno atual\n0- Sair do menu\n", counta1);
        cont++;
    }
    else{
        printf("Digite uma das opções do menu secundário: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
            cont1=0;
            setbuf(stdin,NULL);
            printf("Digite o nome do aluno %d: ", counta1);
            fgets(aluno[counta1-1].nome,TAM2-2,stdin);
            aluno[counta1-1].nome[strlen(aluno[counta1-1].nome)-1]='\0';
            printf("%s\n", aluno[counta1-1].nome);
            if(((nome[0]-'0')>=0 && (nome[0]-'0')<=9) || ((nome[0]-'0')>=-9 && (nome[0]-'0')<=0 ) || (strlen(nome)>TAM3)){
                printf("\nNome inválido.");
            }
            cont1++;
            break;}
        case 2:{
            cont2=0;
            setbuf(stdin,NULL);
            printf("Digite o sexo; m,f ou o para masculino, feminino ou outro: ");
            scanf(" %c", &aluno[counta1-1].sexo);
            printf("%c\n",aluno[counta1-1].sexo);
            switch(aluno[counta1-1].sexo){
                case 'm':
                case 'M':
                cont2++;
                break;
                case 'f':
                case 'F':
                cont2++;
                break;
                case 'o':
                case 'O':
                cont2++;
                break;
                default:{
                    printf("\nSexo inválido\n.");
                    sexo='\0';
                break;}
            }
            cont2++;

        break;}
        case 3:{
            cont3=0;
            printf("Digite a data de nascimento com barras: ");
            setbuf(stdin,NULL);
            fgets(aluno[counta1-1].dataNascimento,TAM3-2,stdin);
            aluno[counta1-1].dataNascimento[strlen(aluno[counta1-1].dataNascimento)-1]='\0';
            printf("%s\n", aluno[counta1-1].dataNascimento);
            dia=(dataNascimento[0]-'0')*10;
            dia+=dataNascimento[1]-'0';
            mes=(dataNascimento[3]-'0')*10;
            mes+=dataNascimento[4]-'0';
            ano=(dataNascimento[6]-'0')*1000;
            ano+=(dataNascimento[7]-'0')*100;
            ano+=(dataNascimento[8]-'0')*10;
            ano+=dataNascimento[9]-'0';
            if(dia<1 || dia>31){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes<1 || mes>12){
                printf("Data de nascimento inválida.\n");
            }
            else if(ano<1900 || ano>2100){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes == 4 || mes == 6 || mes==9 || mes==11){
                if(dia>30){
                    printf("Data de nascimento inválida.\n");
                }
            }
            else if((ano%4==0 && ano%100>0 )|| (ano%4==00 && ano%100==0 && ano%400==0)){
                if(mes==2){
                    if(dia>29){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            else{
                if(mes==2){
                    if(dia>28){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            cont3++;

        break;}
        case 4:{
            contcpf=0,cont4=0,h=11,result=0,aux=0,z=1,a=12,b=1,resultado=0,e=1;
            printf("Digite o cpf com ponto e hífen: ");
            setbuf(stdin,NULL);
            fgets(aluno[counta1-1].cpf,TAM3-2,stdin);
            aluno[counta1-1].cpf[strlen(aluno[counta1-1].cpf)-1]='\0';
            printf("%s\n", aluno[counta1-1].cpf);
            for(l=0;l<=9;l++){
                if(aux==11){
                    printf("\nCpf inválido.");
                    contcpf++;
                }
                aux=0;
                for(k=0;k<=13;k++){
                    if((cpf[k]-'0')==l){
                        aux++;
                    }
                }
            }
            for(j=0;j<=10;j++){
                if((cpf[j])!='.'){
                    result+=(cpf[j]-'0')*(h-z);
                }
                else{
                    z--;
                }
                z++;
            }
            if((result*10)%11==10){
                result2=0;
            }
            if((result*10)%11==cpf[12]-'0' || result2==cpf[12]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            for(b=0;b<=12;b++){
                if((cpf[b])!='.' && (cpf[b])!= '-'){
                    resultado+=(cpf[b]-'0')*(a-e);
                }
                else{
                    e--;
                }
                e++;
            }
            if((resultado*10)%11==10){
                resultado2=0;
            }
            if((resultado*10)%11==cpf[13]-'0' || resultado2==cpf[13]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            if(contcpf==0){
                cont4++;
            }
            cont4++;

        break;}
        case 5:{
            aluno[counta1-1].matricula=counta1;
            printf("%d\n", aluno[counta1-1].matricula);
        }
        cont5++;
        case 6:{
        for(t=0;t<39;t++){
            aluno[counta1-1].nome[t]='\0';
            }
        sexo='\0';
        for(t=0;t<12;t++){
            aluno[counta1-1].dataNascimento[t]='\0';
        }
        for(t=0;t<16;t++){
            aluno[counta1-1].cpf[t]='\0';
        }
        break;}
        default:
        break;
    }
    }
    while(i);
    if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
        printf("Não foram digitados todos os dados.\n");
    }
}
void CadastroProfessor(char nome[TAM2],char sexo,char dataNascimento[TAM3],char cpf[TAM3], int matricula){
    setlocale(LC_ALL,"Portuguese");
    int dia,mes,ano;
    int i=0;
    int cont=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,contcpf=0;
    int h=11,result=0,result2,aux=0,z=1,a=12,b=1,resultado=0,resultado2,e=1;
    int l,k,j,t;
    do{
    if(cont==0){
        printf("Digite uma das opções do menu secundário do professor %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Sexo\n3- Inserir ou modificar Data de Nascimento\n4- Inserir ou modificar Cpf\n"
        "5- Gerar matricula\n6- Excluir cadastro do professor atual\n0- Sair do menu\n", countp1);
        cont++;
    }
    else{
        printf("Digite uma das opções do menu secundário: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
            cont1=0;
            setbuf(stdin,NULL);
            printf("Digite o nome do professor %d: ", countp1);
            fgets(professor[countp1-1].nome,TAM2-2,stdin);
            professor[countp1-1].nome[strlen(professor[countp1-1].nome)-1]='\0';
            printf("%s\n",professor[countp1-1].nome);
            if(((professor[countp1-1].nome[0]-'0')>=0 && (professor[countp1-1].nome[0]-'0')<=9) || ((professor[countp1-1].nome[0]-'0')>=-9 && (professor[countp1-1].nome[0]-'0')<=0 ) || (strlen(professor[countp1-1].nome)>TAM3)){
                printf("\nNome inválido.");
            }
            else{
                cont1++;
            }
        break;}
        case 2:{
            cont2=0;
            printf("Digite o sexo; m,f ou o para masculino, feminino ou outro: ");
            setbuf(stdin,NULL);
            scanf(" %c", &professor[countp1-1].sexo);
            printf("%c\n",professor[countp1-1].sexo);
            switch(professor[countp1-1].sexo){
                case 'm':
                case 'M':
                cont2++;
                break;
                case 'f':
                case 'F':
                cont2++;
                break;
                case 'o':
                case 'O':
                cont2++;
                break;
                default:{
                    sexo='\0';
                    printf("Sexo inválido\n.");
                break;}
            }


        break;}
        case 3:{
            cont3=0;
            printf("Digite a data de nascimento com barras: ");
            setbuf(stdin,NULL);
            fgets(professor[countp1-1].dataNascimento,TAM3-2,stdin);
            professor[countp1-1].dataNascimento[strlen(professor[countp1-1].dataNascimento)-1]='\0';
            printf("%s\n",professor[countp1-1].dataNascimento);
            dia=(dataNascimento[0]-'0')*10;
            dia+=dataNascimento[1]-'0';
            mes=(dataNascimento[3]-'0')*10;
            mes+=dataNascimento[4]-'0';
            ano=(dataNascimento[6]-'0')*1000;
            ano+=(dataNascimento[7]-'0')*100;
            ano+=(dataNascimento[8]-'0')*10;
            ano+=dataNascimento[9]-'0';
            if(dia<1 || dia>31){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes<1 || mes>12){
                printf("Data de nascimento inválida.\n");
            }
            else if(ano<1900 || ano>2100){
                printf("Data de nascimento inválida.\n");
            }
            else if(mes == 4 || mes == 6 || mes==9 || mes==11){
                if(dia>30){
                    printf("Data de nascimento inválida.\n");
                }
            }
            else if((ano%4==0 && ano%100>0 )|| (ano%4==00 && ano%100==0 && ano%400==0)){
                if(mes==2){
                    if(dia>29){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            else{
                if(mes==2){
                    if(dia>28){
                        printf("Data de nascimento inválida.\n");
                    }
                }
            }
            cont3++;

        break;}
        case 4:{
            contcpf=0,cont4=0,h=11,result=0,aux=0,z=1,a=12,b=1,resultado=0,e=1;
            printf("Digite o cpf com ponto e hífen: ");
            setbuf(stdin,NULL);
            fgets(professor[countp1-1].cpf,TAM3-2,stdin);
            professor[countp1-1].cpf[strlen(professor[countp1-1].cpf)-1]='\0';
            printf("%s\n",professor[countp1-1].cpf);
            for(l=0;l<=9;l++){
                if(aux==11){
                    printf("\nCpf inválido.");
                    contcpf++;
                }
                aux=0;
                for(k=0;k<=13;k++){
                    if((cpf[k]-'0')==l){
                        aux++;
                    }
                }
            }
            for(j=0;j<=10;j++){
                if((cpf[j])!='.'){
                    result+=(cpf[j]-'0')*(h-z);
                }
                else{
                    z--;
                }
                z++;
            }
            if((result*10)%11==10){
                result2=0;
            }
            if((result*10)%11==cpf[12]-'0' || result2==cpf[12]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            for(b=0;b<=12;b++){
                if((cpf[b])!='.' && (cpf[b])!= '-'){
                    resultado+=(cpf[b]-'0')*(a-e);
                }
                else{
                    e--;
                }
                e++;
            }
            if((resultado*10)%11==10){
                resultado2=0;
            }
            if((resultado*10)%11==cpf[13]-'0' || resultado2==cpf[13]-'0'){
            }
            else{
                printf("\nCpf inválido.");
                contcpf++;
            }
            if(contcpf==0){
                cont4++;
            }

            break;}
            case 5:{
                matricula=countp1;
                printf("%d\n", matricula);
                cont5++;
            break;}
            case 6:{
            for(t=0;t<39;t++){
                nome[t]='\0';
            }
            sexo='\0';
            for(t=0;t<12;t++){
                dataNascimento[t]='\0';
            }
            for(t=0;t<14;t++){
                cpf[t]='\0';
            }
            break;}
            default:
            break;
        }
        }
        while(i);
        if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
            printf("Não foram cadastrados todos os dados.\n");
        }
}
void CadastroDisciplina(char nome[TAM2],char semestre[TAM3],char professor[TAM2],char alunos[50][TAM2],char codigo[TAM3]){
    setlocale(LC_ALL, "Portuguese");
    int cont=0,i=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,k=0,t;
    do{
        if(cont==0){
        printf("Digite uma das opções do menu secundário da disciplina %d:\n1- Inserir ou modificar nome\n2- Inserir ou modificar Semestre\n3- Inserir ou modificar Professor\n4- Inserir ou modificar Alunos\n"
        "5- Inserir ou modificar Código da disciplina\n6- Excluir cadastro feito\n0- Sair do menu\n", countd1);
        cont++;
        }
        else{
            printf("Digite uma das opções do menu secundário da disciplina %d: ", countd1);
        }
        scanf("%d", &i);
        switch(i){
            case 1:{
            cont1=0;
            printf("Digite o nome de uma disciplina: ");
            setbuf(stdin,NULL);
            fgets(disciplina[countd1-1].nome,TAM2-2,stdin);
            disciplina[countd1-1].nome[strlen(disciplina[countd1-1].nome)-1]='\0';
            if(((disciplina[countd1-1].nome[0]-'0')>=0 && (disciplina[countd1-1].nome[0]-'0')<=9) || ((disciplina[countd1-1].nome[0]-'0')>=-9 && (disciplina[countd1-1].nome[0]-'0')<=0 ) || (strlen(disciplina[countd1-1].nome)>TAM3)){
                printf("\nDisciplina inválida.");
            }
            cont1++;
            break;}
            case 2:{
            cont2=0;
            printf("Digite o semestre da disciplina %d (ex: 2019.1): ", countd1);
            setbuf(stdin,NULL);
            fgets(disciplina[countd1-1].semestre,TAM3-2,stdin);
            disciplina[countd1-1].semestre[strlen(disciplina[countd1-1].semestre)-1]='\0';
            printf("%s\n", disciplina[countd1-1].semestre);
            if( disciplina[countd1-1].semestre[4]!='.' ||  disciplina[countd1-1].semestre[5]-'0'>2 || disciplina[countd1-1].semestre[5]-'0'<1 ){
                printf("Semestre Inválido.\n");
            }
            cont2++;
            break;}
            case 3:{
            cont3=0;
            printf("Digite o professor da disciplina %d: ", countd1);
            setbuf(stdin,NULL);
            fgets(disciplina[countd1-1].professor,TAM2-2,stdin);
            disciplina[countd1-1].professor[strlen(disciplina[countd1-1].professor)-1]='\0';
            printf("%s\n", professor);
            if(((disciplina[countd1-1].professor[0]-'0')>=0 && (disciplina[countd1-1].professor[0]-'0')<=9) || ((disciplina[countd1-1].professor[0]-'0')>=-9 && (disciplina[countd1-1].professor[0]-'0')<=0 ) || (strlen(disciplina[countd1-1].professor)>TAM3)){
                printf("\nDisciplina inválida.");
            }
            cont3++;
            break;}
            case 4:{
            cont4=0;
            do{
            printf("Digite qual o numero do aluno a se cadastrar digite um valor de 1 a 50: ");
            setbuf(stdin,NULL);
            scanf("%d", &countd11);
            printf("Digite o nome do aluno %d da disciplina %s: ", countd11, nome);
            setbuf(stdin,NULL);
            fgets(disciplina[countd1-1].alunos[countd11-1],TAM2-2,stdin);
            disciplina[countd1-1].alunos[countd11-1][strlen(disciplina[countd1-1].alunos[countd11-1])-1]='\0';
            printf("%s\n", disciplina[countd1-1].alunos[countd11-1]);
            if(((disciplina[countd1-1].alunos[countd11-1][0]-'0')>=0 && (disciplina[countd1-1].alunos[countd11-1][0]-'0')<=9) || ((disciplina[countd1-1].alunos[countd11-1][0]-'0')>=-9 && (disciplina[countd1-1].alunos[countd11-1][0]-'0')<=0 ) || (strlen(disciplina[countd1-1].alunos[countd11-1])>TAM3)){
                printf("\nAluno inválido.\n");
            }
            else{
                cont4++;
            }
            printf("Deseja continuar?1- sim 0- não: ");
            scanf("%d", &countd11);
            }
            while(countd11);
            break;}
            case 5:{
            cont5=0;
            printf("Digite o código da disciplina %s (ex: INF.029): ", nome);
            setbuf(stdin,NULL);
            fgets(disciplina[countd1-1].codigo,9,stdin);
            disciplina[countd1-1].codigo[strlen(disciplina[countd1-1].codigo)-1]='\0';
            printf("%s\n", codigo);
            if(disciplina[countd1-1].codigo[3]!='.' || (((disciplina[countd1-1].codigo[0]-'0')>=0 && (disciplina[countd1-1].codigo[0]-'0')<=9) || ((disciplina[countd1-1].codigo[0]-'0')>=-9 && (disciplina[countd1-1].codigo[0]-'0')<=-1))){
                printf("Código inválido\n.");
            }
            cont5++;
            break;}
            case 6:{
            for(t=0;t<TAM2-1;t++){
                disciplina[countd1-1].nome[t]='\0';
            }
            for(t=0;t<TAM3-1;t++){
                disciplina[countd1-1].semestre[t]='\0';
            }
            for(t=0;t<TAM3-1;t++){
                disciplina[countd1-1].professor[t]='\0';
            }
            for(t=0;t<TAM2-1;t++){
                disciplina[countd1-1].alunos[countd11-1][t]='\0';
            }
            for(t=0;t<7;t++){
                disciplina[countd1-1].codigo[t]='\0';
            }
            break;}
            default:
            break;
        }
    }
    while(i);
    if (cont1==0 || cont2==0 || cont3==0 || cont4==0 || cont5==0){
        printf("Não foram cadastrados todos os dados.\n");
    }
}
void Relatorio(struct dados aluno[], struct dados professor[], struct disc disciplina[]){
    int cont=0,i=0,k=0,d=0,c=0,j=0,conter=0,t=0,aux;
    char dia[6],mes[6],string[6];
    do{
    if(cont==0){
        printf("Digite um das opções do menu de relatório:\n1- Listar Alunos\n2- Listar Professores\n3- Listar Disciplinas\n4- Listar uma disciplina\n5- Listar alunos por sexo\n6- Listar alunos ordenados"
        " por nome\n7- Listar alunos ordenados por data de nascimento\n8- Listar professores por sexo\n9- Listar professores ordenados por nome\n10- Listar professores ordenados por data de nascimento\n11- Aniversariante"
        "do mês\n12- Lista de pessoas a partir de uma string de busca\n13- Lista de alunos matriculados em menos de 3 disciplinas\n14- Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas\n"
        "0- Sair do menu\n");
        cont++;
    }
    else{
        printf("Digite uma das opções do menu de relatório: ");
    }
    scanf("%d", &i);
    switch(i){
        case 1:{
            for(k=0;k<TAM;k++){
                printf("Aluno %d: %s\n",k+1, aluno[k].nome);
                }
        break;}
        case 2:{
            for(k=0;k<TAM;k++){
                printf("Professor %d: %s\n",k+1, professor[k].nome);
                }
        break;}
        case 3:{
            for(k=0;k<DISC;k++){
                printf("Nome da disciplina %d: %s\n", k+1, disciplina[k].nome);
                printf("Semestre da disciplina %d: %s\n", k+1, disciplina[k].semestre);
                printf("Professor da disciplina %d: %s\n", k+1, disciplina[k].professor);
                printf("Código da disciplina %d: %s\n", k+1,disciplina[k].codigo);
            }
        break;}
        case 4:{
            printf("Digite qual o disciplina queres listar: ");
            scanf("%d", &d);
            printf("Nome da disciplina %d: %s\n", d+1, disciplina[d].nome);
            printf("Semestre da disciplina %d: %s\n", d+1, disciplina[d].semestre);
            printf("Professor da disciplina %d: %s\n", d+1, disciplina[d].professor);
            for(c=0;c<TAM;c++){
                printf("Aluno %d da disciplina: %s", c+1,disciplina[d].alunos[c]);
            }
            printf("Código da disciplina %d: %s\n", d+1,disciplina[d].codigo);
        break;}
        case 5:{

             for(k=0;k<TAM;k++){
                if(aluno[k].sexo=='m'){
                    printf("Aluno %d- %s é masculino.\n",k+1, aluno[k].nome);
                }
                }
             for(k=0;k<TAM;k++){
                if(aluno[k].sexo=='f'){
                    printf("Aluno %d- %s é feminino.\n",k+1, aluno[k].nome);
                }
                }
             for(k=0;k<TAM;k++){
                if(aluno[k].sexo=='o'){
                    printf("Aluno %d- %s é outro.\n",k+1, aluno[k].nome);
                }
                }
        break;}
        case 6:{
            break;}
        case 7:{
           /* for(k=0;k<TAM;k++){
                if(strlen(aluno[k].dataNascimento)==10){
                    aluno[k].dia=(aluno[k].dataNascimento[0]-'0')*10+(aluno[k].dataNascimento[1]-'0');
                    aluno[k].mes=(aluno[k].dataNascimento[3]-'0')*10+(aluno[k].dataNascimento[4]-'0');
                    aluno[k].ano=(aluno[k].dataNascimento[6]-'0')*1000+((aluno[k].dataNascimento[7]-'0')*100)+((aluno[k].dataNascimento[8]-'0')*10)+(aluno[k].dataNascimento[9]-'0');
                    aluno[k].data=aluno[k].dia+aluno[k].mes+aluno[k].ano;
                    printf("%d\n", aluno[k].data);
                    }
                }
            for(k=0;k<TAM;k++){
                for(j=0;j<TAM-1;j++){
                }
            }*/
            break;}
        case 8:{
             for(k=0;k<TAM;k++){
                if(professor[k].sexo=='m'){
                    printf("Professor %d- %s é masculino.\n",k+1, professor[k].nome);
                }
                }
             for(k=0;k<TAM;k++){
                if(professor[k].sexo=='f'){
                    printf("Professor %d- %s é feminino.\n",k+1, professor[k].nome);
                }
                }
             for(k=0;k<TAM;k++){
                if(professor[k].sexo=='o'){
                    printf("Professor %d- %s é outro.\n",k+1, professor[k].nome);
                }
                }
            break;}
        case 9:{
            printf(" Em desenvolvimento\n");
            break;}
        case 10:{
            printf(" Em desenvolvimento\n");
            break;}
        case 11:{
            printf("Digite o dia de nascimento: ");
            setbuf(stdin,NULL);
            fgets(dia,4,stdin);
            printf("Digite o mes de nascimento: ");
            setbuf(stdin,NULL);
            fgets(mes,4,stdin);
            for(k=0;k<TAM;k++){
                if(dia[0]==aluno[k].dataNascimento[0] && dia[1]==aluno[k].dataNascimento[1] && mes[0]==aluno[k].dataNascimento[3] && mes[1]==aluno[k].dataNascimento[4]){
                    printf("Aluno %d- %s é aniversariante.\n", k+1,aluno[k].nome);
                }
            }
            for(k=0;k<TAM;k++){
                if(dia[0]==professor[k].dataNascimento[0] && dia[1]==professor[k].dataNascimento[1] && mes[0]==professor[k].dataNascimento[3] && mes[1]==professor[k].dataNascimento[4]){
                    printf("Professor %d- %s é aniversariante.\n", k+1,professor[k].nome);
                }
            }
            break;}
        case 12:{
            printf("Digite 3 letras para buscar pessoas com as 3 letras :");
            setbuf(stdin,NULL);
            fgets(string,5,stdin);
            string[strlen(string)-1]='\0';
            for(k=0;k<TAM;k++){
                conter=0;
                for(j=0;j<TAM2;j++){
                     if(aluno[k].nome[j]==string[0] || aluno[k].nome[j]==string[1] || aluno[k].nome[j]==string[2]){
                        conter++;
                     }
                     if(conter==3){
                        printf("Aluno %d- %s possui as 3 letras.\n",k+1, aluno[k].nome);
                     }
                    }
                }

            break;}
        case 13:{
            for(k=0;k<TAM;k++){
                conter=0;
                for(j=0;j<DISC;j++){
                    if(strlen(aluno[k].nome)>1){
                        if(j==DISC-1){
                            if(conter<3){
                                printf("Aluno %d- %s está matriculado em menos de 3 disciplinas.\n",k+1,aluno[k].nome);
                            }
                        }
                    }
                    for(t=0;t<TAM;t++){
                        if(strlen(disciplina[j].alunos[t])>1 && strlen(aluno[k].nome)>1){
                            if(strcmp(disciplina[j].alunos[t],aluno[k].nome)==0){
                                conter++;
                            }
                         }
                     }
                    }
                }
        break;}
        case 14:{
            printf("Se n printou nada eh pq n existem disciplinas com mais de 40 alunos.\n");
            conter=0;
            for(k=0;k<TAM;k++){
                for(j=0;j<TAM;j++){
                    if(strlen(disciplina[k].alunos[j])>1)
                        conter++;
                    }
                    if(strlen(disciplina[k].nome)>1){
                        if(j=(TAM-1)){
                            if(conter>40){
                                printf("Disciplina %d- %s do professor %s extrapola 40 alunos.\n", k+1, disciplina[k].nome, disciplina[k].professor);
                            }
                        }
                    }
                }
            break;}
    }
    }
    while(i);
}
