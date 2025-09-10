#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// **************************************************************************
int *numbers_create(int size); // aloca os espaços para um tamanho fixo
void numbers_read(int *numbers,
                  int size); // ler todos os valores para os espaços
float numbers_average(int *numbers,
                      int size);           // calcula a média e retorna o valor
void numbers_show(int *numbers, int size); // exibe os valores alocados
void numbers_destroy(int *numbers);        // desaloca a variável alocada

//novas funções 
int numbers_maior(int *numbers, int size); // identifica o maior número da sequência
int numbers_menor(int *numbers, int size); // identifica o menor número da sequência
void numbers_pares(int *numbers, int size); //identifica os números pares
void numbers_impares(int *numbers, int size); // identifica os números ímpares
int numbers_maior_limite(int *numbers, int size, int limit); //identifica os números maiores que um limite informado, neste caso >=30

// **************************************************************************


// ***************************** Implementação ******************************

int *numbers_create(int size) {
  int *num = NULL;
  num = (int *)malloc(size * sizeof(int));
  if (num == NULL)
    return NULL;
  return num;
}

void numbers_read(int *numbers, int size) {
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      numbers[i] = rand() % 50;
  }
}

float numbers_average(int *numbers, int size) {
  float sum = 0.0;
  if (numbers != NULL)
    for (int i = 0; i < size; i++)
      sum += numbers[i];
  if (sum != 0)
    return sum / (float)size;
  return 0;
}

void numbers_show(int *numbers, int size) {
  printf("[");
  if (numbers != NULL) {
    for (int i = 0; i < size; i++)
      if (i == (size - 1))
        printf("%d", numbers[i]);
      else
        printf("%d, ", numbers[i]);
  }
  printf("]\n");
}

void numbers_destroy(int *numbers) { free(numbers); }

// *************************************************************************
int numbers_maior(int *numbers, int size){
  int maior = numbers[0];
  for(int i = 1; i <size; i++){
    if (numbers[i] > maior)
    maior = numbers[i];
  }
  return maior;
}

int numbers_menor(int *numbers, int size){
  int menor = numbers[0];
  for(int i = 1; i < size; i++){
    if(numbers[i] < menor)
    menor = numbers[i];
  }
  return menor;
}

void numbers_pares(int *numbers, int size){
      printf("Pares: ");
      for (int i = 0; i < size; i++){
        if( numbers[i] % 2 == 0)
        printf("%d ",numbers[i]);
      }
      printf("\n");
}

void numbers_impares(int *numbers, int size){
      printf("Ímpares: ");
      for(int i = 0; i < size; i++){
        if(numbers[i] % 2 != 0)
        printf("%d ", numbers[i]);
      }
      printf("\n");
}

int numbers_maior_limite(int *numbers, int size, int limit) {
  int cont = 0;
  for(int i = 0; i < size; i++){
    if (numbers[i] >limit)
     cont++;
  }
  return cont;
}

int main() {
  srand(time(NULL));
  int *numbers; 
  int size=rand() % 100; 
  numbers = numbers_create(size);
  numbers_read(numbers, size);

  float avg = numbers_average(numbers, size); 

  printf("Conjunto de números:\n");
  numbers_show (numbers,size);

  printf("Média = %.2f\n", avg);
  printf("Maior número = %d\n", numbers_maior(numbers, size));
  printf("Menor número = %d\n", numbers_menor(numbers, size));
  
  numbers_pares(numbers, size);
  numbers_impares(numbers, size);

  int limite = 30;
  printf("Quantidade de números maiores que %d = %d\n", limite,
    numbers_maior_limite(numbers, size, limite));

  numbers_destroy(numbers);
  return 0;
}