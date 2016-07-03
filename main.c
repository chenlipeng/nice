#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>



int my_strcoll(const char *lhs, const char *rhs);
void output();
void success();
void error();
void spin_lock(int *lock, int which);

//static int ncpu = 4;
int main() {

	int val1 = 1, val2 = 2;
	typedef struct {
		int val1;
		int val2;
	}st;

	st nst = {
		val1: val1,
		val2: val2,
	};
	printf("%d %d\n", nst.val1, nst.val2);
return 0;

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 1000000;
    select(0, NULL, NULL, NULL, &tv);
int val = 10000;
for (; val>0; --val) {
}
	printf("%d %d\n", tv.tv_sec, tv.tv_usec);
return 0;
	int rets = -1 << 4;
	printf("%d\n", (-1<<10));
	return 0;
	int lock = 2, which = (int) getpid();
	printf("%d\n", which);
//	spin_lock(lock, which);

	return 0;

	int ret = my_strcoll("ba", "Z");
	printf("%d\n", ret);
	atexit(output);
	atexit(error);
	atexit(success);
	return 0;
}


void output() {
	printf("-------------------\n");
}

void success() {
	printf("success.\n");
}

void error() {
	printf("error.\n");
}

int my_strcoll(const char *lhs, const char *rhs) {
	return strcoll(lhs, rhs);
}

void spin_lock(int *lock, int which) {
	static int ncpu = 4;
    int i, n;

    for (; ;) {

        if (*lock == 0 &&
            __sync_bool_compare_and_swap(lock, 0, which)) {
            return;
        }

        if (ncpu > 1) {

            for (n = 1; n < 129; n << 1) {

                for (i = 0; i < n; i++) {
                    __asm("pause");
                }

                if (*lock == 0 &&
                    __sync_bool_compare_and_swap(lock, 0, which)) {
                    return;
                }
            }
        }
	printf("xxxxxxxxxxxxxxxxxxxxxx\n");

        sched_yield();
    }
}
