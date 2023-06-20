#ifndef fila_h
#define fila_h
//mostra o menu
int menu(int opc);
// scruct da fila com top e vet
typedef struct fila *Fila;
// cria a fila com o tamanho do vetor inserido pelo usuario
Fila criarFila();
// imprime a fila na tela
void imprimirFila(Fila f);
// insere um numero e retorna a fila modificada
Fila inserirFila(Fila f);
// remove um numero e retorna a fila modificada
Fila removerFila(Fila f);
// libera a fila e retorna NULL
void liberarFila(Fila f);
// limpa a tela
void limpaTela();

#endif