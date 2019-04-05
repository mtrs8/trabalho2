/*
INSTITUTO FEDERAL DA BAHIA - IFBA
DISCIPLINA: LABORATORIO DE PROGRAMACAO
SEMESTRE: 2
DOCENTE: RENATO NOVAIS
ALUNO: MATHEUS ALVES RODRIGUES
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct posicoes{//Estrutura utilizada
  int *ordenado;
  int *auxiliar;
  int cont;
  int tam;
} ListaPrincipal;

//Chamando as funcoes
int printMenu();
void adicionarElemento();
void removerElemento();
void listarElementos();
void listarOrdenadoGeral();
void listarOrdenadoCada();
void realocarMemoria();

int main(){//Funcao principal
    int i, j, op;
    int sair = 0;
    ListaPrincipal lp[10];

    for(int i=0; i<10; i++){//Inicializando as variaveis e os ponteiros
      lp[i].auxiliar = NULL;
      lp[i].ordenado = NULL;
    }
    for(int j=0; j<10; j++){
      lp[j].cont = 0;
    }
    for(int k=0; k<10; k++){
      lp[k].tam = 0;
    }
    while (!sair){
        op = printMenu();//Funcao Menu
        switch (op){
                case 0:{ //Sair
                //TODO
                sair = 1;
                printf("Encerrando programa...");
                break;
            }
            case 1:{ //inserir
                //TODO
                adicionarElemento(&lp);
              break;
            }
            case 2:{ //excluir
                //TODO
                removerElemento(&lp);
                break;
            }
            case 3:{ //Listar
              //TODO
              listarElementos(&lp);
              break;
            }
            case 4:{ //Listar ordenado
              //TODO
              listarOrdenadoGeral(&lp);
              break;
            }
            case 5:{ //Listar mostrando onde se encontra cada elemento
              //TODO
              listarOrdenadoCada(&lp);
              break;
            }
            case 6:{ //Aumentar tamanho de estrutura auxiliar
              //TODO
              realocarMemoria(&lp);
              break;
            }
            default:{ //Caso nenhuma opcao seja valida, mostra novamente o menu
                printf("Opcao inválida, tente novamente ...\n");
                break;
            }

        }

    }
    for(i=0; i<10; i++){
      free(lp[i].auxiliar);
  }

    return 0;
}

int printMenu(){//Funcao menu
    int op;
      /*#ifdef __MINGW32__
        system("cls");
      #endif
      #ifdef __linux__
        system("clear");
      #endif
      */
      printf("\nTRABALHO 2 - MENU");
      printf("\n0 - Sair");
      printf("\n1 - Inserir");
      printf("\n2 - Excluir");
      printf("\n3 - Listar elementos de todas as estruturas");
      printf("\n4 - Listar elementos ordenados");
      printf("\n5 - Listar ordenado mostrando cada estrutura");
      printf("\n6 - Aumentar estrutura auxiliar");
      printf("\n\nDigite a opcao desejada: ");
      scanf("%d", &op);
      printf("\n");
    return op;
}

void adicionarElemento(ListaPrincipal v[]){//Funcao Inserir
  int tam, aux, aumentar, i, pos, num;
  printf("Digite a posicao da estrutura principal para inserir [0 a 9]:\n");
  scanf("%d", &pos);
  if((pos >= 0) && (pos <= 9)){
    if(v[pos].cont == 0){
      printf("Digite o tamanho da estrutura auxiliar:\n");
      scanf("%d", &tam);
      v[pos].tam = tam;
      v[pos].auxiliar = (int*)malloc(tam*sizeof(int));
      v[pos].ordenado = (int*)malloc(tam*sizeof(int));
    }
    if(v[pos].cont == v[pos].tam){
      printf("Estrutura auxiliar cheia, por favor, remova um elemento (Op = 2) ou adicione mais memoria(Op = 6) !!\n");
    }
    else{
      printf("Digite valor: ");
      scanf("%d", &aumentar);
      aux = v[pos].cont;
      v[pos].auxiliar[aux] = aumentar;
      v[pos].cont = v[pos].cont + 1;
    }
  }
  else {
    printf("A Estrutura tem apenas 10 posicoes[0 a 9]!!\n\n");
  }
}

void removerElemento(ListaPrincipal v[]){//Funcao Remover
  int pos, aumentar, indice, trocas=0, aux;
  printf("Digite a posicao de busca do vetor principal:\n");
  scanf("%d", &pos);
  if((pos>=0)&&(pos<=9)){
    if(v[pos].tam > 0){
      printf("Digite numero para exclusao:\n");
      scanf("%d", &aumentar);
      for(indice=0; indice < v[pos].cont; indice++){
        if(v[pos].auxiliar[indice] == aumentar){
        printf("Removido...\n");
        v[pos].auxiliar[indice] = 0;
        trocas += 1;
        break;
      }
    }
      if(trocas>0){
        for(indice=0; indice<v[pos].cont; indice++){
          if(v[pos].auxiliar[indice] == 0){
            v[pos].auxiliar[indice] = v[pos].auxiliar[indice+1];
            v[pos].auxiliar[indice+1] = 0;
          }
        }
      }
      else{
        printf("Elemento não encontrado...\n");
      }
    }
    else{
      printf("Não existe estrutura auxiliar criada nessa posicao...\n");
    }
  }
  else{
    printf("Posicao inexistente na estrutura ...\n");
  }
}

void listarElementos(ListaPrincipal v[]){//Funcao Listar
  int i, j;
  for(i = 0; i < 10; i++){
    for(j = 0; j < v[i].cont; j++){
        printf("Estrutura %d: Elemento %d = %d\n", i, j, v[i].auxiliar[j]);
    }
  }
}

void listarOrdenadoGeral(ListaPrincipal *v){//Funcao Listar todos os numeros ordenados
 int i, j, k, atual, *ordenar, contador=0, cont2=0;

 for(i=0; i<10; i++){
   contador = contador + v[i].cont; //Encontrando total a ser alocado
 }

 if(contador>0)
  ordenar = (int*) malloc(contador*sizeof(int));//Alocando Valores

 for(i=0; i<10; i++){ //Passando os valores para vetorzao
  for(j=0; j<v[i].cont; j++){
    if(v[i].auxiliar != NULL){
      ordenar[cont2] = v[i].auxiliar[j];
      cont2++;
    }
  }
}

   //Insertion
   for(j=1; j<cont2; j++){
     atual = ordenar[j];
     for(k=j-1; (k>=0) && (atual < ordenar[k]); k--){
       ordenar[k+1] = ordenar[k];
     }
     ordenar[k+1] = atual;
    }

  printf("\nElementos ordenados: ");
  for(i = 0; i < cont2; i++){
        printf(" %d ",ordenar[i]);
  }

printf("\n");
}

void listarOrdenadoCada(ListaPrincipal v[]){ //Funcao Ordenar cada estrutura
  ListaPrincipal lp[10];
  int i, x, y, z, j, aux;

  for(x = 0; x < 10; x++){
    lp[x].auxiliar = (int*)malloc(v[x].tam*sizeof(int));
  }

  for(x=0; x<10; x++){
    if(v[x].tam != 0){ // Se a estrutura auxiliar não tiver sido iniciada não é feita a passagem de valores.
      for(y=0; y<v[x].tam; y++){
        lp[x].auxiliar[y] = v[x].auxiliar[y];
      }
    }
  }

  for(z = 0; z < 10; z++){
    if(v[z].tam != 0){ //Apenas ordena as estruturas inicializadas.
      for(x = 0; x < v[z].tam; x++ ){
        for(y = x+1; y < v[z].tam; y++){
          if (lp[z].auxiliar[x] > lp[z].auxiliar[y]){
           aux = lp[z].auxiliar[x];
           lp[z].auxiliar[x] = lp[z].auxiliar[y];
           lp[z].auxiliar[y] = aux;
          }
        }
      }
    }
  }

  for(i = 0; i < 10; i++){
    for(j = 0; j < v[i].tam; j++){
        printf("Estrutura %d: Elemento %d = %d\n", i, j, v[i].auxiliar[j]);
    }
  }
}

void realocarMemoria(ListaPrincipal v[]){//Funcao aumentar memoria
  int aumentar, pos;
  printf("Digite a posicao para realocar[0 a 9]:\n");
  scanf("%d", &pos);
  if((pos>=0)&&(pos<=9)){//Verifica se a posicao eh valida
      printf("Digite quantas posicoes voce quer aumentar:\n");
      scanf("%d", &aumentar);
        if(aumentar>0){//Verifica se o valor a ser realocado eh positivo
          aumentar = aumentar + v[pos].tam;
          v[pos].auxiliar = (int*) realloc (v[pos].auxiliar, aumentar*sizeof(int));
          v[pos].ordenado = (int*) realloc (v[pos].ordenado, aumentar*sizeof(int));
          v[pos].tam = v[pos].tam + 1;
          printf("Aumento de estrutura auxiliar feito com sucesso!!!");
      }
      else{
         printf("Nao eh possível realocar valores negativos...");
      }
  }
  else {
    printf("Nao existe esta posicao...");
  }
}
