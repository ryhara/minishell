/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:59:35 by morishitash       #+#    #+#             */
/*   Updated: 2023/08/18 19:59:53 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pipe_error_exit(int *pipefd)
{
	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(1);
	}
}
