#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define contatos_maximo 100

typedef struct Contato
{
    char nome[30];
    char telefone[50];
    char email[50];
} Contato;

int contatosRegistrados = 0;
FILE *fptr;

void listarContatosArquivo(Contato contatos[]) {
    fptr = fopen("contatos.txt", "w");
    for (int i = 0; i < contatosRegistrados; i++) {
        fprintf(fptr, "Contato %i\n", i + 1);
        fprintf(fptr, "Nome: %s\n", contatos[i].nome);
        fprintf(fptr, "Email: %s\n", contatos[i].email);
        fprintf(fptr, "Telefone: %s\n", contatos[i].telefone);
        fprintf(fptr, "\n");
    }
    fclose(fptr);
    printf("Contatos salvos no arquivo contatos.txt\n");
}

void listarContatosTela(Contato contatos[]) {
    for (int i = 0; i < contatosRegistrados; i++) {
        printf("Contato %i\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Email: %s\n", contatos[i].email);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("\n");
    }
}


void listarContatos(Contato contatos[]){
    system("clear");
    int opcaoListar;
    if (contatosRegistrados == 0) {
        printf("Nenhum contato registrado.\n");
        return;
    }
    printf("1 - Listar contatos na tela\n2 - Salvar contatos em um arquivo de texto");
    printf("\nEscolha uma opção: ");
    scanf("%i", &opcaoListar);
    if (opcaoListar == 1) {
        listarContatosTela(contatos);
    } else if (opcaoListar == 2) {  
        listarContatosArquivo(contatos);
    } else {
        printf("Opção inválida.");
    }
}

void incluirContatos(Contato contatos[]) {
    char nome[30], telefone[50], email[50];
    printf("Escreva o nome do contato:");
    scanf("%s", &nome);
    printf("Escreva o telefone do contato:");
    scanf("%s", &telefone);
    printf("Escreva o email do contato:");
    scanf("%s", &email);
    Contato contato;
    strcpy(contato.nome, nome); 
    strcpy(contato.telefone, telefone); 
    strcpy(contato.email, email); 

    if (contatosRegistrados < contatos_maximo){ 
    contatos[contatosRegistrados] = contato;
    contatosRegistrados++;
    }

}

void excluirContatos(Contato contatos[]) {
    for (int i = 0; i < contatosRegistrados; i++) { 
        printf("Índice do contato: %i\n", i + 1);
        printf("Nome: %s", contatos[i].nome);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
    }
    int indice;
    if (contatosRegistrados > 0) {
    printf("\nEscolha o índice que você queira excluir:");
    scanf("%i", &indice);
    if (indice > 0 && indice <= contatosRegistrados) {
        for (int i = indice - 1; i < contatosRegistrados - 1; i++) {
            contatos[i] = contatos[i + 1];
        }
        contatosRegistrados--;
    } else {
        printf("O índice é inválido");
    }
    }
} 

void consultarContatos(Contato contatos[]) {
    char nomeConsultar[30];
    printf("Escreva o nome que você quer consultar: ");
    scanf("%s", &nomeConsultar);
    for (int i = 0; i < contatosRegistrados; i++) {
        if (strncmp(contatos[i].nome, nomeConsultar, strlen(nomeConsultar)) == 0) {
            Contato contatoAchado = contatos[i];
            printf("\n");
            printf("Nome: %s \n", contatoAchado.nome);
            printf("Email: %s \n", contatoAchado.email);
            printf("Telefone: %s \n", contatoAchado.telefone);
            printf("\n");
        } else {
            continue;
        }
    }
    printf("Nenhum contato encontrado com o nome: %s\n", nomeConsultar);
}

int main() {
    int opcao = 0;
    Contato contatos[contatos_maximo];
    printf("---\tPrograma N3 de CRUD de contatos\t---");
    do {
        printf("\n1 - Incluir contato\n2 - Listar contato\n3 - Consultar contato pelo nome\n4 - Excluir contato\n5 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%i", &opcao);
        switch (opcao) {
            case 1:
                incluirContatos(contatos);
            break;
            case 2: 
                listarContatos(contatos);
            break;
            case 3:
                consultarContatos(contatos);
            break;
            case 4:
                excluirContatos(contatos);
            break;
        }
    } while (opcao != 5);
    system("clear");
    printf("Programa encerrado.");
    return 0;
}