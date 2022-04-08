#include <stdlib.h>
#include <math.h>

#include "vector.h"

/* Implementation of the Vector API */

vector* vector_new(double x, double y, double z) {
    vector* v = NULL;
    v->x = x;
    v->y = y;
    v->z = z;

    return v;
}

vector*  vector_add(vector* v1, vector *v2) {
    vector* res = NULL;
    res->x = v1->x + v2->x;
    res->y = v1->y + v2->y;
    res->z = v1->z + v2->z;
    
    return res;
}

vector* vector_sub(vector* v1, vector* v2) {
    vector* res = NULL;
    res->x = v1->x - v2->x;
    res->y = v1->y - v2->y;
    res->z = v1->z - v2->z;
    
    return res;
}

vector* vector_scale(double num, vector* v) {
    vector* res = NULL;
    res->x = v->x * num;
    res->y = v->y * num;
    res->z = v->z * num;
    
    return res;
}

vector* vector_vprod(vector* v1, vector* v2) {
    vector* res = NULL;
    res->x = (v1->x * v2->y) - (v2->x * v1->y);
    res->y = (v2->x * v1->z) - (v1->x * v2->z);
    res->z = (v1->x * v2->y) - (v2->x * v1->y);

    return res;
}

double vector_sprod(vector* v1, vector* v2) {
    return ( (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z) );
}

double vector_mod(vector* v) {
    return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}