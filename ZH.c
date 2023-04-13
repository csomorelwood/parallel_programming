// Vass Gergő - CPZYU5
// FELADAT:
// 1. Írj C programot, amely Linux IPC-t használ.
// Hozz létre egy közös memóriaszegmenst egész érték tárolására és inicializáld egy tetszőleges pozitív
// számmal. A szülő processz hozzon létre 3 db gyerek processzt:
// (a) ha a gyerekprocessz azonosítója páros: altassuk a processzt 3 másodpercig, majd ezt követően
// szorozza be a közös szegmensen található értéket 3-mal
// (b) ha a gyerekprocessz azonosítója páratlan: altassuk a processzt 1 másodpercig, majd szorozza
// be a közös szegmensen található értéket 7-tel
// A szülő processz várja meg a gyerek processzeket és írja ki a szegmens aktuális értékét. Kölcsönös
// kizárással biztosítsd, hogy a gyerekprocesszek ne írják felül egymás számításait. Csak és kizárólag
// a szükséges kódrészlet legyen része a kritikus szakasznak.

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int CSinit(int value) {
    int sh = semget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    semctl(sh, 0, SETVAL, value);
    return sh;
}

static void CSoper(int sh, int op) {
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = 0;
    sb.sem_op = op;
    semop(sh, & sb, 1);
}

void CSwait(int sh) {
    CSoper(sh, -1);
}

void CSsignal(int sh) {
    CSoper(sh, 1);
}

int main() {
    int sh = CSinit(1);
    int shmid = shmget(IPC_PRIVATE, 1, 0666 | IPC_CREAT);
    int * number = (int * ) shmat(shmid, NULL, 0);

    * number = 1;
    printf("%d\n", *number);

    pid_t PID;
    int i;

    for (i = 0; i < 3; i++) {
        PID = fork();

        if (PID == 0) {
            break;
        } else if (PID < 0) {
            exit(EXIT_FAILURE);
        }
    }

    if (PID == 0) {
        if(getpid() % 2 == 0) {
            CSwait(sh);
            sleep(3);
            * number *= 3;
            CSsignal(sh);
        } else {
            CSwait(sh);
            sleep(1);
            * number *= 7;
            CSsignal(sh);
        }
        printf("Child: %d, Number: %d \n", getpid(), * number);
    } else if (PID > 0) {
        int j;
        for (j = 0; j < 3; j++) {
            printf("Waited: %d\n", wait(NULL));
        }
        printf("Parent final number: %d\n", * number);
        exit(EXIT_SUCCESS);
    }
}