/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rondom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:02:27 by hbel-hou          #+#    #+#             */
/*   Updated: 2022/01/10 18:35:10 by hbel-hou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int *buff;
    int num;
    int j;
    int i;
    int k;
    int lenght;
    int rand1;

    j = 0;
    i = 0;
    k = 0;
    buff = malloc(sizeof(int) * atoi(av[1]));
    if (ac == 2)
    {
        lenght = atoi(av[1]);
        srand(time(NULL));
        if (lenght <= 300)
            rand1 = 800;
        else
            rand1 = 15000;
        while (1)
        {
            num = rand() % (rand1 + 0 - 0) + 0;
            j = -1;
            while (++j <= i)
                if (buff[j] == num)
                    break;
            if (buff[j] != num)
            {
                printf("%d ", num);
                buff[i] = num;
                k++;
            }
            if (k == lenght)
                break;
            i++;
        }
    }
}