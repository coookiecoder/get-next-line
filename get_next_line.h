/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/10/23 10:51:38 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//define if not specified in the compiler command

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <malloc.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
char	*get_from_buffer(char buffer[BUFFER_SIZE + 1], char *result);

#endif
