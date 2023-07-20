#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registro() // Função responsável por cadastrar os usuários no sistema
{
    // Inicio de criação de variáveis/string(conjunto de variáveis)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/string

    printf("Digite o CPF a ser cadastrado: "); // Coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a string

    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings

    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file, cpf); // salvando o valor da variável
    fclose(file); // fechando o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o seu cargo: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    system("pause"); // Pausando o sistema
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese_Brasil.1252");

    char cpf[40];
    char conteudo[200];

    printf("Digite o seu CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, não localizado\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        fclose(file);
        printf("Arquivo não localizado.\n");    
        system("pause");
    } 

    else if (file != NULL)
    {
        fclose(file);
        printf("Arquivo deletado com sucesso.\n");
        system("pause");
        remove(cpf);
    }

    
}

int main()
{
    int opcao = 0; // Definindo variáveis
    int laco = 1;

    for (laco = 1; laco == 1;)
    {

        system("cls");

        setlocale(LC_ALL, "Portuguese_Brasil.1252"); // Definindo a Linguagem

        printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Saida do programa\n\n");
        printf("Opção: "); // Fim do menu

        scanf("%d", &opcao); // Armazenando as informações na variável

        system("cls"); // Limpando a tela

        switch (opcao) // Ínicio da seleção
        {
        case 1:
            registro(); // Chamada de funções
            break;

        case 2:
            consulta();
            break;

        case 3:
            deletar();
            break;

        case 4:
            printf("Saindo do programa...\n");
            system("pause");
            laco = 0;
            break;

        default:
            printf("Essa não é uma opção válida\n");
            system("pause");
            break;
        } // Fim de seleção
    }
    return 0;
}