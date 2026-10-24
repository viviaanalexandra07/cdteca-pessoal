#include <stdio.h>
#include <string.h>

#define MAX_CDS 50

// Estrutura exigida pelo escopo do projeto
typedef struct {
    int id;
    char titulo[50];
    char artista[50];
    char genero[30];
    int ano;
    int reproducoes;
} CD;

// --- MÓDULO A: Gerenciamento de Acervo (Cadastrar, Listar, Incrementar Reproduções) ---
void cadastrarCD(CD cdteca[], int *quantidade) {
    if (*quantidade >= MAX_CDS) {
        printf("\n[Erro] A CDteca esta cheia!\n");
        return;
    }
    
    printf("\n--- CADASTRAR NOVO CD ---\n");
    cdteca[*quantidade].id = *quantidade + 1; // ID automático
    printf("ID gerado: %d\n", cdteca[*quantidade].id);
    
    printf("Digite o titulo do album: ");
    fflush(stdin);
    fgets(cdteca[*quantidade].titulo, 50, stdin);
    cdteca[*quantidade].titulo[strcspn(cdteca[*quantidade].titulo, "\n")] = '\0';
    
    printf("Digite o nome do artista/banda: ");
    fflush(stdin);
    fgets(cdteca[*quantidade].artista, 50, stdin);
    cdteca[*quantidade].artista[strcspn(cdteca[*quantidade].artista, "\n")] = '\0';
    
    printf("Digite o genero musical (ex: Rock, Pop, MPB): ");
    fflush(stdin);
    fgets(cdteca[*quantidade].genero, 30, stdin);
    cdteca[*quantidade].genero[strcspn(cdteca[*quantidade].genero, "\n")] = '\0';
    
    printf("Digite o ano de lancamento: ");
    scanf("%d", &cdteca[*quantidade].ano);
    
    cdteca[*quantidade].reproducoes = 0; // Inicia zerado
    
    (*quantidade)++;
    printf("\n[Sucesso] CD cadastrado com sucesso!\n");
}

void listarColecao(CD cdteca[], int quantidade) {
    if (quantidade == 0) {
        printf("\n[Aviso] A CDteca esta vazia.\n");
        return;
    }
    
    int i;
    printf("\n--- LISTA DE CDS NA COLECAO ---\n");
    for (i = 0; i < quantidade; i++) {
        printf("ID: %d | Titulo: %s | Artista: %s | Genero: %s | Ano: %d | Reproducoes: %d\n", 
            cdteca[i].id, cdteca[i].titulo, cdteca[i].artista, cdteca[i].genero, cdteca[i].ano, cdteca[i].reproducoes);
    }
    printf("------------------------------------------------------------------\n");
}

void incrementarReproducao(CD cdteca[], int quantidade) {
    if (quantidade == 0) {
        printf("\n[Aviso] Nao ha CDs cadastrados.\n");
        return;
    }
    
    int idBusca;
    int i;
    printf("\n--- REGISTRAR REPRODUCAO ---\n");
    listarColecao(cdteca, quantidade);
    printf("Digite o ID do CD que foi ouvido: ");
    scanf("%d", &idBusca);
    
    for (i = 0; i < quantidade; i++) {
        if (cdteca[i].id == idBusca) {
            cdteca[i].reproducoes++;
            printf("\n[Sucesso] Reproducao registrada! O album \"%s\" agora tem %d reproducoes.\n", 
                cdteca[i].titulo, cdteca[i].reproducoes);
            return;
        }
    }
    printf("\n[Erro] ID nao encontrado.\n");
}

// --- MÓDULO B: Relatórios e Ordenação (Ranking, Filtro por Gênero, Busca) ---
void rankingMaisOuvidos(CD cdteca[], int quantidade) {
    if (quantidade == 0) {
        printf("\n[Aviso] Nao ha CDs cadastrados.\n");
        return;
    }
    
    CD temp[MAX_CDS];
    int i, j;
    for (i = 0; i < quantidade; i++) {
        temp[i] = cdteca[i];
    }
    
    // Ordena do mais ouvido para o menos ouvido (Bubble Sort)
    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - i - 1; j++) {
            if (temp[j].reproducoes < temp[j + 1].reproducoes) {
                CD aux = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = aux;
            }
        }
    }
    
    printf("\n--- RANKING DE MAIS OUVIDOS ---\n");
    for (i = 0; i < quantidade; i++) {
        printf("%do Lugar: %s (%s) - %d reproducoes\n", i + 1, temp[i].titulo, temp[i].artista, temp[i].reproducoes);
    }
    printf("--------------------------------\n");
}

void filtrarPorGenero(CD cdteca[], int quantidade) {
    if (quantidade == 0) {
        printf("\n[Aviso] Nao ha CDs cadastrados.\n");
        return;
    }
    
    char generoBusca[30];
    int i, encontrados = 0;
    
    printf("\n--- FILTRAR POR GENERO MUSICAL ---\n");
    printf("Digite o genero que deseja buscar: ");
    fflush(stdin);
    fgets(generoBusca, 30, stdin);
    generoBusca[strcspn(generoBusca, "\n")] = '\0';
    
    printf("\nResultados para o genero \"%s\":\n", generoBusca);
    for (i = 0; i < quantidade; i++) {
        if (stricmp(cdteca[i].genero, generoBusca) == 0) {
            printf("- %s por %s (%d)\n", cdteca[i].titulo, cdteca[i].artista, cdteca[i].ano);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("Nenhum CD encontrado com este genero.\n");
    }
}

void buscarArtistaOuTitulo(CD cdteca[], int quantidade) {
    if (quantidade == 0) {
        printf("\n[Aviso] Nao ha CDs cadastrados.\n");
        return;
    }
    
    char busca[50];
    int i, encontrados = 0;
    
    printf("\n--- BUSCAR POR ARTISTA OU TITULO ---\n");
    printf("Digite o termo de busca: ");
    fflush(stdin);
    fgets(busca, 50, stdin);
    busca[strcspn(busca, "\n")] = '\0';
    
    printf("\nResultados da busca:\n");
    for (i = 0; i < quantidade; i++) {
        if (stricmp(cdteca[i].titulo, busca) == 0 || stricmp(cdteca[i].artista, busca) == 0) {
            printf("ID: %d | Album: %s | Artista: %s | Genero: %s | Ano: %d | Reproducoes: %d\n", 
                cdteca[i].id, cdteca[i].titulo, cdteca[i].artista, cdteca[i].genero, cdteca[i].ano, cdteca[i].reproducoes);
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("Nenhum resultado encontrado para \"%s\".\n", busca);
    }
}

// --- MÓDULO C: Menu Interativo Principal ---
int main() {
    CD minhaCdteca[MAX_CDS];
    int totalCds = 0;
    int opcao;

    do {
        printf("\n===================================\n");
        printf("     SISTEMA CDTECA PESSOAL        \n");
        printf("===================================\n");
        printf("1. Cadastrar Novo CD\n");
        printf("2. Listar Toda a Colecao\n");
        printf("3. Incrementar Reproducoes (Ouvir CD)\n");
        printf("4. Ver Ranking de Mais Ouvidos\n");
        printf("5. Filtrar por Genero Musical\n");
        printf("6. Buscar por Artista ou Titulo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCD(minhaCdteca, &totalCds);
                break;
            case 2:
                listarColecao(minhaCdteca, totalCds);
                break;
            case 3:
                incrementarReproducao(minhaCdteca, totalCds);
                break;
            case 4:
                rankingMaisOuvidos(minhaCdteca, totalCds);
                break;
            case 5:
                filtrarPorGenero(minhaCdteca, totalCds);
                break;
            case 6:
                buscarArtistaOuTitulo(minhaCdteca, totalCds);
                break;
            case 0:
                printf("\nEncerrando o programa. Bom trabalho no projeto!\n");
                break;
            default:
                printf("\n[Erro] Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
