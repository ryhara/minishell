/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:26:17 by shmorish          #+#    #+#             */
/*   Updated: 2023/09/10 17:52:29 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <fcntl.h>

typedef struct s_parser	t_parser;
typedef struct s_file	t_file;

int		**make_pipefd(t_parser *parser_head);
void	close_pipefd(int pipefd[2]);
void	redirect_output(t_file *file_head, t_data *data, int pipefd[2]);
void	redirect_input(t_file *file_head, t_data *data, int pipefd[2]);
void	free_pipefd(int **pipefd);
#endif
