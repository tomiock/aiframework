#ifndef POINT_TEST_H_
#define POINT_TEST_H_

#include <stdlib.h>
#include </home/tomiock/anaconda3/envs/latest/include/python3.12/Python.h>

typedef struct point Point;

Point* point_init(int x, int y);

struct point {
    int x;
    int y;
    long z;
};

/*
Point* point_init(int x, int y) {
	Point* p;
	if ((p = malloc(sizeof *p)) != NULL) {
	    p->x = x;
	    p->y = y;
	}
	return p;
}
*/

#endif // POINT_H_
