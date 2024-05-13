#include "get_next_line.h"

//  pseudo code 
//  verifier que la map est rectangle
//  verifier que la map a des murs partout
//  verifier que la map contient seulement les 
//  caracteres 1 0 E P C 
// verfier que la map n est pas une ligne

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;
 
	p = (unsigned char *)b;
	while (length--)
    {
        *p++ = (unsigned char)c;
        // printf("memset en cours...");
    }
    //  printf("memset termine !...");
	return (b);
}

t_game *malloc_game()
{
    t_game *game = (t_game *)malloc(sizeof(t_game));
    
    if (game == NULL)
    {
        perror("Allocation de mémoire pour game a échoué");
        return NULL;
    }
    return game;
}

int     calculate_len(t_game *game, char *line)
{
    int len;

    len = 0;
    while (line[len])
        len++;
    game->map_width = len;
    printf("len : %d\n", len);
    return (0);
}

static int	save_line_in_map(t_game *game, char *line)
{
    char **temp;
    int i;
    int height;

    if (!line)
        return (0);
    height = game->map_height;
    height++; 

    temp = (char **)malloc(sizeof(char *) * (height + 1));
    temp[height] = NULL;
    i = 0;

    while (i < height - 1)
    {
        temp[i] = game->map[i];
        i++;
    }
      
    temp[i] = line;
    if (game->map != NULL)
        free(game->map);
    game->map = temp;
    game->map_height = height;
    printf("save map done\n");
    return (1);
}

int     check_rectangle(t_game *game) 
{
    
    int height;
    height = game->map_height;
    printf("map after treatement\n");
    int i = 0;
    while (i < height)
    {
        printf("%c\n", game->map[i][0]); 
        i++;
    }
    return (1);
}

int     check_walls_horizontal(t_game *game) 
{
    int height;
    int len;
    int count;
    int i;

    len = game->map_width;    
    height = game->map_height;
 
    i = 0;
    count = 1;
    while (i < len)
    {
        if (game->map[height - 1][i] == '1' && game->map[0][i] == '1')
            count++;
        i++;
    }
    if (count == len)
        printf("horizontal walls ok !\n");
    else 
        printf("horizontal walls ISSUE\n");
    return (1);
}

int     check_walls_vertical(t_game *game)
{
    int height;
    int len; 
    int count;
    int i;

    len = game->map_width - 1; 
    height = game->map_height;
    i = 0;
    count = 0;

    while (i < height)
    {
        if (game->map[i][len - 1] == '1' && game->map[i][0] == '1')
            count++;
        i++;
    }
    if (count == height)
        return (1);
    else 
        return (0);
} 

int     check_allowed_caracters(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map_height) 
    {
        x = 0;
        while(x < game->map_width - 1)
        {
            if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
                game->map[y][x] != 'P' && game->map[y][x] != 'E' && 
                game->map[y][x] != 'C')
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int check_if_rectancle(t_game *game)
{
    int init_len = 0;
    int y = 1;
    int x = 0;

    while (game->map[0][init_len])
        init_len++;
    printf("init len %d\n", init_len);
    while (y < game->map_height) 
    {
        x = 0;
        while(game->map[y][x])
            x++;
        if (x == init_len)
            printf("perfect\n");
        else 
        {
            printf("error at line = %d\n", y);
            //corriger le return (0) pour la derniere ligne
        }
         
        y++;
    }
    printf("y = %d\n", y); 
    printf("MP = %d\n ", game->map_height); 
    if (y == game->map_height)
    {
        x = 0;
        while(game->map[game->map_height - 1][x])
            x++;
        if (x == init_len - 1)
            printf("last line ok\n");
        else 
        {
            printf("error\n");
            return (0);
        }
    }
    return (1);
}

int check_extension_file_name(char *name)
{
    const char *needle = ".ber";

    int i;
    int y;
    i = 0;
    y = 0;
    while (name[i])
    {
        if (name[i] == needle[y])
            y++;
        i++;
    }
    if (y == 4 && name[i] == '\0')
        printf("extension ok");
    return (0);
}
    

int check_map(t_game *game)
{
    check_walls_horizontal(game);
    check_walls_vertical(game);
    check_allowed_caracters(game);
    check_if_rectancle(game);
    return (0);
}