#include "stdio.h"
#include "assert.h"

typedef unsigned char byte;
typedef unsigned int  uint;

#ifndef NULL
#define NULL 0
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/******************************************************************************/

/*
 *  Checkpoint 1 - finish the node definition, we would like a list of `int`s.
 */
typedef struct
{
} node_t;

int ll_get(const node_t *ll, const int index) { return -1; }
int ll_size(const node_t *ll) { return 0; }

#define CHECKPOINT_1 0

/******************************************************************************/

/*
 *  Checkpoint 2 - define a linked list printer.
 */
#define CHECKPOINT_2 0

void ll_print(const node_t *ll)
{
#if CHECKPOINT_2
    assert(!"Implement `ll_print()`\n");
#endif
}



/******************************************************************************/

/*
 *  Checkpoint 3 - implement a queue :: `enqueue` and `dequeue`.
 */
node_t *ll_enqueue(node_t *ll, int v) { return NULL; }
node_t *ll_dequeue(node_t *ll, int *v) { return NULL; }

#define CHECKPOINT_3 0

void test_queue()
{
#if CHECKPOINT_3
    int v;

    node_t *q = NULL;
    q = ll_enqueue(q, 1);
    q = ll_enqueue(q, 2);
    q = ll_enqueue(q, 3);

    assert((q = ll_dequeue(q, &v)));
    assert(1 == v);
    assert((q = ll_dequeue(q, &v)));
    assert(2 == v);

    q = ll_enqueue(q, 4);
    assert((q = ll_dequeue(q, &v)));
    assert(3 == v);
    assert(NULL == (q = ll_dequeue(q, &v)));
    assert(4 == v);

    assert(FALSE == ll_dequeue(q, &v));
#endif
}

/******************************************************************************/

/*
 *  Checkpoint 4 - implement a stack :: `push` and `pop`.
 */
node_t *ll_push(node_t *ll, int v) { return NULL; }
node_t *ll_pop(node_t *ll, int *v) { return NULL; }

#define CHECKPOINT_4 0

void test_stack()
{
#if CHECKPOINT_4
    int v;

    node_t *s = NULL;
    s = ll_push(s, 1);
    s = ll_push(s, 2);
    s = ll_push(s, 3);

    assert((s = ll_pop(s, &v)));
    assert(3 == v);
    assert((s = ll_pop(s, &v)));
    assert(2 == v);

    s = ll_push(s, 4);
    assert((s = ll_pop(s, &v)));
    assert(4 == v);
    assert(NULL == (s = ll_pop(s, &v)));
    assert(1 == v);

    assert(FALSE == ll_pop(s, &v));
#endif
}

/******************************************************************************/

/*
 *  Checkpoint 5 - implement reverse and remove!
 */
node_t *ll_reverse(node_t *ll) { return NULL; }
node_t *ll_remove(node_t *ll, const int index) { return NULL; }

#define CHECKPOINT_5 0

void test_reverse_remove()
{
#if CHECKPOINT_5
    node_t *s = NULL;
    s = ll_push(s, 1);
    s = ll_push(s, 2);
    s = ll_push(s, 3);
    assert(1 == ll_get(s, 0));
    assert(2 == ll_get(s, 1));
    assert(3 == ll_get(s, 2));
    s = ll_reverse(s);
    assert(3 == ll_get(s, 0));
    assert(2 == ll_get(s, 1));
    assert(1 == ll_get(s, 2));

    s = ll_push(s, 4);
    s = ll_reverse(s);
    s = ll_remove(s, 1);
    assert(4 == ll_get(s, 0));
    assert(2 == ll_get(s, 1));
    assert(3 == ll_get(s, 2));
#endif
}

/******************************************************************************/

node_t *ll_sort(node_t *ll) { return NULL; }

#define CHECKPOINT_6 0

void test_sort()
{
#if CHECKPOINT_6
    node_t *s = NULL;
    s = ll_push(s, 30);
    s = ll_push(s, 10);
    s = ll_push(s, 17);
    s = ll_push(s, -4);
    s = ll_push(s, 47);
    s = ll_push(s, 0);
    s = ll_push(s, -9);

    s = ll_sort(s);
    assert(-9 == ll_get(s, 0));
    assert(-4 == ll_get(s, 1));
    assert(0  == ll_get(s, 2));
    assert(10 == ll_get(s, 3));
    assert(17 == ll_get(s, 4));
    assert(30 == ll_get(s, 5));
    assert(47 == ll_get(s, 6));
#endif
}

/******************************************************************************/

#define ANY_CHECKPOINT (CHECKPOINT_1 | CHECKPOINT_2 | CHECKPOINT_3 | \
                        CHECKPOINT_4 | CHECKPOINT_5 | CHECKPOINT_6)

#define ALL_CHECKPOINT (CHECKPOINT_1 & CHECKPOINT_2 & CHECKPOINT_3 & \
                        CHECKPOINT_4 & CHECKPOINT_5 & CHECKPOINT_6)

/******************************************************************************/

/*
 *  `main` application entry-point.
 */
int main(int argc, char **argv)
{
    #if CHECKPOINT_1
    {
        node_t *ll = NULL;
        // TODO: Insert two nodes `1` and `2` here.
        assert(ll_size(ll) == 2);
        assert(ll_get(ll, 0) == 1);
        assert(ll_get(ll, 1) == 2);
        ll_print(ll);
    }
    #endif  // CHECKPOINT_1

    {
        test_queue();
        test_stack();
        test_reverse_remove();
        test_sort();
    }

    #if ANY_CHECKPOINT == 0
    {
        assert(!"Enable `CHECKPOINT_1` in `main.c` and type `make` again\n");
    }
    #elif ALL_CHECKPOINT == 1
    {
        printf("Huzzah! You made it!\n");
    }
    #endif
}
