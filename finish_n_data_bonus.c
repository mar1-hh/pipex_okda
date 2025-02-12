/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_n_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:46:45 by msaadaou          #+#    #+#             */
/*   Updated: 2025/02/12 15:50:11 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	finish_n_data(t_pip *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (data[i].matrix)
			free_matrix(data[i].matrix);
		if (data[i].path)
			free(data[i].path);
		close(data[i].pip[0]);
		close(data[i].pip[1]);
		i++;
	}
	exit(1);
}
