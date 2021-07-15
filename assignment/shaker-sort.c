#include <stdio.h>
#define DATA 20 // number of data

int main(void) {
	int T[20]={68, 29, 99, 2, 25, 16, 15, 24, 52, 21, 12, 91, 67, 5, 57, 4, 51, 17, 79, 71};
	int prv = -1;
	int top, last, tmp = 0;
	int num = DATA;

	// set search range to all
	top = 0;
	last = num - 1;

	while (1) {

		prv = top;
		// search top to last
		for (int i = top; i <= last - 1; i++) {
			if (T[i] > T[i + 1]) {
				tmp = T[i];
				T[i] = T[i + 1];
				T[i + 1] = tmp;
				prv = i + 1;
			}
		}

		// reset search range without prv
		last = prv - 1;

		if (last == top) {
			break;
		}

		prv = last;
		// search last to top
		for (int i = last - 1; i >= top; i--) {
			if (T[i] > T[i + 1]) {
				tmp = T[i];
				T[i] = T[i + 1];
				T[i + 1] = tmp;
				prv = i + 1;
			}
		}
		// reset search range without prv
		top = prv;

		if (last == top) {
			break;
		}
	}

	for (int i = 0; i < DATA; i++)
	{
		printf("%d,", T[i]);
	}

	return 0;
}