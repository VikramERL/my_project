#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int a = 0;                 // Shared variable
pthread_mutex_t lock;      // Mutex lock

void* increment(void* arg) {
    for (int i = 0; i < 1000; i++) {
    	pthread_mutex_lock(&lock);
        a++;
	pthread_mutex_unlock(&lock);
	usleep(10);
    }
    return NULL;
}

void* print_value(void* arg) {
    for (int i = 0; i < 1000; i++) {
    	pthread_mutex_lock(&lock);
        printf("Value of a: %d\n", a);
    	pthread_mutex_unlock(&lock);
	usleep(10);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL); // Initialize mutex

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, print_value, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex
    return 0;
}

