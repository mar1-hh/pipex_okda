/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:36:50 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/07 22:47:44 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	p_error(char *str, int status)
{
	perror(str);
	exit(status);
}
