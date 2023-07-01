#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//Marcio Luis Cipriano De Souza
#define MAX_FILMS 10
#include <locale.h>
typedef struct {

    char titulo[50];
    float classificacao;
    char categoria[20];
    char tema[20];
    char orcamento[20];
} Filme;

Filme filmes[MAX_FILMS];
int numFilmes = 0;

void adicionarFilme(char titulo[50], float classificacao, char categoria[20], char tema[20], char orcamento[20]) {
    Filme filme;
    strcpy(filme.titulo, titulo);
    filme.classificacao = classificacao;
    strcpy(filme.categoria, categoria);
    strcpy(filme.tema, tema);
    strcpy(filme.orcamento, orcamento);
    filmes[numFilmes++] = filme;
}

void recomendarFilmes(float classificacaoAcao, float classificacaoComedia, float classificacaoRomance, char tema[20], char orcamento[20]) {
    bool encontrouRecomendacao = false;

    printf("Sugestões de filmes:\n");
    for (int i = 0; i < numFilmes; i++) {
        Filme filme = filmes[i];
        if (strcmp(filme.tema, tema) == 0 && strcmp(filme.orcamento, orcamento) == 0) {
            if ((strcmp(filme.categoria, "Ação") == 0 && filme.classificacao >= classificacaoAcao) ||
                (strcmp(filme.categoria, "Comédia") == 0 && filme.classificacao >= classificacaoComedia) ||
                (strcmp(filme.categoria, "Romance") == 0 && filme.classificacao >= classificacaoRomance)) {
                printf("- %s\n", filme.titulo);
                encontrouRecomendacao = true;
            }
        }
    }

    if (!encontrouRecomendacao) {
        printf("Nenhuma sugestão de filme encontrada para as preferências fornecidas.\n");
    }
}

int main() {
setlocale(LC_ALL, ".1252");

    adicionarFilme("Filme A", 0.8, "Ação", "Medieval", "Indie");
    adicionarFilme("Filme B", 0.6, "Comédia", "Sci-Fi", "Triple A");
    adicionarFilme("Filme C", 0.9, "Romance", "World War", "Indie");
    adicionarFilme("Filme D", 0.7, "Ação", "Sci-Fi", "Indie");
    adicionarFilme("Filme E", 0.5, "Comédia", "Medieval", "Triple A");
    adicionarFilme("Filme F", 0.8, "Romance", "World War", "Triple A");
    adicionarFilme("Filme G", 0.6, "Ação", "Sci-Fi", "Triple A");
    adicionarFilme("Filme H", 0.9, "Comédia", "Medieval", "Indie");

    float classificacaoAcao, classificacaoComedia, classificacaoRomance;
    char tema[20], orcamento[20];

    printf("Classifique sua preferência para filmes de Ação (0 a 1): ");
    scanf("%f", &classificacaoAcao);
    printf("Classifique sua preferência para filmes de Comédia (0 a 1): ");
    scanf("%f", &classificacaoComedia);
    printf("Classifique sua preferência para filmes de Romance (0 a 1): ");
    scanf("%f", &classificacaoRomance);
    printf("Informe a temática desejada (Medieval, Sci-Fi, World War): ");
    scanf("%s", tema);
    printf("Informe a classificação de orçamento desejada (Indie, Triple A): ");
    scanf("%s", orcamento);

    recomendarFilmes(classificacaoAcao, classificacaoComedia, classificacaoRomance, tema, orcamento);

    return 0;
}
