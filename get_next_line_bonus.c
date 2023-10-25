/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: 2023/10/25 07:33:25 by abareux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	try_buffer_without_nl(char *buffer, char **result, int fd)
{
	*result = NULL;
	if (fd < 0)
		return (0);
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
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*result;
	int			buffer_result;

	if (!try_buffer_without_nl(buffer[fd], &result, fd))
		return (result);
	if (buffer[fd][0] && ft_strchr(buffer[fd], '\n'))
		return (get_from_buffer(buffer[fd], 0));
	buffer_result = read(fd, buffer[fd], BUFFER_SIZE);
	while (buffer_result > 0)
	{
		if (buffer[fd][0] && ft_strchr(buffer[fd], '\n'))
			return (get_from_buffer(buffer[fd], result));
		if (buffer[fd][0] && !ft_strchr(buffer[fd], '\n'))
		{
			result = get_from_buffer(buffer[fd], result);
			if (!result)
				return (result);
		}
		buffer_result = read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (buffer_result)
		return (free(result), NULL);
	return (result);
}
