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
	
	double szam = receivedouble();
	int i;
	double temp = 1;
	for(i=1;i<=szam;i++){
		temp*=i;
	}

	senddouble(pvm_parent(), temp);
	pvm_exit();
	exit(EXIT_SUCCESS);
}