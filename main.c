#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define tamanhoVetor 20
#include <windows.h>
#define LINHA 200
#define MAX 130

//VARIAVEL RANGER//
int CAD[40][40];
char usuario[99], senha[99], usuario_cadastrado[99]="adm", senha_cadastrada[99]="1234";

int  opcao, tipo;
char pizza[6][10];
float valor_pizza[6];
char relatorio[20];
char data[10];
char date[0];
float ganho;
float perda;
float calculo;
int a;
int b;
int i;
//FIM VARIAVEL RANGER//
//VARIAVEL ANDERSON//
char nao[5][99]= {"n","N","nao","NAO","Nao"};
char sim[5][99]= {"s","S","sim","SIM","Sim"};
char positivo[200][99];
char mediano[200][99];
char negativo[200][99];
int  i, opcao_menu, atendimento,quali_pizza, quantidade=0, opiniao=0, opiniao_geral=0;
int quant_positivo=1, quant_mediano=1, quant_negativo=1, estrelas;
float soma=0, novo_valor, lucro=0, feedback=0;
char sabores[99], opcao1[99], opcao2[99], opcao3[99], edit_preco[99], comentario[99];
//FIM VARIAVEL ANDERSON//
//VARIAVEL Gabriel//
char nome_da_bebida [20][tamanhoVetor];
int indent [tamanhoVetor];
float valor_bebida [tamanhoVetor];
int op;
int produto;
float novo_valor;
//FIM VARIAVEL Gabriel//
//VARIAVEL RENATO//
char nome_cliente[LINHA][60];
char email[LINHA][60];
char endereco[LINHA][90];
int numresidencia[LINHA];
int rg[LINHA];
int cep[LINHA];
int telefone[LINHA];
int op;
void cadastro();
void pesquisar_cliente();
void listar_clientes();

// FIM VARIAVEL RENATO//
//VARIAVEL GIOVANA//
/* Estrutra para armazenar a ficha do funcionario*/
int opcao;
int seguir;

struct cadastro
{
    int cod; /* C�digo do funcionario*/
    char nome_do_funcionario[50]; /* Nome do funcionario*/
    float salario; /* Salario do funcionario*/
    char cargo[30]; /* Cargo do funcionario*/
    int idade; /* idade do funcionario*/
    char sexo[2]; /* Sexo do funcionario (M)- Masculino e (F)- Feminino*/
};

struct cadastro funcionario[MAX];
int posi;/*Posi��o , Inicio */
//FIM VARIAVEL GIOVANA//

//VARIAVEL ANDERSON//
int i=1;
int g=1;
int opcao;
int cadastrar;
char ingredientes [10] [20];
float kg [10] ;
int  pizzas, pizzas1;
int n_pizza;
char ingredientes_calabresa [6] [20];
float kg_calabresa [6];
char ingredientes_mussarela [6] [20];
float kg_mussarela [6];
//FIM VARIAVEL ANDERSON//
void Menu_Principal()
{
    printf("_____________________________________________");
    printf("\n\n-------PIZZARIA ADS-------");
    printf("\n\n");
    printf("1-MENU PARA CADASTRAR SABORES E RELAT�RIOS DI�RIOS\n");
    printf("2-MENU PARA EDITAR PRE�O E FAZER PEDIDOS\n");
    printf("3-MENU PARA CADASTRO DE BEBIDAS\n");
    printf("4-MENU PARA CADASTRO DE CLIENTES\n");
    printf("5-MENU PARA CADASTRO DE FUNCION�RIOS\n");
    printf("6-MENU PARA CADASTRO DE MAT�RIA PRIMA\n");
    printf("_____________________________________________");
    printf("\n\n");
    printf("Comando: ");
    scanf("%d", &opcao);
    system("cls");
    printf("\n\n");

    switch(opcao)
    {
    case 1:
        menu_cadastrar_sabores_e_relatorios_diarios();
        break;
    case 2:
        Menu_de_editar_preco_e_fazer_pedido();
        break;
    case 3:
        Menu_Cadastro_de_bebida();
        break;
    case 4:
        Menu_cadastro_de_cliente();
        break;
    case 5:
        Menu_de_cadastro_de_funcionarios();
        break;
    case 6:
        Menu_Cadastro_de_materia_prima();
        break;




    }
}

//FUN��ES RANGER//
void menu_cadastrar_sabores_e_relatorios_diarios()
{
    for(a=0; a<30; a++)
    {
        for(b=0; b<40; b++)
        {
            CAD[a][b]=0;
        }
    }
    do
    {
        printf("_____________________________________________");
        printf("\n\n-------PIZZARIA ADS-------");
        printf("\n\n");
        printf("1-CADASTRAR PIZZAS\n");
        printf("2-EXIBIR CARD�PIO\n");
        printf("3-CADASTRAR RELAT�RIO DI�RIO\n");
        printf("4-EXIBIR RELAT�RIO DI�RIO\n");
        printf("5-VOLTAR AO MENU PRINCIPAL\n");
        printf("_____________________________________________");
        printf("\n\n");
        printf("Comando: ");
        scanf("%d", &opcao);
        system("cls");
        printf("\n\n");

        switch(opcao)
        {
        case 1:
            CadastrarPizzas();
            break;
        case 2:
            VerCardapio();
            break;
        case 3:
            CadastrarRelatorioDiario();
            break;
        case 4:
            ExibirRelatorioDiario();
            break;
        case 5:
            Menu_Principal();
            break;


        }
    }
    while(opcao!=6);

}
void CadastrarPizzas()
{
    printf("*PIZZAS SALGADAS*\n\n");
    for(i=1; i<=3; i++)
    {
        printf("\nPizza N�%d: ",i);
        getchar();
        gets(pizza[i]);
        printf("Valor: R$");
        scanf("%f", &valor_pizza[i]);
    }
    printf("\n*PIZZAS DOCES*\n");
    for(i=4; i<=5; i++)
    {
        printf("\nPizza N�%d: ",i);
        getchar();
        gets(pizza[i]);
        printf("Valor: R$");
        scanf("%f", &valor_pizza[i]);
    }
    printf(" ");
    printf("\n\n");
    printf("Pizzas Cadastradas com Sucesso.");
    printf("\n\n");

}
void VerCardapio()
{
    printf("CARD�PIO:\n\n");
    printf("*PIZZAS SALGADAS*\n");
    for(i=1; i<=3; i++)
    {
        printf("\nPizza N�%d: ",i);
        printf("%s\n", pizza[i]);
        printf("R$%.2f\n", valor_pizza[i]);
    }
    printf("\n*PIZZAS DOCES*\n");
    for(i=4; i<=5; i++)
    {
        printf("\nPizza N�%d: ",i);
        printf("%s\n", pizza[i]);
        printf("R$%.2f\n", valor_pizza[i]);
    }

}

void CadastrarRelatorioDiario()
{
    printf("CADASTRO DE RELAT�RIO\n\n");
    gets(date);
    printf("\nDATA: ");
    gets(data);
    printf("\nDigite o valor total positivo: R$");
    scanf("%f", &ganho);
    printf("\nDigite o valor total negativo: R$");
    scanf("%f", &perda);
    printf("\n\nRelat�rio Cadastrado com Sucesso!\n\n");
}
void ExibirRelatorioDiario()
{
    printf("\t*RELAT�RIO DI�RIO*\n\n");
    printf("DATA: %s\n", data);
    printf("VALOR POSITIVO: +R$%0.2f\n", ganho);
    printf("VALOR NEGATIVO: -R$%0.2f\n", perda);
    calculo=(ganho-perda);
    printf("LUCRO OBTIDO: R$%0.2f\n\n", calculo);

    if(calculo>500)
    {
        printf("\nO LUCRO DI�RIO EM RELA��O AO ESPERADO ENCONTRA-SE \nPOSITIVAMENTE ACIMA DO IDEAL!!\n\n");
    }
    else
    {
        printf("\nO LUCRO DI�RIO SE ENCONTRA ABAIXO DO IDEAL,\nFAVOR REVISAR O RELAT�RIO!!\n\n");
    }

}

//FIM DE FUN��ES RANGER//
//FUN��ES GIGANTE//
void Menu_de_editar_preco_e_fazer_pedido()
{
    system("cls");
    printf("\nBem Vindo\n");
    printf("1 - ALTERAR VALOR DE PIZZA\n");
    printf("2 - FAZER PEDIDO\n");
    printf("3 - OPNI�ES/COMENT�RIOS SOBRE A PIZZARIA\n");
    printf("4 - VOLTAR AO MENU PRINCIPAL\n");

    printf("Informe o numero da op��o que deseja acessar\n");
    scanf("%d", &opcao_menu);
    system("cls");

    if(opcao_menu==1)
    {
        editar_preco();
    }
    else if(opcao_menu==2)
    {
        pedido();
    }
    else if(opcao_menu==3)
    {
        opinioes_da_pizzaria();
    }
    else if(opcao_menu==4)
    {
        Menu_Principal();
    }
    else
    {
        printf("Opc�o Invalida\n");
        Menu_de_editar_preco_e_fazer_pedido();
    }

}

void editar_preco()
{
    do
    {
        VerCardapio();
        printf ("Informe o nome da pizza\n");
        scanf("%s", &sabores);
        printf("Qual o novo valor?\n");
        scanf("%f",&novo_valor);
        for(i=0; i<=6; i++)
        {
            if(strcmp(sabores, pizza[i])==0)
            {
                valor_pizza[i]=novo_valor;
            }
        }
        printf("Deseja mudar mais algum pre�o? sim/nao\n");
        scanf("%s",&edit_preco);
        for(i=0; i<=5; i++)
        {
            if(strcmp(edit_preco, sim[i])==0)
            {
                editar_preco();
            }
        }
        for(i=0; i<=5; i++)
        {
            if(strcmp(edit_preco, nao[i])==0)
            {
                Menu_de_editar_preco_e_fazer_pedido();
            }
        }


    }
    while(edit_preco==sim[i]);
}

void comentarios()
{
    if (opiniao<=10 && opiniao>=7)
    {
        i=quant_positivo;
        getchar();
        gets(positivo[i]);
        quant_positivo=quant_positivo+1;

    }
    if (opiniao<7 && opiniao>=5)
    {
        i=quant_mediano;
        getchar();
        gets(mediano[i]);
        quant_mediano=quant_mediano+1;

    }
    if (opiniao<5)
    {
        i=quant_negativo;
        getchar();
        gets(negativo[i]);
        quant_negativo=quant_negativo+1;

    }
    opiniao=opiniao-opiniao;
    Menu_de_editar_preco_e_fazer_pedido();

}

void pedido()
{
    printf("Hora do pedido\n");
    VerCardapio();
    printf ("Informe o nome da pizza\n");
    scanf("%s", &sabores);
    for(i=0; i<=6; i++)
    {
        if(strcmp(sabores, pizza[i])==0)
        {
            soma=soma+valor_pizza[i];
        }
    }
    printf("Deseja pedir outra pizza? sim/nao\n");
    scanf("%s",&opcao2);
    for(i=0; i<=5; i++)
    {
        if(strcmp(opcao2, sim[i])==0)
        {
            pedido();
        }
    }
    for(i=0; i<=5; i++)
    {
        if(strcmp(opcao2, nao[i])==0)
        {
            printf("Soma e de %.2f\n",soma);
            lucro=lucro+soma;
            soma=soma-soma;
            printf("Registre a sua opini�o\n");
            printf("Com uma nota de 0 a 5:\n");
            do
            {
                printf("Nota para o atendimento:\n");
                scanf("%d",&atendimento);
                printf("Nota para a Pizza:\n");
                scanf("%d",&quali_pizza);
                if(atendimento>5 || quali_pizza>5)
                {
                    printf("Valor digitado � improv�vel. Por favor repita o processo.\n");
                }
            }
            while(atendimento>5 || quali_pizza>5);
            opiniao=opiniao+atendimento+quali_pizza;
            opiniao_geral=opiniao_geral+opiniao;
            quantidade=quantidade+1;
            printf("Deseja registrar um coment�rio? sim/nao:");
            scanf("%s",&comentario);
            for(i=0; i<=5; i++)
            {
                if(strcmp(comentario, sim[i])==0)
                {
                    printf("Qual a sua opini�o\n");
                    comentarios();
                }
            }
            for(i=0; i<=5; i++)
            {
                if(strcmp(comentario, nao[i])==0)
                {
                }
            }
            Menu_de_editar_preco_e_fazer_pedido();
        }
    }
}

void opinioes_da_pizzaria(){
    system("cls");
    feedback=opiniao_geral/quantidade;
    {
        printf("\nA pizzaria tem nota: %.1f\n", feedback);
    }
    printf("Deseja ver opini�es de clientes?  sim/nao\n");
    scanf("%s",&opcao3);
    for(i=0; i<=5; i++)
    {
        if(strcmp(opcao3, sim[i])==0)
        {
            printf("Qual op��o deseja ver?\n");
            printf("1-Coment�rios Positivos\n");
            printf("2-Coment�rios Medianos\n");
            printf("3-Coment�rios Negativos\n");
            printf("Informe o n�mero ");
            scanf("%d",&estrelas);
            if (estrelas==1)
            {

                for(i=1; i<quant_positivo; i++)
                {
                    printf("\n Opini�o %d :\n\n",i);
                    printf(" %s\n",positivo[i]);
                }


            }
            if (estrelas==2)
            {

                for(i=1; i<quant_mediano; i++)
                {
                    printf("\n Opini�o %d :\n\n",i);
                    printf(" %s\n",mediano[i]);
                }


            }
            if (estrelas==3)
            {

                for(i=1; i<quant_negativo; i++)
                {
                    printf("\n Opini�o %d :\n\n",i);
                    printf(" %s\n",negativo[i]);
                }


            }

            printf("\n N�o h� mais coment�rios\n");
getchar();
getchar();
        }
    }
    for(i=0; i<=5; i++)
    {
        if(strcmp(opcao3, nao[i])==0)
        {
        }
    }

    Menu_de_editar_preco_e_fazer_pedido();
}
//FIM FUN��ES GIGANTE//

//FUN��ES GABRIEL//
void Menu_Cadastro_de_bebida()
{
    do
    {
        system("cls");
        printf("\n=======MENU=======\n1 - CADASTRAR\n2 - LISTAR BEBIDAS\n3 - PESQUISAR\n4 - ALTERAR VALOR \n5-VOLTAR AO MENU PRINCIPAL\n6 - SAIR \n================== \n");
        scanf("%i", &op);
        system("cls");
        printf("-------------------");
        switch(op)
        {
        case 1:
            cadastro_de_bebidas();
            break;
        case 2:
            listar_bebidas();
            break;
        case 3:
            pesquisar_bebidas();
            break;
        case 4:
            alterar();
            break;
        case 5:
            Menu_Principal();
            break;
        case 6:
            system("exit");
            break;
        default:
            printf("opcao invalida");
            break;
        }

    }
    while(op!=5);

}
void cadastro_de_bebidas ()
{
    static int linha;
    do
    {
        printf("\nNome da bebida :");
        scanf("%s", &nome_da_bebida[linha]);
        printf("\nID da bebida :");
        scanf("%i",&indent[linha]);
        printf("\nValor da bebida R$:");
        scanf("%f",&valor_bebida[linha]);
        printf("\n====================");
        linha++;
        printf("\nDigite 1 para continuar 2 para sair\n ");
        scanf("%d",&op);


    }
    while (op == 1);
}

void listar_bebidas ()
{
    int i;
    for (i=0; i<tamanhoVetor; i++)
    {
        if (indent[i]>0)
        {
            printf("\nProduto:%s\nID:%i\nValor R$:%.2f",nome_da_bebida[i],indent[i],valor_bebida[i]);
            printf("\n========================");
        }
        else
        {
            printf("\nENTER PARA SAIR");
            break;
        }
    }
    getchar();
    getchar();
}


void pesquisar_bebidas()
{
    int indentpesquisa;
    char nomepesquisa[10];
    int i;
    do
    {
        printf("\nDIGITE 1 PARA BUSCAR:");
        scanf("%i", &op);
        switch(op)
        {
        case 1:
            printf("\nDIGITE O ID PARA BUSCAR:");
            scanf ("%i",&indentpesquisa);
            printf("\nBUSCANDO...");
            printf("\n=======================");
            for(i=0; i<tamanhoVetor; i++)
            {
                if(indent[i]==indentpesquisa)
                {
                    printf("\nProduto: %s\nID: %i\nValor: %.2f",nome_da_bebida[i],indent[i],valor_bebida[i]);
                    printf("\n====================================");
                }
            }
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
        printf("\nDIGITE 1 PARA CONTINUAR /2 PARA SAIR :");
        scanf("%i", &op);
    }
    while(op==1);

}
void alterar()
{
    int i;
    printf ("\nInforme o n�mero de id do produto\n");
    scanf("%i", &produto);
    printf("Qual o novo valor?\n");
    scanf("%f",&novo_valor);
    for(i=0; i<=tamanhoVetor; i++)
    {
        if(produto==indent[i])
        {
            valor_bebida[i]=novo_valor;
        }
    }
}
//FIM FUN��ES GABRIEL//

//FUN��ES RENATO//
void Menu_cadastro_de_cliente()
{
    do
    {
        system("cls");
        printf("\n----------MENU----------\n1 - CADASTRAR\n2 - LISTAR TODOS\n3 - PESQUISAR\n4 - VOLTAR AO MENU PRINCIPAL\n5 - SAIR\n\nDigite a op��o que deseja acessar:");
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            cadastro();
            break;
        case 2:
            listar_clientes();
            getchar();
            getchar();
            break;
        case 3:
            pesquisar_cliente();
            break;
        case 4:
            Menu_Principal();
            break;
        case 5:
            system("exit");
            break;
        default:
            printf("\nOpc�o inv�lida");
            getchar();
            getchar();
            break;
        }
    }
    while(op!=5);

}

void listar_clientes()
{
    int i;
    for(i=0; i<LINHA; i++)
    {
        if(rg[i]>0)
        {
            printf("\nNome: %s\nEmail: %s\nRG: %d\nEndere�o: %s\nN�mero Residencial: %d\nTelefone: %d \n\n", nome_cliente[i], email[i], rg[i], endereco[i], numresidencia[i], telefone[i]);
        }
        else
            break;
    }
    getchar();
    getchar();
}

void cadastro()
{

    static int linha;
    do
    {
        printf("\nDigite o nome do cliente:");
        getchar();
        gets(nome_cliente[linha]);
        printf("\nDigite o email do cliente:");
        scanf("%s", &email[linha]);
        printf("\nDigite o RG do cliente:");
        scanf("%d", &rg[linha]);
        printf("\nDigite o endere�o do cliente:");
        getchar();
        gets(endereco[linha]);
        printf("\nDigite o n�mero da residencia do cliente:");
        scanf("%d", &numresidencia[linha]);
        printf("\nDigite o telefone do cliente:");
        scanf("%d", &telefone[linha]);

        printf("\nDigite 1 para continuar ou outro valor para sair:");
        scanf("%d", &op);
        linha++;

    }
    while(op==1);

}

void pesquisar_cliente()
{
    int rgpesquisa;
    char emailpesquisa[50];
    int i;
    do
    {
        printf("\nDigite 1 para pesquisar por RG ou 2 para pesquisar por email:");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("\nDigite o RG:");
            scanf("%d", &rgpesquisa);
            for(i=0; i<LINHA; i++)
            {
                if(rg[i]==rgpesquisa)
                {
                    printf("\nNome: %s\nEmail: %s\nRG: %d\nEndere�o: %s\nN�mero Residencial: %d\nTelefone: %d", nome_cliente[i], email[i], rg[i], endereco[i],numresidencia[i], telefone[i]);
                }
            }
            break;
        case 2:
            printf("\nDigite o E-mail:");
            scanf("%s", emailpesquisa);
            for(i=0; i<LINHA; i++)
            {
                if(strcmp(email[i], emailpesquisa)==0)
                {
                    printf("\nNome: %s\nEmail: %s\nRG: %d\nEndere�o: %s\nN�mero Residencial: %d\nTelefone: %d", nome_cliente[i], email[i], rg[i], endereco[i], numresidencia[i], telefone[i]);
                }
            }

            break;
        default:
            printf("\nOp��o inv�lida!");
            break;

        }
        printf("\nDigite 1 para continuar pesquisando:\t");
        scanf("%d", &op);
    }
    while(op==1);
}
//FIM FUN��ES RENATO//
//FUN��ES GIOVANA//
/* Programa Principal*/
void Menu_de_cadastro_de_funcionarios()
{
    posi = 0;
    do
    {
        system("cls");
        printf("    * Cadastro de Funcion�rios * \n\n");
        printf("1) CADASTRO \n");
        printf("2) LISTAR\n");
        printf("3) PESQUISAR \n");
        printf("4) ALTERAR \n");
        printf("5) VOLTAR AO MENU PRINCIPAL\n");
        printf("Digite a op��o que deseja acessar: ");
        scanf("%d",&opcao);
        system("cls");
        printf("\n");


        switch(opcao)
        {
        case 1:
        {
            printf(" INSERINDO NOVO REGISTRO \n\n");
            if(posi< MAX)
            {
                inserir();
                printf(" DADOS INSERIDO COM SUCESSO!\n\n");
            }
            else
            {
                printf(" Desculpe, Sistema de Cadastro est� no limite!\n\n");
            }
            break;
        }

        case 2:
        {
            if(posi == 0)
            {
                printf("n�o h� dados no sistema!\n\n");
            }
            else
            {
                printf(" Listando os Funcion�rios cadastrados\n\n");
                listar();
            }
            break;
        }
        case 3:
        {
            if(posi== 0)
            {
                printf("n�o h� dados no sistema!\n\n");
            }
            else
            {
                printf(" PESQUIZANDO DADOS\n\n");
                pesquisar();
            }
            break;
        }
        case 4:
        {
            if(posi == 0)
            {
                printf("n�o h� dados no sistema!\n\n");
            }
            else
            {
                printf(" ALTERANDO DADOS!\n\n");
                alterar_dados_do_funcionario();
                printf(" DADOS ALTERADOS COM SUCESSO!\n\n");
            }
            break;
        }
        case 5:
        {
            if(posi == 0)
            {
                printf("n�o h� dados no sistema!\n\n");
            }
            else
            {
                printf(" ALTERANDO DADOS!\n\n");
                Menu_Principal();
                printf(" DADOS ALTERADOS COM SUCESSO!\n\n");
            }
            break;
        }
        default:
            printf("  OPCAO INVALIDA! \n\n");
        }

        printf("\n");

        printf(" DIGITE 1 PARA CONTINUAR OU 0 PARA SAIR: ");
        scanf("%d",&seguir);
    }
    while(seguir==1);



    getchar();
    return opcao;

}
/* Funcao para inserir registros*/
void inserir()
{
    funcionario[posi].cod = posi+1;
    printf(" CODIGO : %d\n",funcionario[posi].cod);

    printf(" NOME: ");
    getchar();
    gets(funcionario[posi].nome_do_funcionario);

    printf(" IDADE: ");
    scanf("%d", &funcionario[posi].idade);

    printf(" SEXO: ");
    getchar();
    gets(funcionario[posi].sexo);

    printf(" SALARIO: R$");
    scanf("%f", &funcionario[posi].salario);

    printf(" CARGO: ");
    getchar();
    gets(funcionario[posi].cargo);



    printf("\n");

    posi = posi + 1;
}
//Fun��o para listar os funcionario}
//s cadastrados no Sistema/



void listar()
{
    int i;

    for(i=0; i<posi; i++)
    {
        printf(" ARQUIVO %d\n\n",(i+1));
        printf(" C�DIGO: %d\n",funcionario[i].cod);
        printf(" NOME: %s\n",funcionario[i].nome_do_funcionario);
        printf(" IDADE: %d\n",funcionario[i].idade);
        printf(" SEXO: %s\n",funcionario[i].sexo);
        printf(" SAL�RIO: R$%.2f\n",funcionario[i].salario);
        printf(" CARGO: %s\n",funcionario[i].cargo);

        printf("\n\n");
    }
}

//Fun��o para alterar os funcionarios cadastrados no Sistema/

void alterar_dados_do_funcionario()
{
    int i,dado,cont ;

    printf(" ATEN��O! PARA ALTERAR UM REGISTRO \n");
    printf(" EFETUE UMA PESQUISA PELO SEU C�DIGO. \n\n");
    printf(" C�DIGO DO REGISTRO: ");
    scanf("%d",&dado);
    for(i=0; i<posi; i++)
    {
        if(dado == funcionario[i].cod)
        {
            cont = cont + 1;

            printf(" NOME: ");
            getchar();
            gets(funcionario[i].nome_do_funcionario) ;

            printf(" IDADE: ");
            scanf("%d", &funcionario[i].idade);

            printf(" SEXO: ");
            getchar();
            gets(funcionario[i].sexo);


            printf(" SAL�RIO: R$");
            scanf("%f", &funcionario[i].salario);

            printf(" CARGO: ");
            getchar();
            gets(funcionario[i].cargo);


        }
    }
    if(cont == 0)
    {
        printf(" DADOS NAO ENCONTRADO!\n\n");
    }
}

//Fun��o para pesquisar dados cadastrados no Sistema/
void pesquisar()
{
    int i,dado,cont = 0;
    printf(" PESQUISA PELO C�DIGO DO FUNCION�RIO: ");
    scanf("%d",&dado);
    for(i = 0; i < posi; i++)
    {
        if(dado == funcionario[i].cod)
        {
            printf("DADOS ENCONTRADO \n\n");
            printf(" C�DIGO: %d\n",funcionario[i].cod);
            printf(" NOME: %s\n",funcionario[i].nome_do_funcionario);
            printf(" IDADE: %d\n",funcionario[i].idade);
            printf(" SEXO: %s\n",funcionario[i].sexo);
            printf(" SAL�RIO: R$%.2f\n",funcionario[i].salario);
            printf(" CARGO: %s\n",funcionario[i].cargo);

            printf("\n");
            cont = cont + 1;
        }
    }
    if(cont == 0)
    {
        printf(" Registro n�o Encontrado!\n\n");
    }
}

//FIM FUN��ES GIOVANA//

//FUN��ES ANDERSON//
void Menu_Cadastro_de_materia_prima()
{
    system("cls");

    int op;

    printf("-------------------------------------------------------\n");

    printf(" CONTROLE DE MAT�RIAS PRIMAS \n \n ");

    printf("-------------------------------------------------------\n");

    printf("Cadastro da Pizzaria: \n");

    do
    {

        printf("\n 1- CADASTRAR ESTOQUE: \n");

        printf("\n 2- EXIBIR ESTOQUE: \n");

        printf("\n 3- CADASTRO DE PIZZAS:\n");

        printf("\n 4- CALCULAR PIZZAS: \n");

        printf("\n 5-  VOLTAR AO MENU PRINCIPAL: \n \n \n");

        scanf("%d", &op);
        system("cls");

        switch (op)

        {

        case 1:

            cadastrar_estoque();

            system("cls");

            break;

        case 2:

            exibir_estoque();

            system("cls");

            break;

        case 3:

            cadastrar_pizzas();

            system("cls");

            break;

        case 4:

            calculo_estoque();

            system("cls");

            break;

        case 5:

            Menu_Principal();

            break;


        }

    }
    while (op!=5);

}

void cadastrar_estoque ()

{

    printf("********** ESTOQUE GERAL *********: \n");

    for (i=1; i<=5; i++)

    {

        printf("\n Ingrediente %u:", i);

        getchar();

        gets(ingredientes[i]);

        printf("\n %s (KG):",ingredientes[i]);

        scanf("%f", &kg[i]);

    }

}

void exibir_estoque ()

{

    for (i=1; i<=5; i++)

    {

        printf("\n ------------------------------------------------------- ");

        printf("\n Nome da %u mat�ria prima %s (KG): %2.f\n", i, ingredientes [i], kg[i]);

    }

    getchar();

    getchar();

}

void cadastrar_pizzas ()

{

    printf("Qual pizza deseja fazer? \n");

    printf("1 - Calabresa \n");

    printf("2 - Mussarela \n");

    printf("informe o n�mero \n");

    scanf("%d",&pizzas1);

    for (g=1; g<=5; g++)
    {

        printf("Ingredientes restantes no estoque: %s tem %.2f KG \n", ingredientes[g], kg[g]);

    }

    if (pizzas1==1)

    {

        printf("\n Insira os Ingredientes da Pizza Calabresa: \n");

        for (i=1; i<=5; i++)

        {

            printf("\n Pizza de Calabresa - Ingrediente %u:", i);

            scanf("%s", &ingredientes_calabresa[i]);

            printf("\n %s (KG): \n",ingredientes_calabresa[i]);

            scanf("%f", &kg_calabresa[i]);

        }

        if (pizzas1==2)

        {

            printf("\n Insira os Ingredientes da Pizza Mussarela: \n");

            for (i=1; i<=5; i++)

            {

                printf("\n Pizza de Mussarela - Ingrediente %u:", g);

                scanf("%s", &ingredientes_mussarela[g]);

                printf("\n %s (KG): \n",ingredientes_mussarela[g]);

                scanf("%f", &kg_mussarela[g]);
            }
        }
    }
        getchar();
        getchar();
}

void calculo_estoque ()

{

    printf("Qual pizza deseja fazer? \n");

    printf("1 - Calabresa \n");

    printf("2 - Mussarela \n");

    printf("informe o n�mero \n");

    scanf("%d",&pizzas);

    printf("Ingredientes dispon�veis \n");


    for(i=1; i<=5; i++)

    {

        printf("\n %s (KG): %.2f \n", ingredientes [i],kg[i]);

    }

    if(pizzas==1)

    {

        printf("Valores unit�rios");

        for(i=1; i<=5; i++)

        {

            printf("\t %s (KG): %.2f \n", ingredientes_calabresa [i],kg_calabresa [i]);

        }

        printf("Quantas pizzas de calabresa deseja fazer?");

        scanf("%d",&n_pizza);

        for(g=1; g<=6; g++)

        {

            for(i=1; i<=6; i++)

            {

                if(strcmp(ingredientes[g],ingredientes_calabresa [i])==0)

                {

                    kg[g]=kg[g]- (kg_calabresa[i]*n_pizza);

                }

            }

        }

        for (g=1; g<=5; g++)
        {

            printf("Ingredientes restantes no estoque: %s tem %.2f KG \n", ingredientes[g], kg[g]);

        }

    }

    getchar();

    getchar();

    if(pizzas==2)

    {

        printf("valores unit�rios");

        for(i=1; i<=5; i++)

        {

            printf("\t %s (KG): %.2f \n",ingredientes_mussarela[i],kg_mussarela[i]);

        }

        printf("Quantas pizzas de mussarela deseja fazer?");

        scanf("%d",&n_pizza);

        for(g=1; g<=6; g++)

        {

            for(i=1; i<=6; i++)

            {

                if(strcmp(ingredientes[i],ingredientes_mussarela[i])==0)

                {

                    kg[g]==kg[g]-(kg_mussarela[i]*n_pizza);

                }

            }

        }

        for (g=1; g<=5; g++)
        {

            printf("Ingredientes restantes no estoque: %s tem %.2f KG \n", ingredientes[g], kg[g]);


        }

    }
        getchar();
        getchar();
}


//FIM FUN��ES ANDERSON//
int main(void)
{
    setlocale(LC_ALL,"portuguese");
    do
    {
        printf("\tBEM VINDA A PIZZARIA ADS2\n\n");
printf("\tTELA DE LOGIN\n");
printf("USU�RIO : ");
scanf("%s",&usuario);
printf("SENHA : ");
scanf("%s",&senha);
if((strcmp(usuario_cadastrado, usuario)==0) && (strcmp(senha_cadastrada, senha)==0)){
Menu_Principal();
}
else{
        system("cls");
    printf("\t\tLOGIN OU SENHA INV�LIDA\n\n");
}

    }
    while(opcao!=6);

    system("pause");
    return 0;
}



