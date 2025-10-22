/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:19:40 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/22 23:23:46 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int     i = 0;
    char    *string = NULL;
    int     j = 1;
    int     number_of_arg;


    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else if (argc != 1)
    {
        number_of_arg = argc;
        while (j < number_of_arg)
        {
            string = argv[j];
            i = 0;
            while (string[i])
            {
                std::cout << (char)toupper(string[i]); 
                i++;
            }
            j++;
        }
        std::cout << std::endl;
    }
    return (0);    
}
