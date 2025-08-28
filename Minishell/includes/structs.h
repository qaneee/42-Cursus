/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipogodae <ipogodae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:15:52 by ipogodae          #+#    #+#             */
/*   Updated: 2025/08/28 12:17:06 by ipogodae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef int				t_bool;
# define TRUE 1
# define FALSE 0

# define STDIN_FILENO  0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

typedef struct s_env	t_env;

typedef enum e_token_type
{
	TOKEN_UNKNOWN,
	TOKEN_ARG,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND_OUT,
	TOKEN_REDIR_ERR,
	TOKEN_REDIR_APPEND_ERR,
	TOKEN_HEREDOC,
}	t_token_type;

typedef struct s_char_vector
{
	char	*data;
	size_t	size;
	size_t	capacity;
}	t_char_vector;

void	init_string(t_char_vector *v);
void	clear_string(t_char_vector *v);
int		push_back_char(t_char_vector *v, char c);
void	copy_string(t_char_vector *dst, t_char_vector src);

typedef struct s_token
{
	char			*value;
	t_token_type	type;
}	t_token;

void	init_token(t_token *t);
void	clear_token(t_token *t);
void	assign_token(t_token *t, char *line);
void	print_token(t_token *t);
size_t	get_token_length(t_token_type type);

typedef struct s_token_vector
{
	t_token	*data;
	size_t	size;
	size_t	capacity;
}	t_token_vector;

void	init_tokens(t_token_vector *v);
void	clear_tokens(t_token_vector *v);
int		push_back_token(t_token_vector *v, t_token_type type, char *value);
int		copy_tokens(t_token_vector *dst, t_token_vector src);

// TODO: maybe 3-state enum would be enough
typedef struct s_parse_state
{
	t_bool	in_single_quotes;
	t_bool	in_double_quotes;
	t_bool	in_curly_braces;
}	t_parse_state;

void	init_parse_state(t_parse_state *s);
t_bool	is_state_initial(t_parse_state state);

typedef struct s_command
{
	t_token_vector	arguments;
	t_bool			is_command_builtin;
	char			*command_path;
	char			*in_file;
	char			*out_file;
	char			*heredoc;
	char			*heredoc_content;
	char			*err_file;
	t_bool			is_out_append;
	t_bool			is_err_append;
	int				read_pipe;
	int				write_pipe;
	int				child_process_pid;
	t_bool			is_dummy;
}	t_command;

void	init_command(t_command *c);
int		clear_command(t_command *c);
void	execute_command(t_command *c);
void	print_command(t_command *c);
void	copy_command(t_command *dst, t_command src);
t_bool	is_command_complete(t_command *c);

typedef struct s_command_vector
{
	t_command	*data;
	size_t		size;
	size_t		capacity;
}	t_command_vector;

void	init_commands(t_command_vector *v);
void	clear_commands(t_command_vector *v);
int		push_back_command(t_command_vector *v, t_command command);

// TODO: maybe move somewhere else
char	*process_raw_token(char *raw_token, t_env *env);

// TODO: maybe move somewhere else
int		update_string_field(char **field, char *new_value);

#endif
