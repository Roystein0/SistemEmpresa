#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*Criando a estrutura para armazenar os dados do funcionario*/
typedef struct
{
    char nome[40];
    int idade;
    int horas;
    int id;
} Funcionario;
int qntFunc = 0;
/*Menu que apresenta todas as opções para o usuario escolher*/
void menuPrincipal()
{
    system("cls");
    printf("\n-=-=-=-=-=-=-=   Cadastro de funcionario    -=-=-=-=-=-=-");
    printf("\n1 - Cadastrar funcionario ");
    printf("\n");
    printf("\n2 - Excluir cadastro ");
    printf("\n");
    printf("\n3 - Listar todos os funcionarios (Memoria)");
    printf("\n");
    printf("\n4 - Ordena por horas trabalhadas");
    printf("\n");
    printf("\n5 - Ordenar por ordem alfabetica");
    printf("\n");
    printf("\n6 - Salvar Funcionario no Arquivo");
    printf("\n");
    printf("\n7 - Imprimir funcionarios do arquivo");
    printf("\n");
    printf("\n8 - Apagar Arquivo");
    printf("\n");
    printf("\n0 - Sair");
}
/*Função do tipo interiro para inserir os funcionarios na struct*/
int InserirFunc(Funcionario func[21]) /*criando as variaveis, uma do tipo funcionario, e a outra do tipo inteiro*/
{
    setbuf(stdin, NULL);
    /*variaveis para auxiliar no armazenamento*/
    int aux = 0, resposta = 0;

    do
    {
        system("cls");
        /*Informações mostra na tela e sendo armazenadas na struct*/
        printf("\nDigite o nome do funcionario: ");
        setbuf(stdin, NULL); // limpando o buffer do teclado
        fgets(func[qntFunc].nome, 40, stdin);

        printf("\nDigite as horas trabalhadas: ");
        scanf("%d", &func[qntFunc].horas);
        setbuf(stdin, NULL);

        printf("\nDigite a idade: ");
        scanf("%d", &func[qntFunc].idade);
        setbuf(stdin, NULL);

        func[qntFunc].id = qntFunc;
        aux++;
        //  tam++;
        qntFunc++;

        if (aux > 21) // condição para verificar se a quantidade de funcionarios é maior que 21.
        {
            /*Se a condição for satisfeita aparecerá a mensagem abaixo ao usuario*/
            printf("\nFUNCIONARIO CADASTRADO COM SUCESSO!!\n");
            printf("\n");
            system("pause");
            resposta = 0;
            break;
        }
        printf("\n\nDESEJA CONTINUAR CADASTRANDO?\n");
        printf("\n[1 - SIM]");
        printf("\n[0 - NAO]\n");
        setbuf(stdin, NULL); // LIMPANDO O BUFFER DO TECLADO.
        scanf("%d", &resposta);

    } while (resposta == 1); // looping para verificar se o usuario ainda deseja casdastrar mais funcionairos
    printf("%d", qntFunc);
    return (aux);
}

/*Procedimento para imprimir os usuarios cadastrados*/
void printFuncMem(Funcionario func[21])
{
    setbuf(stdin, NULL);
    printf("\n########Funcinarios cadastrados########");

    /*estrutura de repetição, para mostrar os usuarios na tela*/
    for (int j = 0; j < qntFunc; j++)
    {
        printf("\nNome do funcionario:  %s", func[j].nome);
        printf("\nHoras trabalhada: %d", func[j].horas);
        printf("\nIdade: %d", func[j].idade);
        printf("\nID do  funcionario: %d", func[j].id);
        printf("\n============================================");
    }
    printf("\n");
    system("pause");
}
/*Teste para verificar se está funcionando a função de imprimir*/
void teste001()
{
    int tam = 0, resp = 0;
    Funcionario func[21];
    // printFuncMem(func, tam);
    system("pause");
    system("cls");
}
/*Usando o metodo Insertion sort para a ordenação, onde consite percorrer o vetor da esquerda para a direita,
pegando o valor que está passando, e testando com todos os valores que estão a sua esquerda
se são maiores que ele*/

void organizaHoras(Funcionario func[21])
{
    int tHoras = qntFunc;
    Funcionario temp;
    setbuf(stdin, NULL);

    for (int j = qntFunc - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (func[i].horas > func[i + 1].horas)
            {
                temp = func[i];
                func[i] = func[i + 1];
                func[i + 1] = temp;
            }
        }
    }
    printf("quantidade: %d", tHoras);
    setbuf(stdin, NULL);
    for (int i = 0; i < tHoras; i++) // estrutura de repetição para mostrar os dados na tela.
    {
        printf("\n---- Ordenado por horas trabalhadas ------");
        printf("\nFuncionario: %s", func[i].nome);
        printf("Quantidade de horas trabalhadas: %d\n", func[i].horas);
        printf("Idade: %d\n", func[i].idade);
        printf("\n==Organizado com sucesso!!\n");
        printf("\n============================================");
    }
    /*parte designada ao salvamento dos funcionarios no arquivo*/
    int op;
    FILE *file;                                            // ponteiro para arquivo
    file = fopen("funcionarios_Organizado_Hora.txt", "w"); // abrindo o arquivo funcionarios no modo de escrita (w). Se o arquivo não existir ele será criado.
    printf("\n\nDeseja salvar o arquivo organizado por horas trabalhadas? ");
    printf("\n1 - Salvar");
    printf("\n2 - Sair");
    printf("\nEscolha uma opacao: ");
    scanf("%d", &op);
    // estrutura de condição para saber se o usuario deseja salvar o cadastro, ou se deseja sair
    switch (op)
    {

    case 1:
        for (int i = 0; i < tHoras; i++)
        {
            fprintf(file, "%s", func[i].nome);
            fprintf(file, "%d\n", func[i].horas);
            fprintf(file, "%d\n", func[i].idade);
        }
        printf("FUNCIONARIOS SALVOS COM SUCESSO!!");
        break;
    case 2:
        return 0;
        break;
    default:
        printf("\nOPCAO INVALIDA");
        break;
    }
    setbuf(stdin, NULL);
    fclose(file); // fechando o arquivo.
    system("pause");
}
/*A ordenação por ordem alfabetica foi feita com base na ordenação por horas */
void ordemalfabetica(Funcionario func[21])
{
    Funcionario temp;
    int tnome = qntFunc;
    for (int i = 0 ; i < tnome ; i++){
        for (int j = i+1 ; j < tnome ; j ++ ){
        if (strcmp(func[i].nome,func[j].nome)>0){
            temp = func[i];
            func[i]=func[j];
            func[j]=temp;
            }
        }
    }

    setbuf(stdin, NULL);
    for (int i = 0; i < tnome; i++) // estrutura de repetição para mostrar os dados na tela.
    {
        printf("\n---- Ordenado por ordem alfabetica ------");
        printf("\nFuncionario: %s", func[i].nome);
        printf("Quantidade de horas trabalhadas: %d\n", func[i].horas);
        printf("Idade: %d\n", func[i].idade);
        printf("\n==Organizado com sucesso!!\n");
        printf("\n============================================");
    }
    // parte de salvamento...
    int op;
    FILE *file;
    file = fopen("funcionarios_Orgdem_Alfabetica.txt", "w"); // abrindo o arquivo funcionarios no modo de escrita (w). Se o arquivo não existir ele será criado.
    printf("\n\nDeseja salvar o arquivo em ordem alfabetica? ");
    printf("\n1 - Salvar");
    printf("\n2 - Sair");
    printf("\nEscolha uma opacao: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
        for (int i = 0; i < qntFunc; i++)
        {
            fprintf(file, "%s", func[i].nome);
            fprintf(file, "%d\n", func[i].horas);
            fprintf(file, "%d\n", func[i].idade);
        }
        printf("FUNCIONARIOS SALVOS COM SUCESSO!!");
        break;
    case 2:
        system("pause");
        menuPrincipal();
        break;
    default:
        printf("\nOPCAO INVALIDA");
        break;
    }
    printf("valor da quantidade de funcionario: d%", tnome);
    setbuf(stdin, NULL);
    fclose(file);
    system("pause");
}
/*procedimento responsavel por salvar o cadastro de funcionairos no arquivo*/
void SalvarFuncionarios(Funcionario func[21])
{
    int tamanho = qntFunc;
    int op;
    // op = res
    FILE *file;
    // file = pont_arq
    file = fopen("funcionarios.txt", "w"); // abrindo o arquivo funcionarios no modo de escrita (w). Se o arquivo não existir ele será criado.
    setbuf(stdin, NULL);
    printf("\n1 - Salvar");
    printf("\n2 - Sair");
    printf("\nEscolha uma opacao: ");
    scanf("%d", &op);
    switch (op)
    {

    case 1:
        // repetição para salvar os usuarios
        for (int i = 0; i < tamanho; i++)
        {
            fprintf(file, "%s", func[i].nome);
            fprintf(file, "%d\n", func[i].horas);
            fprintf(file, "%d\n", func[i].idade);
        }
        // print mostrado na tela
        printf("FUNCIONARIOS SALVOS COM SUCESSO!!");
        return 0;
        break;
    case 2:
        return 0;
        break;
    default:
        printf("\nOPCAO INVALIDA");
        break;
    }
    fclose(file);
}
/*Esse procedimento é o responsavel por ler o arquivo 'funcionarios.txt'*/
void ImprimirLista()
{
    FILE *arq;
    arq = fopen("funcionarios.txt", "r"); // abrindo o arquivo no modo de leitura(r).
    char cPalavra[64];
    // se o arquivo for igual a 0 irá da um erro de abertura
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    getchar();
    while (fgets(cPalavra, 64, arq) != NULL)
    {
        printf("\n");
        printf(" %s  ", cPalavra);
    }
    setbuf(stdin, NULL);
    printf("\n\n");
    system("pause");
    system("cls");
}
/*procedimento responsavel por imprimir o arquivo 'funcionarios_Organizado_Hora.txt'*/
void ImprimeFuncHoras()
{
    FILE *arq_horas;
    arq_horas = fopen("funcionarios_Organizado_Hora.txt", "r");
    char cPalavra[64];
    // mesma ideia do procedimento anterior
    if (arq_horas == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    getchar();
    while (fgets(cPalavra, 64, arq_horas) != NULL)
    {
        printf("\n");
        printf(" %s  ", cPalavra);
    }
    setbuf(stdin, NULL);
    printf("\n\n");
    system("pause");
    system("cls");
}
/*procedimento para deletar o arquivo de cadastro*/
void deletaFunc()
{
    FILE *file;                            // ponteiro pora file
    file = fopen("funcionarios.txt", "r"); // abrindo no modo de leitura
    // verificando se o arquivo é diferente de 0, se for irá apaga-lo usando a função remove
    if (file != NULL)
    {
        fclose(file);
        printf("\nArquivo apagado com sucesso\n", remove("funcionarios.txt"));
        return 1;
    }
    else
    {
        printf("\nErro ao abrir o arquivo, ou nao existe!\n");
    }
    setbuf(stdin, NULL);
}
/*procedimento para deletar o arquivo de cadastro*/
void deletaFunHoras()
{
    FILE *file;
    file = fopen("funcionarios_Organizado_Hora.txt", "r");

    if (file != NULL)
    {
        fclose(file);
        printf("\nArquivo apagado com sucesso\n", remove("funcionarios_Organizado_Hora.txt"));
        return 1;
    }
    else
    {
        printf("\nErro ao abrir o arquivo, ou nao existe!\n");
    }
    setbuf(stdin, NULL);
}
/*procedimento para deletar o arquivo de cadastro*/
void deletaFunNome()
{
    FILE *file;
    file = fopen("funcionarios_Orgdem_Alfabetica.txt", "r");

    if (file != NULL)
    {
        fclose(file);
        printf("\nArquivo apagado com sucesso\n", remove("funcionarios_Orgdem_Alfabetica.txt"));
        return 1;
    }
    else
    {
        printf("\nErro ao abrir o arquivo, ou nao existe!\n");
    }
    setbuf(stdin, NULL);
}
/*procedimento designado as funções de deletar o arquivo*/
void menuDeleta()
{
    // opções que aparecerá na tela para o usuario escolher
    int opDel;
    printf("Qual arquivo deseja deletar?");
    printf("\n1 - Arquivo 'funcionarios.txt'? ");
    printf("\n2 - Arquivo 'funcionarios_Organizado_Hora.txt'? ");
    printf("\n3 - Arquivo 'funcionarios_Orgdem_Alfabetica.txt'? ");
    printf("\n0 - Sair");
    printf("\nEscolha: ");
    scanf("%d", &opDel);
    /*usando o switch case para executar a escolha do usuario com base em uma comparação de valores.*/
    switch (opDel)
    {
    case 1:
        // invocando o procedimento
        deletaFunc();
        system("pause");
        break;
    case 2:
        // invocando o procedimento de apagar o registro organizado por hora
        deletaFunHoras();
        system("pause");
    case 3:
        // invocando o procedimento de apagar o registro organizado por nome
        deletaFunNome();
        system("pause");
        break;
    case 0:
        system("pause");
        return 0;
        break;
    default:
        printf("\nOPCAO INVALIDA");
        break;
    }
}
/*procedimento de opções de impressão ao usuario*/
void opImprime()
{
    // menu para o usuario escolher
    int op = 0;
    printf("\n1 - Imprime funcionario do arquivo (sem tratamentos de dados)");
    printf("\n2 - Imprime funcionario do arquivo por ordem de horas trabalhadas");
    printf("\n3 - Imprime funcionario do arquivo por ordem alfabetica");
    printf("\n0 - Sair");
    printf("\nEscolha uma opacao: ");
    scanf("%d", &op);
    // usando a estrutura de condição switch case, que consiste na comparação de valores para executar determinado bloco de comandos.
    switch (op)
    {

    case 1:
        ImprimirLista();
        break;
    case 2:
        ImprimeFuncHoras();
        break;
    case 3:

        break;
    case 0:
        return 0;
        break;
    default:
        printf("\nOPCAO INVALIDA");
        break;
    }
}
/*Procedimento para mostrar o menu principal*/
void opcaoMenu()
{
    int tamanho = 0, op;  // variaveis para usar no parametros
    Funcionario func[21]; // vetor do tipo funcionario com 21 posições

    do
    {

        menuPrincipal();         // invocando o procedimento
        setbuf(stdin, NULL);     // limpando o buffer do teclado para evitar erros.
        printf("\nEscolha:   "); // pedindo para o usuario digitar a opção
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
            InserirFunc(func);
            op = 100;
            system("pause");
            system("cls");
            break;

        case 2:
            break;

        case 3:
            printFuncMem(func); // invocando o procedimento
            op = 100;
            system("cls");
            break;

        case 4:
            organizaHoras(func); // invocando o procedimento
            op = 100;
            system("cls");
            break;

        case 5:
            ordemalfabetica(func); // invocando o procedimento
            system("pause");
            break;
        case 6:
            SalvarFuncionarios(func); // invocando o procedimento
            system("pause");
            system("cls");
            break;
        case 7:
            opImprime(); // invocando o procedimento
            system("pause");
            system("cls");
            break;
        case 8:
            menuDeleta(); // invocando o procedimento
            system("pause");
            system("cls");
            break;
        case 0:

            return 0;
            break;

        default:
            system("cls");
            printf("\nOpcao invalida\n");
            op = 100;
            break;
        }
    } while ((op < 0) || (op > 8)); // condição para efetuar o looping do menu
}

int main()
{

    opcaoMenu(); // invocando o procedimento menu888

    return 0;
}
