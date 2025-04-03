#include<iostream>
#include "Eigen/Eigen"
#include <iomanip>
using namespace std;
using namespace Eigen;

void print(Matrix2d b){
	cout<<"la matrice che vuoi stampare è: "<<b<<endl;	
}
void print1(Vector2d y){
	cout<<"la soluzione al sitema lineare1 è: "<<y<<endl;	
}

Vector2d solutorePALU(Matrix2d A,Vector2d b){
		PartialPivLU<Matrix2d> lu(A);  //è un metodo appartenente alla classe delle matrici definite in Eigen
		//Non necessario, ma l'ho fatto per capire come funziona il comando
		Matrix2d U = lu.matrixLU().triangularView<Upper>();
		Matrix2d L = lu.matrixLU().triangularView<StrictlyLower>();
		Matrix2d P = lu.permutationP();
		Vector2d x = lu.solve(b);
		return x;
}
long double errore_relativo(Vector2d soluzionePALU){
	Vector2d sol_esatta= {-1.0e+0, -1.0e+00};
	long double err_rel=(sol_esatta-soluzionePALU).norm()/sol_esatta.norm();
	return err_rel;
}


int main()
{
    Matrix2d A1 {      // costruisce a 2x2 matrix
      {5.547001962252291e-01, -3.770900990025203e-02},     // prima riga
      {8.320502943378437e-01, -9.992887623566787e-01}      // second riga
	};
	Vector2d b1={-5.169911863249772e-01, 1.672384680188350e-01};
	
	Vector2d soluzione_sistema1= solutorePALU(A1,b1);
	long double err_rel1= errore_relativo(soluzione_sistema1);
	
	print1(soluzione_sistema1);
	cout<<"l'errore relativo del primo sistema è: "<<err_rel1<<endl;  //risolto il primo sistema
	
	Matrix2d A2 {
      {5.547001962252291e-01,-5.540607316466765e-01}, 
      {8.320502943378437e-01,-8.324762492991313e-01}      
	};
	Vector2d b2={-6.394645785530173e-04, 4.259549612877223e-04};
	
	Vector2d soluzione_sistema2= solutorePALU(A2,b2);
	long double err_rel2= errore_relativo(soluzione_sistema2);
	
	print1(soluzione_sistema2);
	cout<<"l'errore relativo del secondo sistema è: "<<err_rel2<<endl;  //risolto il secondo sistema
	
	Matrix2d A3 {
      {5.547001962252291e-01,-5.547001955851905e-01}, 
      {8.320502943378437e-01,-8.320502947645361e-01}      
	};
	Vector2d b3={-6.400391328043042e-10, 4.266924591433963e-10};
	
	Vector2d soluzione_sistema3= solutorePALU(A3,b3);
	long double err_rel3= errore_relativo(soluzione_sistema3);
	
	print1(soluzione_sistema3);
	cout<<"l'errore relativo del secondo sistema è: "<<err_rel3<<endl;  //risolto il terzo sistema	
	
	return 0;
}
