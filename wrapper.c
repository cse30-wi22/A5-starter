#include <stdlib.h>
#include <stdio.h>
#include <time.h>
extern int __real_main(int, char **);
extern void * __real_malloc(size_t c);
///
/// compile with -Wl,--wrap=main,--wrap=malloc
///
///
/// set default stack to non-zero values
///
void __stackSet(){
  int arr[4096];
  srand(time(NULL));
  for (int i=0; i<4096; i++){
    arr[i] = rand();
  }
  (void)arr[1];
}
///
/// wrapper around main
///
int __wrap_main(int argc, char **argv){
  __stackSet();
  //printf("Starting in __wrap_main()\n");
  return  __real_main(argc, argv);
}
///
/// wrapper around malloc.  Set
/// values returned by malloc to non-zero values
///
void * __wrap_malloc(size_t c){
  void *p = __real_malloc(c);
  if (p != NULL){
    char *t = (char*)p;
    for (size_t i=0; i<c; i++){
      *t = (char)(rand()%256);
      t++;
    }
  }
  return p;
}
