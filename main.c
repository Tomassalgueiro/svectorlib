#include "svectorlib.h"

int main(){

     svector_int v;
     svector_init(&v);
     svector_push(&v, 1);
     svector_push(&v, 2);
     svector_push(&v, 3);
     svector_push(&v, 4);
     svector_push(&v, 5);
     svector_push(&v, 6);
     svector_print(&v);

}
