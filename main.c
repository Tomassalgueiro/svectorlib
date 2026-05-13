#include "svectorlib.h"
#include <stdio.h>

int main(){

     svector_int v;
     svector_init(&v);
     svector_push(&v, 6);
     svector_push(&v, 5);
     svector_push(&v, 4);
     svector_push(&v, 3);
     svector_push(&v, 2);
     svector_push(&v, 1);
     int element = svector_get(&v, 4);
     printf("\n %d", element);

}
