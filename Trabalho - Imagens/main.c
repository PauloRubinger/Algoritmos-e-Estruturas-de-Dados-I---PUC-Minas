#include <stdio.h>
#include <stdlib.h>

// Função para alocação dinâmica das matrizes usadas durante o programa
int** alocarMatriz(int m, int n) {
	
	int **v; // Matriz
	int i; // Variável auxiliar
	
	// Teste para ver se os parâmetros (linhas, colunas) são válidos
	if (m < 1 || n < 1) { 
		printf("** Erro: Parametro invalido **\n");
		return (NULL);
	}

	v = (int**) calloc(m, sizeof(int*)); // Aloca um ponteiro para as linhas da matriz
	// Teste para descobrir se a alocação foi bem-sucedida
	if (v == NULL) {
		printf("** Erro: Memoria Insuficiente **");
		return (NULL);
	}

	// Aloca um vetor de ponteiros (que serão as colunas) para cada linha da matriz
	for (i = 0; i < m; i++) {
		v[i] = (int*) calloc(n, sizeof(int));
		// Teste para descobrir se a alocação foi bem-sucedida
		if (v[i] == NULL) {
			printf("** Erro: Memoria Insuficiente **");
			return (NULL);
		}
	}
	return (v); // Retorna a matriz alocada
}

// Função para ler os dados da imagem (largura, altura, tonalidade máxima)
void leAlturaLarguraMaxColor(char *file, int *largura, int *altura, int *maxColor) {
	
	FILE *arq;
	char linha[100];		 // Variável para ler as linhas
	arq = fopen(file, "rt"); // Abre o arquivo no modo leitura
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");	// Avisa se o arquivo não pôde ser aberto
		exit(0);										// Fecha o programa se o arquivo não puder ser lido
	}

	fgets(linha, 100, arq);	// Lê a primeira linha do arquivo de imagem
	printf("%s", linha); 	// Imprime a primeira linha do arquivo de imagem (apenas para verificação)
	fgets(linha, 100, arq);	// Lê a segunda linha do arquivo de imagem
	printf("%s", linha); 	// Imprime a segunda linha do arquivo de imagem (apenas para verificação)

	// As próximas linhas após as duas primeiras mostram a largura, altura e tonalidade máxima da imagem
	fscanf(arq, "%d", largura);	// Lê a largura da imagem
	fscanf(arq, "%d", altura);	// Lê a altura da imagem
	fscanf(arq, "%d", maxColor); // Lê a tonalidade máxima
	
	fclose(arq);	// Fecha o arquivo
}

// Função para ler os dados do arquivo de imagem
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

// Função para gerar (criar) o arquivo da imagem
void gerarFigura(char *destino, char *tipo, int altura, int largura, int maxColor, int **img) {

	FILE *arq;
	arq = fopen(destino, "wt");	// Cria um arquivo se não existir e o abre no modo escrita
	if (arq == NULL) {
		printf("Problemas na abertura do arquivo\n");
		exit(0);
	}

	fprintf(arq, "%s\n", tipo);	// Imprime o "identificador mágico" no arquivo
	fprintf(arq,"%d %d\n", largura, altura); // Imprime a largura e a altura no arquivo
	fprintf(arq, "%d\n", maxColor);	// Imprime a tonalidade máxima no arquivo

	for (int i = 0; i < altura; i++){	// Percorre todos os elementos (pixels) da altura da figura
		for (int j = 0; j < largura; j++){	// Percorre todos os elementos (pixels) da largura da figura
			fprintf(arq, "%d ", img[i][j]);	// Imprime os elementos da matriz no arquivo
		}
		fprintf(arq, "\n");	// Solta uma linha após preencher as colunas para ficar no formato de matriz
	}

	fclose(arq);	// Fecha o arquivo
}

// Função para imprimir a matriz na tela (apenas para verificação)
void imprimir_matriz(int largura, int altura, int **img) {

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){	
			printf("%d ", img[i][j]);		// Imprime os elementos da matriz na tela
		}
		printf("\n");	// Solta uma linha após preencher as colunas para ficar no formato de matriz
	}

}

// Função para gerar as mudanças na tonalidade
void geraTons(int altura, int largura, int **img, int **imgDestino, float reducao) { // "img" é a matriz original, "imgDestino" é a nova matriz gerada e "reducao" é o fator de redução da tonalidade máxima

	for (int i = 0; i < altura; i++){	// Percorre todos os elementos (pixels) da altura da figura
		for (int j = 0; j < largura; j++){	// Percorre todos os elementos (pixels) da largura da figura
			imgDestino[i][j] = (int)(img[i][j]*reducao);	// Multiplica as tonalidades pelo fator de redução
		}
	}

}

/* Rotação 180 graus normal da matriz

1	2	3		7	8	9
4	5	6	=>	4	5	6
7	8	9		1	2	3

*/

// Função para girar a figura em 180 graus normal
void gira180Normal(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada

	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			imgDestino[i][j] = img[altura - (i + 1)][j]; // Troca a primeira linha com a última, a segunda com a penúltima e assim por diante
		}
	}

}

/* Rotação 180 graus espelhado da matriz

1	2	3		7	8	9		9	8	7
4	5	6	=>	4	5	6	=>	6	5	4
7	8	9		1	2	3		3	2	1

*/

// Função para girar a figura em 180 graus e espelhar a imagem
void gira180Espelho(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada
	
	for (int i = 0; i < altura; i++){
		for (int j = 0; j < largura; j++){
			imgDestino[i][j] = img[altura - (i + 1)][largura - (j + 1)]; // Troca a primeira linha com a última, a segunda com a penúltima e assim por diante, e também inverte direita com esquerda
		}
	}

}

/* Rotação 270 graus normal da matriz

1	2	3		1	4	7	
4	5	6	=>	2	5	8	
7	8	9		3	6	9	

*/

// Função que gira a figura em 270 graus normal
void gira270Normal(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada
	
	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[j][i];	// Troca as linhas pelas colunas
		}
	}

}

/* Rotação 270 graus espelhado da matriz

1	2	3		1	4	7		3	6	9
4	5	6	=>	2	5	8	=>	8	5	2
7	8	9		3	6	9		1	4	7

*/

// Função para girar a figura em 270 graus e espelhar a imagem
void gira270Espelho(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada
	
	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[j][largura - (i + 1)];	// Troca as linhas pelas colunas e espelha as linhas para que a primeira seja a última, a segunda a penúltima e assim por diante
		}
	}

}

/* Rotação 90 graus normal da matriz

1	2	3		7	4	1
4	5	6	=>	8	5	2
7	8	9		9	6	3

*/

// Função para girar a figura em 90 graus normal
void gira90Normal(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada

	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[altura - (j + 1)][i]; // A primeira linha passa a ser a última coluna, a segunda linha passa a ser a penúltima coluna e assim por diante
		}
	}

}

/* Rotação 90 graus espelhado da matriz

1	2	3		7	4	1		9	6	3
4	5	6	=>	8	5	2	=>	8	5	2
7	8	9		9	6	3		7	4	1

*/

// Função para girar a figura em 90 graus e espelhar a imagem
void gira90Espelho(int altura, int largura, int **img, int **imgDestino) { // "img" é a matriz original e "imgDestino" a nova matriz gerada

	for (int i = 0; i < largura; i++){
		for (int j = 0; j < altura; j++){
			imgDestino[i][j] = img[altura - (j + 1)][largura - (i + 1)]; // A primeira linha passa a ser a última coluna, a segunda linha passa a ser a penúltima coluna e assim por diante, porém espelha-se as linhas para que a primeira seja a última e vice-versa
		}
	}

}

// Função para liberar a memória alocada para as matrizes
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

	int largura = 0, altura = 0, maxColor = 0; // Inicializa as variáveis largura, altura e tonalidade máxima da imagem
	int **img, **img180Normal, **img180Espelho, **img270Normal,**img270Espelho, **img90Normal, **img90Espelho, **imgTons; // Declara os ponteiros para armazenarem as matrizes que retornarão das funções por parâmetro
	float reducao = 0.25;	// Controle de tonalidade, sendo que quanto menor o valor, mais escuro (maior a redução)
	char *enderecoArquivo = "imagens/lena.pgm"; // Endereço do arquivo de imagem de entrada

	leAlturaLarguraMaxColor(enderecoArquivo, &largura, &altura, &maxColor); // Função para ler do arquivo as informações da imagem (largura, altura, tonalidade máxima)
	printf("\n%d %d %d", largura, altura, maxColor); // Impressão dos dados acima (apenas para verificação)
	img = alocarMatriz(altura, largura); // Aloca a matriz que conterá a imagem original e coloca em "img"

	leMatriz(enderecoArquivo, altura, largura, img); // Lê a matriz de dentro do arquivo e coloca os pixels em "img"
	// imprimir_matriz(altura,largura, img);

	gerarFigura("copiaOriginal.pgm", "P2", altura, largura, maxColor, img); // Gera uma cópia original do arquivo de imagem por meio da matriz lida

	int fator = reducao*maxColor; // Nova tonalidade máxima para a imagem que mudará as tonalidades
	printf("%d", fator); // Apenas para verificação do valor do fator
	imgTons = alocarMatriz(altura, largura); // Aloca a matriz que mostrará a imagem com tonalidades diferentes e a coloca na variável "imgTons"
	geraTons(altura, largura, img, imgTons, reducao); // Função que gera as diferentes tonalidades da imagem
	gerarFigura("saidaTons.pgm", "P2", altura, largura, maxColor, imgTons); // Função que gera o arquivo de imagem com a tonalidade diferente


	img180Normal = alocarMatriz(altura, largura); // Aloca a matriz que irá conter a imagem girada em 180 graus normal
	gira180Normal(altura, largura, img, img180Normal); // Chama a função que girará a matriz em 180 graus normal
	gerarFigura("saida180Normal.pgm", "P2", altura, largura, maxColor,img180Normal); // Chama a função que gerará o arquivo com a imagem girada em 180 graus normal

	
	img180Espelho = alocarMatriz(altura, largura); // Aloca a matriz que irá conter a imagem girada em 180 graus e espelhada
	gira180Espelho(altura, largura, img, img180Espelho); // Chama a função que irá girar e espelhar a matriz em 180 graus
	gerarFigura("saida180Espelho.pgm", "P2", altura, largura, maxColor,img180Espelho); // Chama a função que gerará o arquivo com a imagem girada em 180 graus espelhada

	
	img270Normal = alocarMatriz(largura, altura); // Aloca a matriz que irá conter a imagem girada em 270 graus normal
	gira270Normal(altura, largura, img, img270Normal); // Chama a função que irá girar a matriz em 270 graus normal
	gerarFigura("saida270Normal.pgm", "P2", largura, altura, maxColor, img270Normal); // Chama a função que irá gerar o arquivo com a imagem alterada


	img270Espelho = alocarMatriz(largura, altura); // Aloca a matriz que irá conter a imagem girada em 270 graus e espelhada
	gira270Espelho(altura, largura, img, img270Espelho); // Chama a função que irá girar e espelhar a matriz em 270 graus
	gerarFigura("saida270Espelho.pgm", "P2", largura, altura, maxColor, img270Espelho); // Chama a função que irá gerar o arquivo com a imagem alterada

	
	img90Normal = alocarMatriz(largura, altura); // Aloca a matriz que irá conter a imagem girada em 90 graus normal
	gira90Normal(altura, largura, img, img90Normal); // Chama a função que irá girar a matriz em 90 graus normal
	gerarFigura("saida90Normal.pgm", "P2", largura, altura, maxColor, img90Normal); // Chama a função que irá gerar o arquivo com a imagem alterada

	
	img90Espelho = alocarMatriz(largura, altura); // Aloca a matriz que irá conter a imagem girada e espelhada e 90 graus
	gira90Espelho(altura, largura, img, img90Espelho); // Chama a função que irá girar e espelhar a imagem em 90 graus
	gerarFigura("saida90Espelho.pgm", "P2", largura, altura, maxColor, img90Espelho); // Chama a função que irá gerar o arquivo com a imagem alterada

	// Libera toda a memória alocada para as matrizes geradas
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
