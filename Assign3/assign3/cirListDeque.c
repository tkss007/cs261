#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
    TYPE value;/* value of the link */
    struct DLink * next;/* pointer to the next link */
    struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
    int size;/* number of links in the deque */
    struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
 ************************************************************************ */

/* Initialize deque.
 
	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
 */
void _initCirListDeque (struct cirListDeque *q)
{
    assert(q != 0);
    q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));
    assert(q->Sentinel != 0);
    q->Sentinel->next = q->Sentinel;
    q->Sentinel->prev = q->Sentinel;
    q->Sentinel->value = 0;
    q->size = 0;
    /* FIXME: you must write this */
}

/*
 create a new circular list deque
 
 */

struct cirListDeque *createCirListDeque()
{
    struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
    _initCirListDeque(newCL);
    return(newCL);
}


/* Create a link for a value.
 
	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
 */
struct DLink * _createLink (TYPE val)
{
    struct DLink* link = (struct DLink *)malloc(sizeof(struct DLink));
    link->value = val;
    link->next = 0;
    link->prev = 0;
    return link;
    /* FIXME: you must write this */
    
    /*temporary return value..you may need to change it*/
    //return(0);
    
}

/* Adds a link after another link
 
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
 */
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
    struct DLink *newLink = _createLink(v);
    newLink->next = lnk->next;
    lnk->next = newLink;
    newLink->prev = lnk;
    newLink->next->prev = newLink;
    q->size++;
    /* FIXME: you must write this */
    
}

/* Adds a link to the back of the deque
 
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
 */
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
    //assert(q != NULL);
    _addLinkAfter(q, q->Sentinel->prev, val);  //////
    /* FIXME: you must write this */
    
}

/* Adds a link to the front of the deque
 
	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
 */
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    
    assert(q != 0);
    _addLinkAfter(q, q->Sentinel, val);
    /* FIXME: you must write this */
    
}

/* Get the value of the front of the deque
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
 */
TYPE frontCirListDeque(struct cirListDeque *q)
{
    
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    return(q -> Sentinel -> next -> value);
    /* FIXME: you must write this */
    /*temporary return value..you may need to change it*/
    //return(1);
}

/* Get the value of the back of the deque
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
 */
TYPE backCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    return q->Sentinel->prev->value;
    /* FIXME: you must write this */
    /*temporary return value..you may need to change it*/
    //return(1);
}

/* Remove a link from the deque
 
	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
 */
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
    assert(lnk != 0);
    
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    
    free(lnk);
    q->size--;
    /* FIXME: you must write this */
    
}

/* Remove the front of the deque
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
 */
void removeFrontCirListDeque (struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    _removeLink(q, q->Sentinel->next);
    /* FIXME: you must write this */
    
}


/* Remove the back of the deque
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
 */
void removeBackCirListDeque(struct cirListDeque *q)
{
    assert(q != 0);
    assert(!isEmptyCirListDeque(q));
    _removeLink(q, q->Sentinel->prev);
    /* FIXME: you must write this */
}

/* De-allocate all links of the deque
 
	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
 */
void freeCirListDeque(struct cirListDeque *q)
{
    struct DLink *current = q->Sentinel->next;
    struct DLink *nextcurrent = q->Sentinel->next->next;
    int i;
    
    for(i=0; i < q->size; i++){
        current = nextcurrent;
        q->size--;
    }
    free(q->Sentinel);
    /* FIXME: you must write this */
    
}

/* 	Deallocate all the links and the deque itself.
 
	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
 */
void deleteCirListDeque(struct cirListDeque *q) {
    assert(q != 0);
    freeCirListDeque(q);
    free(q);
}

/* Check whether the deque is empty
 
	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
 */
int isEmptyCirListDeque(struct cirListDeque *q)
{
    if(q->size == 0){
        return 1;
    }
    return 0;
    /* FIXME: you must write this */
    /*temporary return value..you may need to change it*/
    //return(1);
}

/* Print the links in the deque from front to back
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
 */
void printCirListDeque(struct cirListDeque *q)
{
    int i;
    struct DLink* Ptr = q->Sentinel->next;
    
    for(i = 0; i < q->size; i++){
        printf("%f", Ptr->value);
        Ptr = Ptr->next;
    }
    printf("\n");
    /* FIXME: you must write this */
    
}

/* Reverse the deque
 
	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
 */
void reverseCirListDeque(struct cirListDeque *q)
{
    struct DLink *current = q->Sentinel;
    struct DLink *temp = q->Sentinel->next;
    
    int i;
    for(i = 0; i <= q->size; i++){
        current->next = current->prev;
        current->prev = temp;
        current = temp;
        temp = temp->next;
    }
    /* FIXME: you must write this */
    
}
