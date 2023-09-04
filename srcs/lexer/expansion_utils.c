/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:27:24 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/31 17:53:35 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	expansion_free(char *before_str, char *after_str, char *env_val)
{
	free(before_str);
	free(after_str);
	free(env_val);
}

void	expansion_join(t_token *node, char *before, char *after, char *env_val)
{
	char	*tmp_str;

	tmp_str = node->str;
	node->str = ft_strjoin(before, env_val);
	free(tmp_str);
	if (node->str == NULL)
	{
		expansion_free(before, after, env_val);
		return ;
	}
	tmp_str = node->str;
	node->str = ft_strjoin(tmp_str, after);
	free(tmp_str);
	if (node->str == NULL)
	{
		expansion_free(before, after, env_val);
		return ;
	}
	expansion_free(before, after, env_val);
}

bool	count_doller(char *str, size_t *index)
{
	size_t	count_dollar;

	count_dollar = 0;
	while (str[*index] == '$')
	{
		(*index)++;
		count_dollar++;
	}
	if (count_dollar % 2 == 0)
		return (false);
	else
		return (true);
}

bool	expansion_check_doll_end(char *str, size_t *index)
{
	if (!count_doller(str, index))
		return (true);
	if (str[*index] == '\0')
		return (true);
	return (false);
}