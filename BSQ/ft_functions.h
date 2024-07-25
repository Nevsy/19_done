/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nev <nev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:01:36 by sroyer            #+#    #+#             */
/*   Updated: 2024/07/24 22:41:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONS_H
# define FT_FUNCTIONS_H

typedef struct s_point
{
	int	x;
	int	y;
	int	value;
}	t_point;

typedef struct s_settings
{
	int		line_count;
	int		column_count;
	char	empty;
	char	obstacle;
	char	full;
	int		**map;
	t_point	*big;
}	t_settings;

// SETTINGS
int			are_chars_valid(t_settings *settings);
int			are_lens_valid(t_settings *settings);
void		*free_settings(t_settings *settings);
void		*free_settings_until(t_settings *settings, int until);
void		*free_settings_main(t_settings *settings);

// SETTINGS 2
void		are_chars_valid_stdin(t_settings *settings);

// PARSING
t_settings	*parse_stdin(void);
t_settings	*parse_file(char *filepath);

// PARSING HELPER
int			get_file(char *filepath);
int			get_file_size(int file_desc);
void		get_line(int file_desc);
int			column_length_check(t_settings *settings, int count, int line);
char		*get_first_line(int file_desc);

// ERRORS
void		*throw_parse_err(void);

// HELPER
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str);
char		*ft_strdup(char *src);

// MOD SQUARE
void		modify_square(int **tab, t_settings *settings);

// DRAW SQUARE
void		draw_square(int **tab, t_settings *settings, t_point *big);

#endif
