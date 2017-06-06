#include <stdio.h>
#include <unistd.h> 
#include <signal.h>
#include <stdlib.h>

void CWE243_NG(FILE* network) {

	char filename[255];
	char buf[255];
	size_t len = 0;

	chroot("/var/ftproot");//ERROR
	
	fgets(filename, sizeof(filename), network);
	FILE* localfile = fopen(filename, "r");
	while ((len = fread(buf, 1, sizeof(buf), localfile)) != EOF) {
		fwrite(buf, 1, sizeof(buf), network);
	}
	fclose(localfile);
}

void CWE243_OK(FILE* network) {

	char filename[255];
	char buf[255];
	size_t len = 0;
	
	chroot("/var/ftproot");

	fgets(filename, sizeof(filename), network);

	chdir("/");

	FILE* localfile = fopen(filename, "r");
	
	while ((len = fread(buf, 1, sizeof(buf), localfile)) != EOF) {
		fwrite(buf, 1, sizeof(buf), network);
	}
	fclose(localfile);
}

//SHOULD BE COVERED BY MISRA.SWITCH.NODEFAULT
void test_CWE478(int result) {
#define CWE478_FAILED 0
#define CWE478_PASSED 1
	switch (result) {
	case CWE478_FAILED:
		printf("Security check failed!\n");
		exit(-1);
		//Break never reached because of exit()
		break;
	case CWE478_PASSED:
		printf("Security check passed.\n");
		break;
	}
}

//SHOULD BE COVERED BY MISRA.SWITCH.NODEFAULT
void test_CWE478_2(int x) {
switch ( x ) 
{
  case 0:
    ++x; 
    break; 
  case 1: 
  case 2:
    break;
                        /* Non-compliant - default label is required */ 
}
}

typedef unsigned int myuint;



unsigned long int CWE_681_NG1(int result){
    switch(result){
        case 1:
            return -1;
        default:
            return 0;
    }
}

myuint CWE_681_NG2(int result){
    switch(result){
        case 1:
            return -1;
        default:
            return 0;
    }
}


int CWE_681_OK(int result){
    switch(result){
        case 1:
            return -1;
        default:
            return 0;
    }
}

void CWE831_handler1 (int sigNum) {

}
void CWE831_handler2 (int sigNum) {

}


void CWE831_NG () {
signal(SIGUSR1, CWE831_handler1);//ERROR
signal(SIGUSR2, CWE831_handler1);
}

void CWE831_OK () {
signal(SIGUSR1, CWE831_handler1);
signal(SIGUSR2, CWE831_handler2);
}


