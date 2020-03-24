
#include <stdio.h>
#include <pthread.h>

/* Program spawns two threads, one to print even numbers, the other odd.
 * Currently the threads may not interleave properly and numbers may print out of order.
 * Add syncronization code so that the numbers are guaranteed to print in order (e.g. 1,2,3,4 etc).
 */

/*
 * Some pthreads synchronization primitives syntax that might be useful:
 *
 * pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 * pthread_mutex_(un)lock( pthread_mutex_t *mutex )
 * 
 * pthread_cond_t  cv = PTHREAD_COND_INITIALIZER;
 * pthread_cond_wait( pthread_cond_t *cv, pthread_mutex_t *mutex )
 * pthread_cond_signal( pthread_cond_t *cv)
 *
 * #include <semaphore.h>
 * sem_init( sem_t *sem, int shared_with_other_processes, unsigned int value)
 * sem_post( sem_t *sem)
 * sem_wait( sem_t *sem)
 */


/* Globals */

/* Functions */
void *do_thread_even(void *args)
{
    /* Print Even numbers from 0 -> 18 here. */
    for (int i = 0; i < 10; ++i)
    {
        printf("Thread A :: %d\n", 2 * i);
    }
    return NULL;
}

void *do_thread_odd(void *args)
{
    /* Print Odd numbers from 1 -> 19 here. */
    for (int i = 0; i < 10; ++i)
    {
        printf("Thread B :: %d\n", 2 * i + 1);
    }
    return NULL;
}

int main()
{
    pthread_t id_even, id_odd;
    int ret;

    ret = pthread_create(&id_even, NULL, &do_thread_even, NULL);
    if (ret > 0) {
        printf("Unable to create thread_a :: ec=%d\n", ret);
        return 1;
    }

    ret = pthread_create(&id_odd, NULL, &do_thread_odd, NULL);
    if (ret > 0) {
        printf("Unable to create thread_a :: ec=%d\n", ret);
        return 1;
    }

    pthread_join(id_even, NULL);
    pthread_join(id_odd, NULL);

    return 0;
}
