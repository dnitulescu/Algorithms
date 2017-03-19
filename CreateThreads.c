 /*
 #include <pthread.h>
 #include <stdio.h>
 #define NUM_THREADS     5
 #include <windows.h>

 void *PrintHello(void *threadid)
 {
    long tid;
    tid = (long)threadid;
    Sleep( 2000 ); 
    printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit(NULL);
 }
 
void *PrintMessage(void *threadid)
 {
    long tid;
    tid = (long)threadid;
    //Sleep( 2000 ); 
    printf("This is a message from thread  #%ld!\n", tid);
    pthread_exit(NULL);
 }

 int main (int argc, char *argv[])
 {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0; t<(NUM_THREADS-2); t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&threads[t], NULL, &PrintHello, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }
    
    for(t=3; t<NUM_THREADS; t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&threads[t], NULL, &PrintMessage, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }

    // Last thing that main() should do 
    pthread_exit(NULL);
 }
 */
