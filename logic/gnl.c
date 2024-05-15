#include "get_next_line.h"

static char *make_line(int fd, char *buffer, char *storage)
{
	int read_bytes;
	char *temp;

	read_bytes = 1;
	
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes == -1)
			return NULL;
		else if (read_bytes == 0)
			break ;
		if (!storage)
			storage = ft_strdup("");

		temp = storage; 
		// printf("temp : %s\n", temp);
		storage = ft_strjoin(temp, buffer);
		
		free(temp);
		
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (storage);
}

static char *extract(char *line) {
// char *extract(char *line) {
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[count + 1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

// int process_file() {
	
//     int fd; 
//     char buffer[BUFFER_SIZE];
//     char *line;
//     char *storage = NULL;

//     ssize_t read_bytes;
// 	read_bytes = 1;
    
//     fd = open("file1.ber", O_RDONLY);

//     while (read_bytes > 0) {
//         line = make_line(fd, buffer, storage); 
//         if (strchr(line, '\n') || line != NULL) {
//             storage = extract(line);
//             printf("storage : %s\n", storage);
//             printf("line after traitement: %s\n", line);
//         }
//         free(line); 
//     }
//     free(storage);
// 	close (fd);
//     return 0;
// }

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*storage;

    // fd = open("file1.ber", O_RDONLY);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = make_line(fd, buffer, storage);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	storage = extract(line);
    // printf("line after traitement: %s\n", line);
	return (line);
}