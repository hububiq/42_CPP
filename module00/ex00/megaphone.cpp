/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:19:40 by hgatarek          #+#    #+#             */
/*   Updated: 2025/10/24 19:32:27 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    char    *string = NULL;   

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            string = argv[i];
            for (int j = 0; string[j]; j++)
                std::cout << (char)std::toupper(string[j]);
        }
        std::cout << std::endl;
    }
    return (0);    
}
