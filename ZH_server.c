/*
A master hozzon létre 3 új processzt, amelyek a worker kódot futtatják. A master mindhárom
worker-nek elküld egy egymástól különböző prímszámot. A worker-ek fogadják ezt a számot, majd
kiszámolják a kapott szám faktoriálisát és visszaküldik a master-nek, amely kiírja a kapott számok
összegét. A számokat double-ként kezeld.
Figyelj a túlcsordulásra, ilyen esetben írja ki a program, hogy túlcsordulás történt
*/

#include "stdio.h"
#include "stdlib.h"
#include "pvm3.h"

void senddouble(int tid, double data) {
	pvm_initsend(PvmDataDefault);
	pvm_pkdouble(&data, 1, 1);
	pvm_send(tid, 1);
}

int receivedouble() {
	pvm_recv(-1,-1);
	double num;
	pvm_upkdouble(&num, 1, 1);
	return num;
}

int main() {
	int tid[3];
	double a,b,c;
	pvm_spawn("/workdir/ZH_client", NULL, 0, "", 3, tid);
	
	senddouble(tid[0], 3);
	senddouble(tid[1], 5);
	senddouble(tid[2], 8);

	a=receivedouble();
	b=receivedouble();
	c=receivedouble();

	printf("A: %f, B: %f, C: %f\n", a, b, c);
    
	printf("Összeg: %f\n", a + b + c);

	pvm_exit();
	exit(EXIT_SUCCESS);
}