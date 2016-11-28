#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



void waitFor(time_t);

void time_state_example();
void time_state_example_odd();

void state_main_algorithm(int);

void (*timetest[]) = { time_state_example, time_state_example_odd };

int main(int argc, char *argv[]) {

	int num;

	if (argc == 1) {

		void (*tt)() = timetest[time(NULL) % 2];
		tt();

	}
	else {

		sscanf(argv[1], "%d", &num);
		void(*tt)() = timetest[num];
		tt();

	}

	getchar();
	getchar();

	return 0;

}



void time_state_example() {
	state_main_algorithm(2);
}

void time_state_example_odd() {
	state_main_algorithm(5);
}

void state_main_algorithm(int n) {

	int i;

	system("cls");

	for (i = 0 ;i <= 100 ; i += n) {

		printf("%d", i);
		waitFor(1);
		system("cls");
	}

}

void waitFor(time_t seconds) {
	time_t returntime = time(NULL) + seconds;
	while (time(NULL) < returntime);
}
