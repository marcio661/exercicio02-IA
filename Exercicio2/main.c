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

    printf("Sugest�es de filmes:\n");
    for (int i = 0; i < numFilmes; i++) {
        Filme filme = filmes[i];
        if (strcmp(filme.tema, tema) == 0 && strcmp(filme.orcamento, orcamento) == 0) {
            if ((strcmp(filme.categoria, "A��o") == 0 && filme.classificacao >= classificacaoAcao) ||
                (strcmp(filme.categoria, "Com�dia") == 0 && filme.classificacao >= classificacaoComedia) ||
                (strcmp(filme.categoria, "Romance") == 0 && filme.classificacao >= classificacaoRomance)) {
                printf("- %s\n", filme.titulo);
                encontrouRecomendacao = true;
            }
        }
    }

    if (!encontrouRecomendacao) {
        printf("Nenhuma sugest�o de filme encontrada para as prefer�ncias fornecidas.\n");
    }
}

int main() {
setlocale(LC_ALL, ".1252");

    adicionarFilme("Filme A", 0.8, "A��o", "Medieval", "Indie");
    adicionarFilme("Filme B", 0.6, "Com�dia", "Sci-Fi", "Triple A");
    adicionarFilme("Filme C", 0.9, "Romance", "World War", "Indie");
    adicionarFilme("Filme D", 0.7, "A��o", "Sci-Fi", "Indie");
    adicionarFilme("Filme E", 0.5, "Com�dia", "Medieval", "Triple A");
    adicionarFilme("Filme F", 0.8, "Romance", "World War", "Triple A");
    adicionarFilme("Filme G", 0.6, "A��o", "Sci-Fi", "Triple A");
    adicionarFilme("Filme H", 0.9, "Com�dia", "Medieval", "Indie");

    float classificacaoAcao, classificacaoComedia, classificacaoRomance;
    char tema[20], orcamento[20];

    printf("Classifique sua prefer�ncia para filmes de A��o (0 a 1): ");
    scanf("%f", &classificacaoAcao);
    printf("Classifique sua prefer�ncia para filmes de Com�dia (0 a 1): ");
    scanf("%f", &classificacaoComedia);
    printf("Classifique sua prefer�ncia para filmes de Romance (0 a 1): ");
    scanf("%f", &classificacaoRomance);
    printf("Informe a tem�tica desejada (Medieval, Sci-Fi, World War): ");
    scanf("%s", tema);
    printf("Informe a classifica��o de or�amento desejada (Indie, Triple A): ");
    scanf("%s", orcamento);

    recomendarFilmes(classificacaoAcao, classificacaoComedia, classificacaoRomance, tema, orcamento);

    return 0;
}
