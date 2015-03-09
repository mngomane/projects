/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mngomane <mngomane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:24:34 by mngomane          #+#    #+#             */
/*   Updated: 2015/02/02 01:24:34 by mngomane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../../libfts/incs/libfts.h"
# include "../../asm_folder/incs/asm.h"

int					fill_entry(t_entry *ent);
void				link_instruction(t_instruction **i, char *start, char *end);
void				link_param(struct s_parameter **p, char *start, char *end);
int					ft_pstrcmp(const char *s1, const char *e1, const char *s2, const char *e2);
char				*ft_pstrend(const char *str);
t_pstring			*init_pstring(char *start, char *end);
t_file				*declare_t_file(void);
t_cmd				*declare_t_cmd(void);
t_pstring			*delcare_t_pstring(void);
struct s_parameter	*declare_s_parameter(void);
t_instruction		*declare_t_instruction(void);
t_entry				*declare_t_entry(void);
t_jmp				*declare_t_jmp(void);
void				free_t_pstring(t_pstring **tmp);
void				free_t_cmd(t_cmd **tmp);
void				free_s_parameter(struct s_parameter **tmp);
void				free_t_instruction(t_instruction **tmp);
void				free_t_file(t_file **tmp);
void				free_t_entry(t_entry **tmp);
void				free_t_jmp(t_jmp **tmp);
void				putpstr(t_pstring *pstring);

#endif
