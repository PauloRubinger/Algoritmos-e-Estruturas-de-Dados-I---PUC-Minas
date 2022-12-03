#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int m, int n) {
	
	int **v; 
	int i; 
	if (m < 1 || n < 1) { 
		printf("** Erro: Parametro invalido **\n");
		return (NULL);
	}

	v = (int**) calloc(m, sizeof(int*));
	if (v == NULL) {
		printf("** Erro: Memoria Insuficiente **");
		return (NULL);
	}

	for (i = 0; i < m; i++) {
		v[i] = (int*) calloc(n, sizeof(int));
		if (v[i] == NULL) {
			printf("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}
	return (v); 
}

void leAlturaLarguraMaxColor(char *file, int *largura, int *altura, int *maxColor) {
	
	FILE *arq;
	char linha[100];
	arq = fopen(file, "rt");
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}

	fgets(linha, 100, arq);	// Lê a primeira linha do arquivo de imagem
	printf("%s", linha); 	// Imprime a primeira linha do arquivo de imagem (apenas para verificação)
	fgets(linha, 100, arq);	// Lê a segunda linha do arquivo de imagem
	printf("%s", linha); 	// Imprime a segunda linha do arquivo de imagem (apenas para verificação)

	fscanf(arq, "%d", largura);
	fscanf(arq, "%d", altura);
	fscanf(arq, "%d", maxColor);
	
	fclose(arq);
}


void leMatriz(char *file, int altura, int largura, int **img) {
	
	FILE *arq;
	char linha[100];
	int pixel;
	arq = fopen(file, "rt");
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}
	fgets(linha, 100, arq); // Lê a primeira linha do arquivo de imagem
	printf("\n%s", linha); 	// Imprime a primeira linha do arquivo de imagem (apenas para verificação)
	fgets(linha, 100, arq); // Lê a segunda linha do arquivo de imagem
	printf("%s", linha);  	// Imprime a segunda linha do arquivo de imagem (apenas para verificação)
	fgets(linha, 100, arq); // Lê a terceira linha do arquivo de imagem
	printf("%s", linha);  	// Imprime a terceira linha do arquivo de imagem (apenas para verificação)
	fgets(linha, 100, arq); // Lê a quarta linha do arquivo de imagem
	printf("%s", linha);  	// Imprime a quarta linha do arquivo de imagem (apenas para verificação)

	// Lidas as quatro primeiras linhas do arquivo, podemos agora ler a matriz que forma a imagem, que começa na linha 5
	/* A estrutura de repetição abaixo irá ler cada elemento da matriz e colocá-lo na variável "pixel" e, após isso,
	 atribuir esse valor para cada elemento da matriz "img". Cada valor da matriz representa um pixel */
	for (int i = 0; i < altura; i++) { // Percorre as linhas da matriz (altura da imagem)
		for (int j = 0; j < largura; j++) { // Percorre as colunas da matriz (largura da imagem)
			fscanf(arq, "%d", &pixel); // Lê o elemento e coloca na variável "pixel"
			img[i][j] = pixel;	// Atribui o valor da variável pixel ao elemento img[i][j]
		}
	}

	fclose(arq);	// Fecha o arquivo
}

void gerarFigura(char *destino, char *tipo, int altura, int largura, int maxColor, int **img) {

	FILE *arq;
	arq = fopen(destino, "wt");
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}

	fprintf(arq, "%s\n", tipo);
	fprintf(arq,"%d %d\n", largura, altura);
	fprintf(arq, "%d\n", maxColor);

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			fprintf(arq, "%d ", img[i][j]);
		}
		fprintf(arq, "\n");
	}

	fclose(arq);
}

void imprimir_matriz(int largura, int altura, int **img) {

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			printf("%d ", img[i][j]);
		}
		printf("\n");
	}

}

void geraTons(int altura, int largura, int **img, int **imgDestino, float reducao) {

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			imgDestino[i][j] = (int)(img[i][j]*reducao);
		}
	}

}

/* Rotação 180 graus normal da matriz

1	2	3		7	8	9
4	5	6	=>	4	5	6
7	8	9		1	2	3

*/

void gira180Normal(int altura, int largura, int **img, int **imgDestino) {

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			imgDestino[i][j] = img[altura - (i + 1)][j];
		}
	}

}

/* Rotação 180 graus espelhado da matriz

1	2	3		7	8	9		9	8	7
4	5	6	=>	4	5	6	=>	6	5	4
7	8	9		1	2	3		3	2	1

*/

void gira180Espelho(int altura, int largura, int **img, int **imgDestino) {
	
	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			imgDestino[i][j] = img[altura - (i + 1)][largura - (j + 1)];
		}
	}

}

/* Rotação 270 graus normal da matriz

1	2	3		1	4	7	
4	5	6	=>	2	5	8	
7	8	9		3	6	9	

*/

void gira270Normal(int altura, int largura, int **img, int **imgDestino) {
	
	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[j][i];
		}
	}

}

/* Rotação 270 graus espelhado da matriz

1	2	3		1	4	7		3	6	9
4	5	6	=>	2	5	8	=>	8	5	2
7	8	9		3	6	9		1	4	7

*/

void gira270Espelho(int altura, int largura, int **img, int **imgDestino) {
	
	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[j][largura - (i + 1)];
		}
	}

}

/* Rotação 90 graus normal da matriz

1	2	3		7	4	1
4	5	6	=>	8	5	2
7	8	9		9	6	3

*/

void gira90Normal(int altura, int largura, int **img, int **imgDestino) {

	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[altura - (j + 1)][i];
		}
	}

}

/* Rotação 90 graus espelhado da matriz

1	2	3		7	4	1		9	6	3
4	5	6	=>	8	5	2	=>	8	5	2
7	8	9		9	6	3		7	4	1

*/

void gira90Espelho(int altura, int largura, int **img, int **imgDestino) {

	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[altura - (j + 1)][largura - (i + 1)];
		}
	}

}

void liberarMatriz(int n, int m, int **v) {

	if (v == NULL)	// Se não houver alocação, a função retorna, pois não tem necessidade de liberar a memória
		return;

	if (m < 1){
		printf("** Erro: Parametro invalido **\n");	// Verifica parâmetros recebidos
		return;
	}

	for (int i = 0; i < m; i++)
		free(v[i]);	// Libera todas as linhas da matriz

	free(v);	// Libera a matriz
}

int main() {

	int largura = 0, altura = 0, maxColor = 0;
	int **img, **img180Normal, **img180Espelho, **img270Normal,**img270Espelho, **img90Normal, **img90Espelho, **imgTons;
	float reducao = 0.25;	// controle tonalidade, sendo que quanto menor o valor, mais escuro (maior a redução)
	char *enderecoArquivo = "imagens/lena.pgm"; // Endereço do arquivo de imagem de entrada

	leAlturaLarguraMaxColor(enderecoArquivo, &largura, &altura, &maxColor);
	printf("\n%d %d %d", largura, altura, maxColor);
	img = alocarMatriz(altura, largura);

	leMatriz(enderecoArquivo, altura, largura, img);
	// imprimir_matriz(altura,largura, img);

	gerarFigura("copiaOriginal.pgm", "P2", altura, largura, maxColor, img);

	int fator = reducao*maxColor; // Nova tonalidade máxima para a imagem que mudará as tonalidades
	printf("%d", fator); // Apenas para verificação do valor do fator
	imgTons = alocarMatriz(altura, largura); // Aloca a matriz que mostrará a imagem com tonalidades diferentes e a coloca na variável "imgTons"
	geraTons(altura, largura, img, imgTons, reducao);
	gerarFigura("saidaTons.pgm", "P2", altura, largura, maxColor, imgTons);

	
	img180Normal = alocarMatriz(altura, largura);
	gira180Normal(altura, largura, img, img180Normal);
	gerarFigura("saida180Normal.pgm", "P2", altura, largura, maxColor,img180Normal);

	
	img180Espelho = alocarMatriz(altura, largura);
	gira180Espelho(altura, largura, img, img180Espelho);
	gerarFigura("saida180Espelho.pgm", "P2", altura, largura, maxColor,img180Espelho);

	
	img270Normal = alocarMatriz(largura, altura);
	gira270Normal(altura, largura, img, img270Normal);
	gerarFigura("saida270Normal.pgm", "P2", largura, altura, maxColor, img270Normal);


	img270Espelho = alocarMatriz(largura, altura);
	gira270Espelho(altura, largura, img, img270Espelho);
	gerarFigura("saida270Espelho.pgm", "P2", largura, altura, maxColor, img270Espelho);

	
	img90Normal = alocarMatriz(largura, altura);
	gira90Normal(altura, largura, img, img90Normal);
	gerarFigura("saida90Normal.pgm", "P2", largura, altura, maxColor, img90Normal);

	
	img90Espelho = alocarMatriz(largura, altura);
	gira90Espelho(altura, largura, img, img90Espelho);
	gerarFigura("saida90Espelho.pgm", "P2", largura, altura, maxColor, img90Espelho);

	// Libera todas as matrizes geradas
	liberarMatriz(largura, altura, img);
	liberarMatriz(largura, altura, img180Normal);
	liberarMatriz(largura, altura, img180Espelho);
	liberarMatriz(largura, altura, img270Normal);
	liberarMatriz(largura, altura, img270Espelho);
	liberarMatriz(largura, altura, img90Normal);
	liberarMatriz(largura, altura, img90Espelho);
	liberarMatriz(largura, altura, imgTons);

	return 0;
}