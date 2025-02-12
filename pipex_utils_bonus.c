/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:24:37 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/12 13:42:05 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*helper_path(char *str, char *cmd, int size)
{
	char	*complete_path;
	char	*command_path;
	char	**commands_path;
	int		i;

	complete_path = ft_substr(str, size, ft_strlen(str) - size);
	commands_path = ft_split(complete_path, ':');
	i = 0;
	while (commands_path[i])
	{
		command_path = ft_strjoin(commands_path[i], cmd);
		if (!access(command_path, X_OK))
		{
			free_matrix(commands_path);
			free(complete_path);
			free(cmd);
			return (command_path);
		}
		free(command_path);
		i++;
	}
	free_matrix(commands_path);
	free(complete_path);
	free(cmd);
	return (NULL);
}

char	*debug_okda(char **env, char *cmd)
{
	char	*str;
	int		i;

	if (!cmd)
		return (NULL);
	if (!access(cmd, X_OK))
		return (ft_strdup(cmd));
	if (cmd[0] != '/')
		cmd = ft_strjoin("/", cmd);
	i = 0;
	while (env[i])
	{
		str = ft_strnstr(env[i], "PATH=", ft_strlen("PATH="));
		if (str)
			return (helper_path(str, cmd, ft_strlen("PATH=")));
		i++;
	}
	return (NULL);
}

void	t_error(char *str, t_pip *data, int status)
{
	data_finish(data);
	perror(str);
	exit(status);
}
