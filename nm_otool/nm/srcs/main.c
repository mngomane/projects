/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 08:28:31 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/27 08:28:31 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "ft_nm.h"


#include <sys/mman.h>

#include <inttypes.h>

#include <stdio.h>


int		main(void)
{
	int		fd;
	t_stat	st;
	char	*ptr;

	ptr = NULL;
	ft_bzero(&st, sizeof(t_stat));
	fd = open("a.out", O_RDONLY, 0644);
	printf("fstat return = %d\n", fstat(fd, &st));
	printf("st.st_dev = %u\n", st.st_dev);
	printf("st.st_mode = %d\n", st.st_mode);
	printf("st.st_nlink = %d\n", st.st_nlink);
	printf("st.st_ino = %" PRIu64 "\n", st.st_ino);
	printf("st.st_uid = %d\n", st.st_uid);
	printf("st.st_gid = %d\n", st.st_gid);
	printf("st.st_rdev = %d\n", st.st_rdev);
	printf("st.st_size = %llu\n", st.st_size);
	printf("st.st_blocks = %lld\n", st.st_blocks);
	printf("st.st_blksize = %d\n", st.st_blksize);
	printf("st.st_flags = %d\n", st.st_flags);
	ptr = mmap(ptr, (size_t)st.st_blksize, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 4096);
	printf("ptr = %p\n", ptr);
	printf("ptr = %c\n", ptr[1]);
/*	printf("ptr = %ld\n", (intptr_t)ptr);
*/	if (fd < 0)
		ft_puts("can't open file: a.out (No such file or directory)");
	else
	{
		ft_puts("a.out found");
		close(fd);
	}
	return (0);
}
