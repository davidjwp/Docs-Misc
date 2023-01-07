/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
*   Created: 2022/09/22 13:38:33 by djacobs           #+#    #+#             */
/*   Updated: 2022/11/10 16:17:44 by djacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

include <stdio.h>
int ft_strlen(char *src)
{
  int src_leng;
  
  src_leng = 0;
  while(src[src_leng] != '\0')
  {
      src_leng++;
  }
  
  return (src_leng);
}
unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
        unsigned int    j;
        unsigned int    i;
        unsigned int    src_leng;
        unsigned int    dest_leng;

        j = 0;
        i = 0;
        src_leng = 0;
        dest_leng = 0;
        src_leng = ft_strlen(src);
        
        if(size < dest_leng)
              return(src_leng + size);
        while (src[i] != '\0')
        {
                while (j < size && src[j] != '\0')
                {
                        dest[dest_leng] = src[j];
                        j++;
                }
                i++;
        }
        dest[src_leng + dest_leng] = '\0';
        return (src_leng);



}
int     main(void)
{
        char dest[10] = "123";
        char src[10]  = "4567";
        unsigned int size;


        printf("dest: %s, src: %s\n", dest, src);

        size = 0;
        printf("size: %u\n", size);
        printf("og_strlcat return: %zu | dest: %s \n", strlcat(dest, src, size), dest);
        strcpy(dest, "123"); // Reset the dest str
        printf("ft_strlcat return: %u | dest: %s \n", ft_strlcat(dest, src, size), dest);

        size = 1;
        printf("size: %u\n", size);
        printf("og_strlcat return: %zu | dest: %s \n", strlcat(dest, src, size), dest);
        strcpy(dest, "123"); // Reset the dest str
        printf("ft_strlcat return: %u | dest: %s \n", ft_strlcat(dest, src, size), dest);

        size = 2;
        printf("size: %u\n", size);
        printf("og_strlcat return: %zu | dest: %s \n", strlcat(dest, src, size), dest);
        strcpy(dest, "123"); // Reset the dest str
        printf("ft_strlcat return: %u | dest: %s \n", ft_strlcat(dest, src, size), dest);

        size = 4;
        printf("size: %u\n", size);
        printf("og_strlcat return: %zu | dest: %s \n", strlcat(dest, src, size), dest);
        strcpy(dest, "123"); // Reset the dest str
        printf("ft_strlcat return: %u | dest: %s \n", ft_strlcat(dest, src, size), dest);

        size = 6;
        printf("size: %u\n", size);
        printf("og_strlcat return: %zu | dest: %s \n", strlcat(dest, src, size), dest);
        strcpy(dest, "123"); // Reset the dest str
        printf("ft_strlcat return: %u | dest: %s \n", ft_strlcat(dest, src, size), dest);
}

