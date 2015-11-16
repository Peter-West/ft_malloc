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


// void	*mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
// int
//      getrlimit(int resource, struct rlimit *rlp);

//      struct rlimit {
//                    rlim_t  rlim_cur;       /* current (soft) limit */
//                    rlim_t  rlim_max;       /* hard limit */
//            };


void				info_struct(t_mem_allow	*mem, size_t size, void *mmap_ptr) {
	mem->start_ptr = mmap_ptr;
	mem->size_req = size;
	mem->pages_nb = (size / (size_t)getpagesize()) + 1;

	printf("size_struct : %zu\n", sizeof(*mem));
	printf("mmap_ptr : %p\n", mem->start_ptr);
	printf("size requested : %zu\n", mem->size_req);
	printf("total size : %zu\n", mem->total_size);
	printf("nb pages : %d\n", mem->pages_nb);
	
	// printf("taille du ptr : %zu", strlen(mmap_ptr));
	printf("size size_t : %zu\n", sizeof(size_t));
}

void				show_alloc_mem(){

}

void				tiny_malloc(size_t size)
{
	t_mem_allow		mem;
	char			*mmap_ptr = NULL;

	mmap_ptr = mmap(NULL, mem.total_size, PROT_READ | PROT_WRITE , MAP_ANON | MAP_PRIVATE, -1, 0);
	
}

void				*ft_malloc(size_t size)
{
	struct rlimit	rlp;
	int				limit = 0;
	t_mem_allow		mem;
	char			*mmap_ptr = NULL;

	limit = getrlimit(RLIMIT_CORE, &rlp);
	if (limit == -1)
		perror("-- ");

	printf("rlp.rlim_cur : %llu\n", rlp.rlim_cur);

	if (size < 100)
		tiny_malloc(size);
	else
	{
		mem.total_size = size + sizeof(mem);

		mmap_ptr = mmap(NULL, mem.total_size, PROT_READ | PROT_WRITE , MAP_ANON | MAP_PRIVATE, -1, 0);
		info_struct(&mem, size, mmap_ptr);

		if (mmap_ptr == MAP_FAILED)
			perror("** ");

		size_t	test_struct;
		test_struct = sizeof(mem);

		// printf("mmap_ptr : %p\n", mmap_ptr);
	}
	return (NULL);
}



