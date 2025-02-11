/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:55 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/11 16:09:21 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# define READ 0
# define WRITE 1

# include "libft.h"
# include "pipex.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pip
{
	char	**matrix;
	char	*path;
	int		pip[2];
	int		cmds_size;
	int		n;
}			t_pip;

void		data_finish(t_pip *data);
char		**ft_split_shell(char const *s);
char		*extract_word_2(char const *str);
int			is_valide(const char *s);
void		free_matrix(char **matrix);
char		*helper_path(char *str, char *cmd, int size);
char		*debug_okda(char **env, char *cmd);
void		p_error(char *str, int status);
char		*get_next_line(int fd);
void		middle_proc(t_pip *data, int i, char **env, int ac);
void		process_handle(t_pip *data, char **av, int ac, char **envp);
int			ft_strcmp(char *str, char *str2);
void		init_data(t_pip *data, int ac, char **av, char **envp);
void		proc_1(t_pip *data, char **av, char **envp);
void		proc_finale(t_pip *data, char **av, char **envp, int ac);
#endif