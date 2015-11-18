/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:46:35 by ppellegr          #+#    #+#             */
/*   Updated: 2015/11/04 15:46:38 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H
# define TINY_M 512
# define SMALL_M 4096

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>


typedef struct	s_mem_allow
{
	void		*start_ptr;
	size_t		size_req;
	size_t		total_size;
	int			pages_nb;
	char		*type;
}				t_mem_allow;

typedef struct	s_tiny {

}				t_tiny;

typedef struct	s_small {

}				t_small;

typedef struct	s_large {

}				t_large;

typedef struct	s_malloc
{
	t_tiny		*m_tiny;
	t_small		*m_small;
	t_large		*m_large;

}				t_malloc;

void			*malloc(size_t size);
void			info_struct(t_mem_allow	*mem, size_t size,void *mmap_ptr);
void			show_alloc_mem();
void			*tiny_malloc(size_t size);
void			*small_malloc(size_t size);
void			*large_malloc(size_t size);

#endif