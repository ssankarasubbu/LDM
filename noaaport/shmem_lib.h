/**
 * This file declares the public interface of the "shmem_lib" module.
 */

#ifndef SHMEM_LIB_H
#define SHMEM_LIB_H

#ifdef __cplusplus
extern "C" {
#endif

char *
get_shm_ptr(
	int SHMnumber,  /* shared memory number to validate */
	char *name,     /* name for shared memory */
	int	flag);      /* print flag 0=no, >0 yes */

/*******************************************************************************
NAME
	com_shmAttach - Attach to an Allocated Shared Memory Segment

DESCRIPTION
	A unique well-known key is used to attach to an existing segment.
	Every process that wishes to access shared memory allocated elsewhere
	must perform this call.

RETURNS
	Returns the adress of the segment or NULL.

*******************************************************************************/
char *
com_shmAttach(
    int SHMnumber); /* shared memory segment key */

/*******************************************************************************
NAME
	com_shmIsAlloc - Determine if a Key is Allocated.

DESCRIPTION
	Each shared memory segment is allocated with a unique key, the
	SHMnumber that is unique to the host and well-known to allocator
	and user.  Who frees the segment is a matter of higher-level protocol.
	Stray segments are freed by com_shmAlloc().  ShmIsAlloc() makes it
	possible for an application to determine if a key is in use before
	com_shmAlloc() is called.

RETURNS
	Returns one, if the key is currently allocated;  returns zero if not.

*******************************************************************************/
int
com_shmIsAlloc(
    int SHMnumber); /* unique well-known key */

/*******************************************************************************
NAME
	com_shmAlloc - Allocate a Shared Memory Segment

DESCRIPTION
	Each shared memory segment is allocated with a unique key, the
	SHMnumber that is unique to the host and well-known to allocator
	and user.  Who frees the segment is a matter of higher-level protocol.
	Stray segments must be freed before allocation.  The protocol promises
	that the segment is unique.

RETURNS
	ShmAlloc() returns the address of the shared memory segment or NULL.


*******************************************************************************/
char *
com_shmAlloc(
    int size,       /* size of the shared memory segment in bytes */
    int SHMnumber); /* unique well-known key */

/*******************************************************************************
NAME
	com_shmDetach - Detach from a Shared Memory Segment

DESCRIPTION
	The segment, specified by its address, is detached.  This does not free
	the segment, but merely relinquishes sharing.

RETURNS
	Returns zero if sucessfully detached; otherwise returns -1.

*******************************************************************************/
int
com_shmDetach(
    char *address); /* data segment address to detach */

/*******************************************************************************
NAME
	com_shmFree - Free an Allocated Shared Memory Segment

DESCRIPTION
	The well-known key is used to free a shared memory resource.

RETURNS
	Returns zero if sucessfully freed;  otherwise, returns -1.

*******************************************************************************/
int
com_shmFree(
    int SHMnumber); /* free the segment associated with this key */

#ifdef __cplusplus
}
#endif

#endif
