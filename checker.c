/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:54:40 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/01/08 11:35:02 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	i = 0;
	copy = malloc(i + 1);
	if (copy == NULL)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*get_next_line(int fd)
{
	char	save[999999];
	char	buff[1];
	char	*temp;
	int		i;

	i = 0;
	if (fd < 0)
		return (0);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (save[0] == '\0')
		return (0);
	return (ft_strdup(save));
}

int	check_line(char *line, t_list **list, t_list **listb)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_sa_c(*list);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_sb_c(*listb);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ss_c(list, listb);
	else if (ft_strcmp(line, "ra\n") == 0)
		swap_ra_c(list);
	else if (ft_strcmp(line, "rb\n") == 0)
		swap_rb_c(listb);
	else if (ft_strcmp(line, "rr\n") == 0)
		swap_rr_c(list, listb);
	else if (ft_strcmp(line, "rra\n") == 0)
		swap_rra_c(list);
	else if (ft_strcmp(line, "rrb\n") == 0)
		swap_rrb_c(listb);
	else if (ft_strcmp(line, "rrr\n") == 0)
		swap_rrr_c(list, listb);
	else if (ft_strcmp(line, "pa\n") == 0)
		swap_pa_c(list, listb);
	else if (ft_strcmp(line, "pb\n") == 0)
		swap_pb_c(list, listb);
	else
		return (-1);
	return (0);
}

void	get_list_of_instrctions(t_list **list, t_list **listb)
{
	char	*line;

	line = "";
	while (line)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (check_line(line, list, listb) == -1)
		{
			free(line);
			write(1, "Error\n", 7);
			exit(0);
		}
		free(line);
	}
	if (a_is_sorted(*list) == 0)
		ft_putendl_fd("\e[0;32m[OK]", 1);
	else
		ft_putendl_fd("\033[0;31m[KO]", 1);
}

int	main(int ac, char **av)
{
	t_list	*list;
	t_list	*listb;
	char	*line;

	if (check_args(ac, av) == -1 || ac < 3)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	list = creat_list(ac, av);
	listb = creat_list1(ac);
	get_list_of_instrctions(&list, &listb);
}
