/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:46:30 by ppellegr          #+#    #+#             */
/*   Updated: 2015/11/04 15:46:30 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

t_malloc			alloc_array;

void				show_alloc_mem(){
	
}

/*
void				*large_malloc(size_t size)
{

}

void				*small_malloc(size_t size)
{

}
*/

t_blkset			*init_blkset(void *ptr, size_t size, char *type)
{
	t_blkset		*bs;
	bs = (t_blkset*)ptr;
	bs->size = size;
	bs->next = NULL;
	bs->prev = NULL;
	bs->type = type;
	bs->first = NULL;
	return (bs);
}

t_block				*init_block(void *ptr, size_t size)
{
	t_block			*b;
	b = (t_block*)ptr;
	b->size = size;
	b->next = NULL;
	b->prev = NULL;
	b->isfree = 0;
	return (b);
}


t_blkset			*alloc_blkset(size_t size, char *type)
{
	t_mem_allow		mem;
	t_block			*bl;
	t_blkset		*blkset;

	blkset = (t_blkset*)mmap(NULL, size, PROT_READ | PROT_WRITE ,
		MAP_ANON | MAP_PRIVATE, -1, 0);
	alloc_array.m_tiny = blkset;
	init_blkset(blkset, size, type)
	return (blkset);
}

t_block				*add_block_in_set(t_blkset *blkset, size_t size)
{
	t_block			*new_blk;

	blk = (t_block*)(void*)&blkset + size;
	blkset->first = new_blk;
	return(blk);
}

void				*tiny_malloc(size_t size)
{
	t_blkset		*blkset;
	t_block			*block;

	blkset = alloc_blkset(TINY_LENGTH, "TINY");
	block = add_block_in_set(blkset, size);

	return ();
}

void				*malloc(size_t size)
{
	struct rlimit	rlp;
	int				limit = 0;

	limit = getrlimit(RLIMIT_CORE, &rlp);
	if (limit == -1)
		perror("-- ");

	printf("rlp.rlim_cur : %llu\n", rlp.rlim_cur);

	if (size <= TINY_M)
		return (tiny_malloc(size));
	else if (size <= SMALL_M)
		return (small_malloc(size));
	else
		return (large_malloc(size));
	return (NULL);
}



