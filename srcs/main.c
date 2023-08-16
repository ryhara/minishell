/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryhara <ryhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:59:23 by ryhara            #+#    #+#             */
/*   Updated: 2023/08/10 15:59:23 by ryhara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum;
	(void)ucontext;
	(void)info;
	printf("ctrl+c\n"); // Move to a new line
	// rl_on_new_line(); // Regenerate the prompt on a newline
	// rl_replace_line("", 0); // Clear the previous text
	// rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**list;
	t_env	*env_head;
	struct sigaction	act1;

	(void)argc;
	(void)argv;
	env_head = env_init(envp);
	if (env_head == NULL)
		return (1);
	sigemptyset(&act1.sa_mask);
	act1.sa_sigaction = signal_handler;
	act1.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act1, NULL);
	while (1)
	{
		line = readline("minishell $> ");
		if (line == NULL)
		{
			head_free_all(env_head);
			free(line);
			break ;
		}
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		list = ft_split(line, ' ');
		if (list == NULL)
			break ;
		add_history(line);
		free(line);
		select_commands(list, env_head);
		free_list(list);
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q minishell");
}