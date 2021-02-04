#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int i = 0;
sem_t lock;

// Note the return type: void*
void* incrementingThreadFunction(){
	
	sem_wait(&lock);
    for (int j = 0; j < 1000000; j++) {
		// TODO: sync access to i
		i++;
		//printf("+ \n"); // used for testing
    }
	sem_post(&lock);
    return NULL;
}

void* decrementingThreadFunction(){
	sem_wait(&lock);
    for (int j = 0; j < 1000000; j++) {
		// TODO: sync access to i
		i--;
		//printf("- \n"); // used for testing
	}
	sem_post(&lock);
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
	sem_init(&lock, 0,1);
	
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);	
	
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
	
	sem_destroy(&lock);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
// Would use semaphore as the preferred solution. The semaphore does not lock the resource, but it signals to other that a thread is
// using the resource.