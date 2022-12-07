#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define MAX_FILE_NAME 100


//FUNÇÃO LOGIN __________________________________________________________________________________
login(){
   setlocale(LC_ALL, "");
   inicio:
     system("cls");

     system("mode con:cols=80 lines=30");

     char user[4], senha[4], s, u;

     printf("\n\n\n\n\n\n\n\t\t\t\t______LOGIN______"
            "\n\n\t\t\t\tUSUARIO: ");
     scanf("%s", &user);
     printf("\n\t\t\t\tSENHA: ");

     scanf("%s", &senha);

     u = strcmp(user, "admin" );
     s = strcmp(senha, "12345");

     if(u && s == 0){

            system("color 0f");
            return 0;

            }

     else{

            system("color 4f");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tUSUARIO OU SENHA INCORRETO");
            Sleep(1000);
            goto inicio;
     }

}

//FUNÇÃO CADASTRO _______________________________________________________________________________
cadastroDeClientes(){
   setlocale(LC_ALL, "");
   system("cls");
    FILE *file;
    char nome[50],sobrenome[100], cpf[12], cell[20], email[100], cep[20];
    int op;
    cadastro:
    printf("\n\n\t\t__________________CADASTRAR__________________\n");
       //NOME

        printf("\n\n\t\t\tNOME: ");
        fflush(stdin);
        scanf("%s", &nome);
        file = fopen(nome, "a+");
        fprintf(file,"\n\n\tNOME: \t");
        fprintf(file, nome);


        //CPF

        printf("\n\t\t\tCPF: ");
        fflush(stdin);
        scanf("%s", &cpf);
        fprintf(file,"\n\tCPF: \t");
        fprintf(file, cpf);

        //TELEFONE

        printf("\n\t\t\tTELEFONE: ");
        fflush(stdin);
        scanf("%s", &cell);
        fprintf(file,"\n\tTELEFONE: ");
        fprintf(file, cell);

        //EMAIL

        printf("\n\t\t\tEMAIL: ");
        fflush(stdin);
        scanf("%s", &email);
        fprintf(file,"\n\tEMAIL: \t");
        fprintf(file, email);

        //CEP

        printf("\n\t\t\tCEP:");
        fflush(stdin);
        scanf("%s", &cep);
        fprintf(file,"\n\tCEP: \t");
        fprintf(file, cep);
        fclose(file);

        printf("\n\n\t\t\t____________________________________\n"
        "\n\t\tDIGITE 1 PARA CADASTRAR NOVAMENTE OU 2 PARA VOLTAR ");
        scanf("%i", &op);
         switch(op){

            case 1: system ("cls");goto cadastro; break;
            default: fclose(file);
                     return 0;; break; }
}

//FUNÇÃO BUSCA __________________________________________________________________________________
buscaCliente(){
        setlocale(LC_ALL, "");
        busca:
        system("mode con:cols=80 lines=200");
        system("cls");
        FILE *file;
        char procurar[100], f[100];


        printf("\n\n\t\t__________________BUSCA__________________"
        "\n\n\t\tCADASTRO - PROCURAR PELO PRIMEIRO NOME "
        "\n\t\t_________________________________________");


        printf("\n\n\t\t\tBUSCA: ");
        scanf("%s", &procurar);
        file = fopen(procurar, "rb");


        //LEITURA DO ARQUIVO

        int opbusca;

        if (file == NULL){

        printf("\n\n               NÃO ENCONTRADO");


    }
        while(fgets(f, 100, file) != NULL){

        printf("\t\t%s", f);

    }
        printf("\n\n\t\t____________________________________"
        "\n\n\t\tDIGITE 1 PARA NOVA BUSCA OU 2 PARA VOLTAR ");
        scanf("%i", &opbusca);
         switch(opbusca){

            case 1: goto busca; break;
            default: fclose(file);
                     return 0;; break; }
}

//FUNÇÃO FEEDBACK __________________________________________________________________________________
feedback(){
        setlocale(LC_ALL, "");
    system("cls");
    char nm[100], dia[100], genero[100], ava[100],nshow[100];
    FILE *p;
    printf("\n\n\t\t__________________FEEDBACK__________________"
    "\n\n\t\t\t[1] - MUITO BOM \n\t\t\t[2] - BOM \n\t\t\t[3] - REGULAR \n\t\t\t[4] - RUIM \n\t\t\t[5] - PESSIMO "
    "\n\t\t____________________________________________"
    "\n\n\t\t\tAVALIAÇÃO: ");
    scanf("%s", &ava);

        p = fopen(ava, "a+b");
        printf("\n\t\t\tNOME DO CLIENTE: ");
        fflush(stdin);
        scanf("%s", &nm);

        printf("\n\t\t\tDIA: ");
        fflush(stdin);
        scanf("%s", &dia);

        printf("\n\t\t\tCANTOR: ");
        fflush(stdin);
        scanf("%s", &nshow);

        printf("\n\t\t\tGENERO DO SHOW: ");
        fflush(stdin);
        scanf("%s", &genero);


        fprintf(p,"\n____________________________________________");
        fprintf(p,"\n\tAVALIAÇÃO: ");
        fprintf(p,ava);
        fprintf(p,"\n\tNOME DO CLIENTE: ");
        fprintf(p, nm);
        fprintf(p,"\n\tDIA: ");
        fprintf(p,dia);
        fprintf(p,"\n\tCANTOR: ");
        fprintf(p,"%s",nshow);
        fprintf(p,"\n\tGÊNERO: ");
        fprintf(p,genero);

      fclose(p);
      return 0;
}

//FUNÇÃO DE CADASTRO DE FUNCIONARIO _
cadastrarFuncionarios(){
   setlocale(LC_ALL, "");
    system("cls");
    char fun    [100], dat[100], sal[100], nm[100], cpf[100];
    FILE *fFuncionarios;

    fFuncionarios=fopen("Funcionarios.txt","a+b");
    printf("\n\n\t\t__________________FUNCIONARIOS__________________");
    printf("\n\n\t\t\tNOME: ");
    scanf("%s", &nm);
    printf("\n\t\t\tFUNÇÃO: ");
    scanf("%s",&fun);
    printf("\n\t\t\tDATA DE INICIO: ");
    scanf("%s", &dat);
    printf("\n\t\t\tSALARIO: ");
    scanf("%s", &sal);
    printf("\n\t\t\tCPF: ");
    scanf("%s", &cpf);

    fprintf(fFuncionarios,"\n    NOME: ");
    fprintf(fFuncionarios, nm);
    fprintf(fFuncionarios,"\n    FUNÇÃO: ");
    fprintf(fFuncionarios, fun);
    fprintf(fFuncionarios,"\n    DATA DE INICIO: ");
    fprintf(fFuncionarios, dat);
    fprintf(fFuncionarios,"\n    SALARIO: ");
    fprintf(fFuncionarios, sal);
    fprintf(fFuncionarios,"\n    CPF: ");
    fprintf(fFuncionarios, cpf);

    fprintf(fFuncionarios, "\n");
    fprintf(fFuncionarios,"\n_______________________\n");
    fclose(fFuncionarios);
    return 0;
}

//FUNÇÃO BUSCA FUNCIONARIO
buscaFuncionario(){
        setlocale(LC_ALL, "");
        busca:
        system("mode con:cols=80 lines=200");
        system("cls");
        FILE *file;
        char procurar[100], f[100];


        printf("\n\n\t\t__________________BUSCA__________________"
        "\n\t\t  FUNCIONARIOS REGISTRADOS PELA EMPRESA "
        "\n\t\t_________________________________________");

        printf("\n\n\t\t\tFUNCIONARIOS DA EMPRESA: "
        "\n\t\t_________________________________________");
        file = fopen("Funcionarios.txt", "r+b");

        //LEITURA DO ARQUIVO

        int opbusca;

        if (file == NULL){

        printf("\n\n               NÃO ENCONTRADO");


    }
        while(fgets(f, 100, file) != NULL){

        printf("\t\t%s", f);

    }
        printf("\n\n\t\t_________________________________________"
        "\n\n               DIGITE 1 PARA NOVA BUSCA OU 2 PARA VOLTAR ");

        scanf("%i", &opbusca);

        switch(opbusca){

            case 1: goto busca; break;
            default: fclose(file);
                     return 0; break;
         }
}

//FUNÇÃO EXCLUIR __________________________________________________________________________________
excluir(){
      setlocale(LC_ALL, "");
      system("cls");
      int del;
      FILE *fp;
      char nome[100];
        printf("\n\n\t\t__________________EXCLUIR DADOS__________________"
        "\n\n\t\t\tDIGITE O NOME PARA DELETAR"
        "\n\n\t\t\tDIGITE PARA DELETAR: ");
        scanf("%s", &nome);

      fp = fopen(nome, "w");

      fprintf(fp, "%s", " ");
      fclose(fp);

      del = remove(nome);

      if(del == NULL) { printf("\n\t\t\tDADOS DELETADOS COM SUCESSO");}
       else { printf("\n\t\t\tERRO, DADOS NAO EXISTENTE"); }

      int opdel;
       printf("\n\n\t\t_________________________________________________"
              "\n\n\t\t\tDIGITE 1 PARA VOLTAR: ");

       scanf(" %c", &opdel);
        switch(opdel){
           case 1: return 0; break;
           default: return 0; break; }
}

//CADASTRO DE SHOWS
cadastroDeShows(){
   setlocale(LC_ALL, "");
   system("cls");
    FILE *p;
    char titulo[20], dia[100], horario[100], mes[100], Cidade[50], Estado[20], Cantor[100];
    float preco;
    int op;

    cadastrarShow:

    printf("\n\n\t\t__________________CADASTRAR__________________\n");
       //MÊS
        printf("\n\t\t\tMÊS: ");
        scanf("%s", &mes);

        p = fopen(mes, "ab");
        printf("\n\t\t\tTITULO: ");
        fflush(stdin);
        scanf("%s", &titulo);
        fprintf(p,"\n\tTITULO: \t");
        fprintf(p, titulo);

        //DIA

        printf("\n\t\t\tDIA: ");
        fflush(stdin);
        scanf("%s", &dia);
        fprintf(p,"\n\tDIA: \t");
        fprintf(p, dia);

        //HORÁRIO

        printf("\n\t\t\tHORARIO: ");
        fflush(stdin);
        scanf("%s", &horario);
        fprintf(p,"\n\tHORARIO: \t");
        fprintf(p, horario);

        //CIDADE

        printf("\n\t\t\tCIDADE: ");
        fflush(stdin);
        scanf("%s", &Cidade);
        fprintf(p,"\n\tCIDADE: ");
        fprintf(p, Cidade);

        //ESTADO

        printf("\n\t\t\tESTADO(SIGLA): ");
        fflush(stdin);
        scanf("%s", &Estado);
        fprintf(p,"\n\tESTADO: \t");
        fprintf(p, Estado);

        //CANTOR

        printf("\n\t\t\tCANTOR(a): ");
        fflush(stdin);
        scanf("%s", &Cantor);
        fprintf(p,"\n\tCANTOR(a): \t");
        fprintf(p, Cantor);

        //PREÇO

        printf("\n\t\t\tVALOR DO INGRESSO: ");
        fflush(stdin);
        scanf("%f", &preco);
        fprintf(p,"\n\tVALOR DO INGRESSO: R$\t");
        fprintf(p,"%0.2f", preco);
        fprintf(p,"\n_____________________________________________");
        printf("\n\n\t\t_____________________________________________"
        "\n\t      DIGITE 1 PARA CADASTRAR NOVAMENTE OU 2 PARA VOLTAR ");
        scanf("%i", &op);
         switch(op){

            case 1:
                    system("cls");
                    goto cadastrarShow;
                    break;
            default:
                fclose(p);
                return 0;; break; }
}

//BUSCA DOS SHOWS
buscarshows(){
        setlocale(LC_ALL, "");
        buscashows:
        system("mode con:cols=80 lines=200");
        system("cls");
        FILE *file;
        char procurar[100], f[100];


        printf("\n\n\t\t__________________BUSCA__________________");
        printf("\n\n\n\t\t\tDIGITE O MÊS DO SHOW");
        printf("\n\n\t\t_________________________________________");


        printf("\n\n\t\t\tBUSCA: ");
        scanf("%s", &procurar);
        file = fopen(procurar, "rb");


        //LEITURA DO ARQUIVO

        int opbusca;

        if (file == NULL){

        printf("\n\n               NÃO ENCONTRADO");


    }
        while(fgets(f, 100, file) != NULL){

        printf("\t\t%s", f);

    }
        printf("\n\n________________________________________"
        "\n\t\tDIGITE 1 PARA NOVA BUSCA OU 2 PARA VOLTAR ");
        scanf("%i", &opbusca);
         switch(opbusca){

            case 1: goto buscashows; break;
            default: fclose(file);
                     return 0;; break; }
}

//FUNÇÃO COMPRAR INGRESSO __________________________________________________________________________________
comprarIngresso(){
    setlocale(LC_ALL, "");
    loop:
    system("cls");
    char f[100];
    float val;
    int op,opbusca;
    FILE *file;

    FILE *entrada;

    FILE *valores;


    printf("\n\n__________________COMPRAR INGRESSO__________________"
    "\n\n                                 [1]-JANEIRO"
    "\n                                 [2]-FEVEREIRO"
    "\n                                 [3]-MARÇO"
    "\n                                 [4]-ABRIL"
    "\n                                 [5]-MAIO"
    "\n                                 [6]-JUNHO"
    "\n                                 [7]-JULHO"
    "\n                                 [8]-AGOSTO"
    "\n                                 [9]-SETEMBRO"
    "\n                                 [10]-OUTUBRO"
    "\n                                 [11]-NOVEMBRO"
    "\n                                 [12]-DEZEMBRO"
    "\n                                 [0]-VOLTAR"
    "\n____________________________________________________"
    "\n\n\t\t\tMES: ");
    fflush(stdin);
    scanf("%i", &op);

    switch(op){
    case 1:entrada = fopen("jan.dat", "ab");
            system("cls");
            file=fopen("Janeiro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE JANEIRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 2: entrada = fopen("fev.dat", "ab");
            system("cls");
            file=fopen("Fevereiro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE FEVEREIRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 3: entrada = fopen("mar.dat", "ab");
            system("cls");
            file=fopen("Marco","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE MARCO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 4: entrada = fopen("abr.dat", "ab");
            system("cls");
            file=fopen("Abril","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE ABRIL:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 5: entrada = fopen("mai.dat", "ab");
            system("cls");
            file=fopen("Maio","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE MAIO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 6: entrada = fopen("jun.dat", "ab");
            system("cls");
            file=fopen("Junho","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE JUNHO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 7: entrada = fopen("jul.dat", "ab");
            system("cls");
            file=fopen("Julho","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE JULHO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 8: entrada = fopen("ago.dat", "ab");
            system("cls");
            file=fopen("Agosto","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE AGOSTO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 9: entrada = fopen("set.dat", "ab");
            system("cls");
            file=fopen("Setembro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE SETEMBRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 10: entrada = fopen("out.dat", "ab");
            system("cls");
            file=fopen("Outubro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE OUTUBRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 11: entrada = fopen("nov.dat", "ab");
            system("cls");
            file=fopen("Novembro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE NOVEMBRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;

    case 12: entrada = fopen("dez.dat", "ab");
            system("cls");
            file=fopen("Dezembro","rb");

            printf("\n\n\t\t-----------------SHOWS NO MÊS DE DEZEMBRO:-----------------");

            if (entrada== NULL){

            printf("\n\n\t\t\tNÃO ENCONTRADO");

            }

            while(fgets(f, 200, file) != NULL){


                printf("\t\t\t%s", f);

            }
            fclose(file);
            break;
    case 0:
            return 0;; break;

        default: printf("\n                                OPCAO INVALIDA");goto loop;break;}

        valores=fopen("valores","a");

        printf("\n\n\n\t\tDIGITE O VALOR DO INGRESSO QUE SERÁ COMPRADO: ");
        scanf("%s", &val);

        fprintf(entrada,&val);
        fprintf(entrada, "\n");

        fprintf(valores,&val);
        fprintf(valores, "\n");

        fclose(entrada);
        fclose(file);
        fclose(valores);

        system("cls");
        system("color A0");
        printf("\n\n\t\t____________________________________________________");
        printf("\n\n\n\t\t\tINGRESSO COMPRADO COM SUCESSO! ");
        Sleep(1000);
        system("color 0f");
        return 0;

}

//RELATORIO SHOWS
relatoriosNDeShows(){

    setlocale(LC_ALL, "");
    system("cls");
    int op;
    int numShows;
    int comecouPalavra = 0, numPalavras = 0, numLinhas = 0, numCaracteres = 0;
    FILE *file;
    FILE *rel;

    char arquivo[100];
    char caracter;
    relatorios:
        system("cls");
    printf("\n\t\t__________________RELATÓRIO__________________");
    printf("\n\n\t\t  DIGITE O MÊS QUE DEVE SER ANALISADO: ");
    fflush(stdin);
    gets(arquivo);

    rel = fopen("RelatorioShows.txt","a+");
    file = fopen(arquivo, "r+b");

    if(file==NULL){
            system("cls");
            printf("\n\n\n\n\n\t\t\tARQUIVO NÃO ENCONTRADO");
            Sleep(1000);
            return 0;


            }else{
    while (!feof(file)) {
          fread(&caracter, 1, 1, file);
          numCaracteres++;
          if  ((caracter!=' ') && (caracter!='\n') && (!comecouPalavra)) {
             comecouPalavra = 1;
          }
          if  (((caracter==' ') || (caracter == '\n')) && (comecouPalavra)) {
             comecouPalavra = 0;
             numPalavras++;
          }
          if (caracter=='\n') {
             numLinhas++;
             }

   }
        numShows=numLinhas/7;


        printf("\n\t\t\tO NUMERO DE SHOWS EM %s É: %d",arquivo,numShows);
        printf("\n\n\t\t_____________________________________________");
        fprintf(rel,"\n_____________________________________________________");
        fprintf(rel,"\n\t\t\t\%s\t\t\t",arquivo);
        fprintf(rel,"\n_____________________________________________________");
        fprintf(rel,"\n\n\tNúmero de Shows:\t\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

}}

//FUNÇÃO FATURAMENTO MENSAL __________________________________________________________________________________
faturamentoMensal(){

  setlocale(LC_ALL, "");
  system("cls");
  char op;
   FILE *fat;
   FILE *rel;

   printf("\n\n\t\t__________________FATURAMENTO__________________"
   "\n\n\t\t\t[1]-JANEIRO"
    "\n\t\t\t[2]-FEVEREIRO"
    "\n\t\t\t[3]-MARÇO"
    "\n\t\t\t[4]-ABRIL"
    "\n\t\t\t[5]-MAIO"
    "\n\t\t\t[6]-JUNHO"
    "\n\t\t\t[7]-JULHO"
    "\n\t\t\t[8]-AGOSTO"
    "\n\t\t\t[9]-SETEMBRO"
    "\n\t\t\t[10]-OUTUBRO"
    "\n\t\t\t[11]-NOVEMBRO"
    "\n\t\t\t[12]-DEZEMBRO"
    "\n\t\t\t[0]-VOLTAR"
    "\n\t\t_______________________________________________"
    "\n\n\t\t\tMES: ");
    scanf("%d", &op);
    switch(op){
    case 0: return 0;
    case 1: fat = fopen("jan.dat", "r");break;
    case 2: fat = fopen("fev.dat", "rb");break;
    case 3: fat = fopen("mar.dat", "rb");break;
    case 4: fat = fopen("abr.dat", "rb");break;
    case 5: fat = fopen("mai.dat", "rb");break;
    case 6: fat = fopen("jun.dat", "rb");break;
    case 7: fat = fopen("jul.dat", "rb");break;
    case 8: fat = fopen("ago.dat", "rb");break;
    case 9: fat = fopen("set.dat", "rb");break;
    case 10: fat = fopen("out.dat", "rb");break;
    case 11: fat = fopen("nov.dat", "rb");break;
    case 12: fat = fopen("dez.dat", "rb");break;
    default: printf("\n\t\t\tOPÇÃO INVALIDA");return 0;break;}

    if (fat == NULL) {
        system("cls");
        printf ("\n\n\n\n\t\t\tARQUIVO NÃO ENCONTRADO!\n");
        Sleep(1000);
        return 0;
    }
    float soma = 0;
    while (!feof( stdin )) {
        int x;

        if (fscanf (fat, "%i", &x) != 1) break;
        soma += x;
    }
    system("cls");
    printf ("\n\n\n\t\tO FATURAMENTO DO MES REFERENTE FOI DE R$ %.2f\n", soma);


        rel = fopen("RelatorioShows.txt","a+b");
        fprintf(rel,"\n\n\tFaturamento:\t\t R$ %.2f",soma);
        fprintf(rel,"\n_____________________________________________________");
        fclose(rel);
                fclose (fat);
        Sleep(3000);
        return 0;

}

//FUNÇÃO FATURAMENTO TOTAL__________________________________________________________________________________
faturamentoTotal(){
    setlocale(LC_ALL, "");
    system("cls");
    int op;
    FILE *fatTotal;
    printf("\n\n\t\t__________________FATURAMENTO TOTAL__________________\n\n");

    fatTotal = fopen("valores", "rb");

    if (fatTotal == NULL) {
      printf ("\n\t\t\tARQUIVO NÃO ENCONTRADO!\n");
      Sleep(1000);
      return 0;
    }
    float soma = 0;
    while (!feof( stdin )) {
    int x;

    if (fscanf (fatTotal, "%i", &x) != 1) break;
    soma += x;
    }
    fclose (fatTotal);
    printf ("\n\t\t\tO FATURAMENTO TOTAL FOI DE R$ %.2f\n", soma);
    fprintf(fatTotal,"FATURAMENTO TOTAL DE R$ %.2f\n", soma);
    Sleep(2000);
    return 0;

}

//FUNÇÃO FEEDBACKS
relatorioFeedbacks(){
    setlocale(LC_ALL, "");
    system("cls");
    int op;
    int numShows;
    int comecouPalavra = 0, numPalavras = 0, numLinhas = 0, numCaracteres = 0;
    FILE *file;
    FILE *rel;

    char arquivo[100];
    char caracter;

    relatorios:
        system("cls");
    printf("\t        __________________RELATÓRIO DE FEEDBACKS__________________");
    printf("\n\n\t\t\tDIGITE O QUAL AVALIAÇÃO QUER ANALISAR:"
    "\n\t\t__________________________________________________________"
    "\n\n\t\t\t[1]-MUITO BOM"
    "\n\t\t\t[2]-BOM"
    "\n\t\t\t[3]-REGULAR"
    "\n\t\t\t[4]-RUIM"
    "\n\t\t\t[5]-MUITO RUIM"
    "\n\t\t\t[0]-VOLTAR"
    "\n\t\t__________________________________________________________\n\n");
    fflush(stdin);
    gets(arquivo);

    rel = fopen("RelatorioShows.txt","a+");
    file = fopen(arquivo, "r+");

    if(atoi(arquivo)==0){
            return 0;}

            else{
            if(file==NULL){
            system("cls");
            printf("\n\n\n\n\n\t\t\tARQUIVO NÃO ENCONTRADO");
            Sleep(1000);
            goto relatorios;


            }else{
    while (!feof(file)) {
          fread(&caracter, 1, 1, file);
          numCaracteres++;
          if  ((caracter!=' ') && (caracter!='\n') && (!comecouPalavra)) {
             comecouPalavra = 1;
          }
          if  (((caracter==' ') || (caracter == '\n')) && (comecouPalavra)) {
             comecouPalavra = 0;
             numPalavras++;
          }
          if (caracter=='\n') {
             numLinhas++;
             }

   }
        numShows=numLinhas/6;

        switch(atoi(arquivo)){

        case 1:

        system("cls");

        printf("\n\t\tNÚMERO DE AVALIAÇÕES EM MUITO BOM NO ANO: %d",numShows);
        fprintf(rel,"\n\n\tAvaliações em Muito Bom:\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

        case 2:

        system("cls");

        printf("\n\t\tNÚMERO DE AVALIAÇÕES EM BOM NO ANO: %d",numShows);
        fprintf(rel,"\n\n\tAvaliações em Bom:\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

        case 3:

        system("cls");

        printf("\n\t\tNÚMERO DE AVALIAÇÕES EM REGULAR NO ANO: %d",numShows);
        fprintf(rel,"\n\n\tAvaliações em Regular:\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

        case 4:

        system("cls");

        printf("\n\t\tNÚMERO DE AVALIAÇÕES EM RUIM NO ANO: %d",numShows);
        fprintf(rel,"\n\n\tAvaliações em Ruim:\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

        case 5:

        system("cls");

        printf("\n\t\tNÚMERO DE AVALIAÇÕES EM MUITO RUIM NO ANO: %d",numShows);
        fprintf(rel,"\n\n\tAvaliações em Muito Ruim:\t%d",numShows);
        fprintf(rel,"\n_____________________________________________________");
        fclose(arquivo);
        fclose(rel);
        Sleep(1000);
        return 0;

        }
}}}



int main(){
    setlocale(LC_ALL, "");
inicio:
   if (login() == 0){ goto menu; }

//MENU PRINCIPAL__________________________________________________________________________________
menu:
    system("mode con:cols=80 lines=30");
    system("cls");
    int menuop;
    printf("\n\n\n\n\n\t\t__________________MENU__________________ "
    "\n\n\t\t\t[1]-CLIENTES"
    "\n\t\t\t[2]-SHOWS"
    "\n\t\t\t[3]-FUNCIONARIOS"
    "\n\t\t\t[4]-RELATORIOS"
    "\n\t\t\t[0]-SAIR"
    "\n\t\t________________________________________"
    "\n\n\t\t\tDIGITE UMA OPÇÃO: ");
    scanf("%i", &menuop);
    switch(menuop){

        case 0: goto inicio;
        case 1: goto submenu; break;
        case 2: goto subagen; break;
        case 3: goto submenuFun;break;
        case 4: goto subrela; break;
        default: goto menu;}

//SUBMENU CLIENTES __________________________________________________________________________________
submenu:
    system("mode con:cols=80 lines=30");
    system("cls");
    int opcad;
    printf("\n\n\n\n\n\t\t__________________CLIENTES__________________"
    "\n\n\t\t\t[1]-CADASTRAR CLIENTES"
    "\n\t\t\t[2]-BUSCAR CLIENTES"
    "\n\t\t\t[3]-EXCLUIR CADASTRO"
    "\n\t\t\t[4]-FEEDBACK DOS SHOWS"
    "\n\t\t\t[0]-VOLTAR"
    "\n\t\t____________________________________________"
    "\n\n\t\t\tDIGITE UMA OPÇÃO: ");
    scanf("%i", &opcad);
    switch(opcad){
        case 0: goto menu; break;

        case 1: if (cadastroDeClientes() == 0){
                goto submenu; };
                break;

        case 2: if (buscaCliente() == 0){
                goto submenu; };
                break;

        case 3: if (excluir() == 0){
                goto submenu; };
                break;;

        case 4:if   (feedback()==0){
            goto submenu;
        }
        default: printf("\n                            INVALIDO");
                goto submenu; break; }
//SUBMENU FUNCIONARIOS __________________________________________________________________________________
submenuFun:
    system("mode con:cols=80 lines=30");
    system("cls");
    int opcadFun;
    printf("\n\n\n\n\n\t\t__________________FUNCIONARIOS__________________"
    "\n\n\t\t\t[1]-CADASTRAR FUNCIONARIO"
    "\n\t\t\t[2]-BUSCAR FUNCIONARIOS"
    "\n\t\t\t[3]-EXCLUIR FUNCIONARIOS"
    "\n\t\t\t[0]-VOLTAR"
    "\n\t\t________________________________________________"
    "\n\n\t\t\tDIGITE UMA OPÇÃO: ");
    scanf("%i", &opcadFun);
    switch(opcadFun){
        case 0: goto menu; break;

        case 1: if (cadastrarFuncionarios() == 0){
                goto submenuFun; };
                break;

        case 2: if (buscaFuncionario() == 0){
                goto submenuFun; };
                break;
        case 3: if (excluir() == 0){
                goto submenuFun; };
                break;
        default: printf("\n                            INVALIDO");
                goto submenuFun; break; }
//SUBMENU SHOWS __________________________________________________________________________________
subagen:
    system("mode con:cols=80 lines=30");
    system("cls");
    int opagen;
    printf("\n\n\n\n\n\t\t__________________SHOWS__________________"
    "\n\n\t\t\t[1]-CADASTRAR SHOWS"
    "\n\t\t\t[2]-LISTAR SHOWS"
    "\n\t\t\t[3]-COMPRAR INGRESSOS"
    "\n\t\t\t[0]-VOLTAR"
    "\n_________________________________________"
    "\n\n\t\t\tDIGITE UMA OPÇÃO: ");
    scanf("%i", &opagen);
     switch(opagen){
        case 1: if (cadastroDeShows() == 0){
                goto subagen;}
                break;
        case 2: if (buscarshows() == 0){
                goto subagen; };
                break;
        case 3: if (comprarIngresso() == 0){
                goto subagen; };
                break;
        case 0: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subagen; break; }

//SUBMENU RELATORIOS __________________________________________________________________________________
subrela:
    system("mode con:cols=80 lines=30");
    system("cls");
    int oprela;
    printf("\n\n\n\n\n\t\t__________________RELATÓRIO__________________"
    "\n\n\t\t\t[1]-QUANTIA DE SHOWS P/ MÊS"
    "\n\t\t\t[2]-FATURAMENTO P/ MÊS"
    "\n\t\t\t[3]-TOTAL DE GANHO NO ANO"
    "\n\t\t\t[4]-FEEDBACKS"
    "\n\t\t\t[0]-VOLTAR"
    "\n\t\t_____________________________________________"
    "\n\n\t\t\tDIGITE UMA OPÇÃO: ");
    scanf("%i", &oprela);
     switch(oprela){
        case 1: if (relatoriosNDeShows() == 0){
                goto subrela; };
                break;
        case 2: if (faturamentoMensal() == 0){
                goto subrela; };
                break;
        case 3: if (faturamentoTotal() == 0){
                goto subrela; };
                break;;
        case 4: if (relatorioFeedbacks() == 0){
                goto subrela; };
                break;;
        case 0: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subrela; break; }
}

