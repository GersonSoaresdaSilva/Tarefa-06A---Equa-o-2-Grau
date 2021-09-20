/*Equação do 2Grau - Tarefa 06 - Argumentos como Ponteiros
 ax^2 + bx + c = 0       Δ = b^2 - 4ac
 Δ > 0; 2 raízes reais diferentes
 Δ < 0; 2 raízes reais iguais
 Δ = 0 não admite solução real*/

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double aX, bX, c, deltaX, x1, x2;

double lerAx (double *ptrAx);
double lerBx (double *ptrBx);
double lerC (double *ptrC);
double delta (double *ptrAx, double *ptrBx, double *ptrC);
double vlX1 (double *ptrAx, double *ptrBx, double *ptrDeltaX);
double vlX2 (double *ptrAX, double *ptrBx, double *ptrDeltaX);
void lerValores ();
void calcular ();
void exibir ();
void controle ();

int main () {
  setlocale(LC_ALL, "Portuguese");
  system ("clear");
  controle (); 
  return 0;
}

double lerAx (double *ptrAx) {
  cout << "\nInforme o valor de A.: ";
  cin >> aX;
  if (aX == 0) {
    cout << "O coeficiente não pode ser '0'." << endl;
    lerAx (&aX);    
  }
  return aX;
}

double lerBx (double *ptrbX) {
  cout << "Informe o valor de B.: ";
  cin >> bX;
  return bX;
}

double lerC (double *ptrC) {
  cout << "Informe o valor de C.: ";
  cin >> c;
  return c;
}

double delta (double *ptraX, double *ptrbX, double *ptrc) {
  double vDelta;
  vDelta = pow (*ptrbX, 2) - 4 * (*ptraX) * (*ptrc);
  return vDelta;
}

double vlX1 (double *ptraX, double *ptrbX, double *ptrdeltaX){
  double x1vlr;
  x1vlr = (- *ptrbX + sqrt(*ptrdeltaX)) / 2 * aX;
  return x1vlr;
}

double vlX2 (double *ptraX, double *ptrbX, double *ptrdeltaX) {
  double x2vlr;
  x2vlr = (- *ptrbX - sqrt(*ptrdeltaX)) / 2 * aX;
  return x2vlr;
}

void lerValores (){
  system ("clear");
  cout << "\n***  Calcular Equação do 2º Grau  ***" << endl;
  lerAx (&aX);
  lerBx (&bX);
  lerC  (&c);
  system ("sleep 4");
}

void calcular () {
  deltaX = delta (&aX, &bX, &c);
  x1 = vlX1 (&aX, &bX, &deltaX);
  x2 = vlX2 (&aX, &bX, &deltaX);
  system ("clear");
  cout << "\nCálculo realizado com Sucesso!" << endl;
  system ("sleep 4");
}

void exibir () {
  system ("clear");
  if (aX == 0) {
    cout << "Não há valores à exibir.";
    system ("sleep 4");
  }
  else { 
    cout << "\n*** Exibir Resultados  ***" << endl;
    cout << "\nValor de delta.: " << deltaX << endl;
    cout << "Valor de x'    : " << x1 << endl;
    cout << "Valor de x''   : " << x2 << endl;
  system ("sleep 4");
  }
  
}

void controle (){
  int optItem;
  while (true) {
    system ("clear");
    cout << "\n***  Menu de Controle  ***" << endl;
    cout << "\n1 - Ler Valores \n2 - Calcular \n3 - Exibir \n4 - Sair" << endl;
    cout << "Opção.: ";
    cin >> optItem;
    switch (optItem) {
      case 1: lerValores (); break;
      case 2: calcular (); break;
      case 3: exibir (); break;
      case 4: exit (0);
      default: cout << "\nOpção Inválida!" << endl; 
      system ("sleep 4"); break;
    }
  }
}