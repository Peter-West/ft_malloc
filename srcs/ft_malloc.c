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


void	info_struct(t_mem_allow	*mem, size_t size,void *mmap_ptr, size_t page_size) {
	mem->start_ptr = mmap_ptr;
	mem->size_req = size;
	mem->total_size = size + sizeof(*mem);
	mem->pages_nb = (size / page_size) + 1;

	printf("size_struct : %zu\n", sizeof(*mem));
	printf("mmap_ptr : %p\n", mem->start_ptr);
	printf("size requested : %zu\n", mem->size_req);
	printf("total size : %zu\n", mem->total_size);
	printf("nb pages : %d\n", mem->pages_nb);
	
	// printf("taille du ptr : %zu", strlen(mmap_ptr));
	printf("size size_t : %zu\n", sizeof(size_t));
}

void	*ft_malloc(size_t size)
{
	int					page_size = getpagesize();
	int					fd;
	struct rlimit		*rlp = NULL;
	int					limit = 0;
	t_mem_allow			mem;


	if (-1 == (fd = open("all_users", O_CREAT | O_RDWR, 0755)))
	{
		printf("open failed\n");
		return (NULL);
	}

	void				*mmap_ptr = NULL;
	limit = getrlimit(RLIMIT_CORE, rlp);
	if (limit == -1)
		perror("-- ");

	mmap_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE , MAP_SHARED, fd, page_size);

	info_struct(&mem, size, mmap_ptr, page_size);

	if (mmap_ptr != MAP_FAILED)
		printf("yes\n");
	else
	{
		// printf("%s\n", strerror((int)MAP_FAILED));
		// int errsv = errno;
		// if (errsv == MAP_FAILED)
			perror("** ");

	}

	size_t	test_struct;
	test_struct = sizeof(mem);

	// printf("limit %d\n", limit);
	printf("mmap_ptr : %p\n", mmap_ptr);
	printf("\nsize structure : %zu\n", test_struct);
	printf("size : %zu\n", size);
	// printf("page_size : %d\n", page_size);
	return (NULL);
}