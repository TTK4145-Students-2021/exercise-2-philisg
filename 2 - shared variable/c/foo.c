#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_mutex_t lock;
// Note the return type: void*
void* incrementingThreadFunction(){
	pthread_mutex_lock(&lock);
    for (int j = 0; j < 1000000; j++) {
		// TODO: sync access to i
		i++;
    }
	pthread_mutex_unlock(&lock);
    return NULL;
}

void* decrementingThreadFunction(){
	pthread_mutex_lock(&lock);
    for (int j = 0; j < 1000000; j++) {
		// TODO: sync access to i
		i--;
    }
	pthread_mutex_unlock(&lock);
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
	pthread_mutex_init(&lock, NULL);
	
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);	
	
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);
	
	pthread_mutex_destroy(&lock);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
// Mutex is the preffered solution. This is because Mutex locks the resource until its done executing the critical section
// of the code. After execution the resource is released and other threads/processes can use it. A mutex is a 
// mutual exclusion technique while semaphore is a signaling mechanism. 