/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:36:34 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/11 16:10:57 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_proc(t_pip *data, int i, char **env, int ac)
{
	int	j;

	(void)ac;
	data[i].n = fork();
	if (!data[i].n)
	{
		j = i + 1;
		while (j < data->cmds_size)
		{
			close(data[j].pip[READ]);
			close(data[j].pip[WRITE]);
			j++;
		}
		close(data[i - 1].pip[WRITE]);
		close(data[i].pip[READ]);
		dup2(data[i - 1].pip[READ], 0);
		close(data[i - 1].pip[READ]);
		dup2(data[i].pip[WRITE], 1);
		close(data[i].pip[WRITE]);
		execve(data[i].path, data[i].matrix, env);
		exit(1);
	}
}

void	process_handle(t_pip *data, char **av, int ac, char **envp)
{
	int	i;

	i = 0;
	while (i < data->cmds_size)
	{
		if (!i)
			proc_1(data, av, envp);
		else if (i == data->cmds_size - 1)
			proc_finale(data, av, envp, ac);
		else
			middle_proc(data, i, envp, ac);
		if (i)
		{
			close(data[i - 1].pip[READ]);
			close(data[i - 1].pip[WRITE]);
		}
		i++;
	}
}

void	init_data(t_pip *data, int ac, char **av, char **envp)
{
	int	i;
	int	flag;

	flag = 2;
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		flag++;
	i = 0;
	while (i < ac - (flag + 1))
	{
		data[i].matrix = ft_split_shell(av[i + flag]);
		data[i].path = debug_okda(envp, data[i].matrix[0]);
		pipe(data[i].pip);
		data[i].cmds_size = ac - (flag + 1);
		i++;
	}
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] || str2[i])
	{
		if (str[i] > str2[i])
			return (1);
		else if (str[i] < str2[i])
			return (-1);
		i++;
	}
	return (0);
}
