/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/10/23 10:56:02 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	try_buffer_without_nl(char *buffer, char **result)
{
	if (buffer[0] && !ft_strchr(buffer, '\n'))
	{
		*result = get_from_buffer(buffer, 0);
		if (!*result)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;

	if (fd < 0)
		return (0);
	result = NULL;
	if (buffer[0] && ft_strchr(buffer, '\n'))
		return (get_from_buffer(buffer, 0));
	if (!try_buffer_without_nl(buffer, &result))
		return (result);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (buffer[0] && ft_strchr(buffer, '\n'))
			return (get_from_buffer(buffer, result));
		if (buffer[0] && !ft_strchr(buffer, '\n'))
		{
			result = get_from_buffer(buffer, result);
			if (!result)
				return (result);
		}
	}
	return (result);
}
