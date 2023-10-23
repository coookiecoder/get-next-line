/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   NOOT NOOT MOTHER FUCKER                      :#:  :#:         :#:  :#:   */
/*                                                :#:  :#::#     #::#:  :#:   */
/*   By: an asshole who like to break thing       :#:  :#::#: # :#::#:  :#:   */
/*                                                :##::##: :#:#:#: :##::##:   */
/*   Created: the-day-it-was created by UwU        :####:  :##:##:  :####:    */
/*   Updated: the-day-it-was updated by UwU                                   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strchr(char *s, char c)
{
	int	cursor;

	cursor = 0;
	while (*(s + cursor))
	{
		if (*(s + cursor) == c)
			return (s + cursor);
		cursor++;
	}
	if (*(s + cursor) == c)
		return (s + cursor);
	return (0);
}

void	move_buffer_left(char buffer[BUFFER_SIZE + 1])
{
	int	cursor;
	int	copy_cursor;

	cursor = 0;
	if (!ft_strchr(buffer, '\n'))
		while (cursor < BUFFER_SIZE)
			buffer[cursor++] = 0;
	else
	{
		while (buffer[cursor] != '\n')
			cursor++;
		copy_cursor = 0;
		while (buffer[cursor + copy_cursor])
		{
			buffer[copy_cursor] = buffer[cursor + copy_cursor + 1];
			copy_cursor++;
		}
		while (copy_cursor < BUFFER_SIZE + 1)
			buffer[copy_cursor++] = 0;
	}
	return ;
}

char	*ft_malloc(int size, char *result)
{
	char	*buffer;
	int		cursor;

	if (!result)
	{
		buffer = malloc(size);
		*buffer = '\0';
		return (buffer);
	}
	cursor = 0;
	while (*(result + cursor))
		cursor++;
	buffer = malloc(cursor + size);
	if (!buffer)
		return (free(result), buffer);
	cursor = 0;
	while (*(result + cursor))
	{
		*(buffer + cursor) = *(result + cursor);
		cursor++;
	}
	*(buffer + cursor) = '\0';
	return (free(result), buffer);
}

char	*get_from_buffer(char buffer[BUFFER_SIZE + 1], char *result)
{
	int		cursor;
	int		offset;

	cursor = 0;
	while (cursor < BUFFER_SIZE && buffer[cursor] != '\n')
		cursor++;
	if (buffer[cursor] == '\n')
		result = ft_malloc(cursor + 2, result);
	else
		result = ft_malloc(cursor + 1, result);
	if (!result)
		return (result);
	cursor = 0;
	offset = ft_strlen(result);
	while (cursor < BUFFER_SIZE && buffer[cursor] != '\n')
	{
		*(result + cursor + offset) = buffer[cursor];
		cursor++;
	}
	if (buffer[cursor] == '\n')
		*(result + cursor++ + offset) = '\n';
	*(result + cursor + offset) = '\0';
	move_buffer_left(buffer);
	return (result);
}
