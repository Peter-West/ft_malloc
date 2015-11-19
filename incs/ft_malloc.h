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
# define TINY_M			128
# define TINY_LENGTH	(4 * getpagesize())
# define SMALL_M		1024
# define SMALL_LENGTH	(32 * getpagesize())

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>


typedef struct		s_mem_allow
{
	void			*start_ptr;
	size_t			size_req;
	size_t			total_size;
	int				pages_nb;
	char			*type;
}					t_mem_allow;

typedef struct		s_blkset
{
	size_t			size;
	char			*type;
	struct s_blkset	*next;
	struct s_blkset	*prev;
	struct s_block	*first;
}					t_blkset;

typedef struct		s_block {
	size_t			size;
	int				is_free;
	struct s_block	*next;
	struct s_block	*prev;
}					t_block;

typedef struct		s_malloc
{
	t_tiny			*m_tiny;
	t_small			*m_small;
	t_large			*m_large;
}					t_malloc;

void			*malloc(size_t size);
void			show_alloc_mem();
void			*tiny_malloc(size_t size);
void			*small_malloc(size_t size);
void			*large_malloc(size_t size);

#endif