/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:36:51 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/08 21:40:14 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "libft.h"
# include "pipex.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	**matrix_1;
	char	**matrix_2;
	char	*path_1;
	char	*path_2;
	int		current_pipe[2];
	int		n;
}			t_data;

char		**ft_split_shell(char const *s);
char		*extract_word_2(char const *str);
int			is_valide(const char *s);
void		free_matrix(char **matrix);
char		*helper_path(char *str, char *cmd, int size);
char		*debug_okda(char **env, char *cmd);
void		p_error(char *str, int status);

#endif