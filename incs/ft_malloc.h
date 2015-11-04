/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:46:35 by ppellegr          #+#    #+#             */
/*   Updated: 2015/11/04 15:46:38 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <sys/resource.h>

typedef struct	s_mem_allow
{
	void		*start_ptr;
	size_t		size_req;
	size_t		total_size;
	int			pages_nb;
}				t_mem_allow;

void			*ft_malloc(size_t size);
void			info_struct(t_mem_allow	*mem, size_t size,void *mmap_ptr, size_t page_size);

#endif