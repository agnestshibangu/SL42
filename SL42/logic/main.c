#include "get_next_line.h"

int main() {

    t_game  game;
    int fd; 
    char *treated_line;

    char *name_file;
    name_file = "file1.ber";

    check_extension_file_name(name_file);
    malloc_game();
    fd = open(name_file, O_RDONLY);
    ft_memset(&game, 0, sizeof(t_game));
    // malloc map
    while (1) {
        treated_line = get_next_line(fd);
        // printf("here %s", treated_line);
        save_line_in_map(&game, treated_line);
        if (!treated_line)
			break ;
    }
   
    calculate_len(&game, game.map[0]);
    
    check_walls_vertical(&game);
    check_allowed_caracters(&game);
    check_if_rectancle(&game);
    printf("check rectangle 1 : %d\n", check_if_rectancle(&game));
    
    return 0;
}
 