NAME    :=  libftprintf.a

CC      :=  gcc
CFLAGS  :=  -Wall -Wextra -Werror
CFLAGS  +=  -I includes/

SOURCE_FILES =  libft/btree_add_node.c\
                libft/btree_apply_inorder.c\
                libft/btree_apply_postorder.c\
                libft/btree_apply_preorder.c\
                libft/btree_create_node.c\
                libft/ft_atoi.c\
                libft/ft_bzero.c\
                libft/ft_isalnum.c\
                libft/ft_isalpha.c\
                libft/ft_isascii.c\
                libft/ft_isdigit.c\
                libft/ft_isprint.c\
                libft/ft_itoa.c\
                libft/ft_lstadd.c\
                libft/ft_lstappend.c\
                libft/ft_lstdel.c\
                libft/ft_lstdelone.c\
                libft/ft_lstiter.c\
                libft/ft_lstmap.c\
                libft/ft_lstnew.c\
                libft/ft_memalloc.c\
                libft/ft_memccpy.c\
                libft/ft_memchr.c\
                libft/ft_memcmp.c\
                libft/ft_memcpy.c\
                libft/ft_memdel.c\
                libft/ft_memmove.c\
                libft/ft_memset.c\
                libft/ft_putchar.c\
                libft/ft_putchar_fd.c\
                libft/ft_putendl.c\
                libft/ft_putendl_fd.c\
                libft/ft_putnbr.c\
                libft/ft_putnbr_fd.c\
                libft/ft_putstr.c\
                libft/ft_putstr_fd.c\
                libft/ft_strcat.c\
                libft/ft_strchr.c\
                libft/ft_strclr.c\
                libft/ft_strcmp.c\
                libft/ft_strcpy.c\
                libft/ft_strdel.c\
                libft/ft_strdup.c\
                libft/ft_strequ.c\
                libft/ft_striter.c\
                libft/ft_striteri.c\
                libft/ft_strjoin.c\
                libft/ft_strlcat.c\
                libft/ft_strlen.c\
                libft/ft_strmap.c\
                libft/ft_strncat.c\
                libft/ft_strncmp.c\
                libft/ft_strncpy.c\
                libft/ft_strndup.c\
                libft/ft_strnequ.c\
                libft/ft_strnew.c\
                libft/ft_strnstr.c\
                libft/ft_strrchr.c\
                libft/ft_strsplit.c\
                libft/ft_strsplitlist.c\
                libft/ft_strstr.c\
                libft/ft_strsub.c\
                libft/ft_strtrim.c\
                libft/ft_tolower.c\
                libft/ft_toupper.c\
                libft/ft_itoa_base.c\
                libft/ft_imaxtoa.c\
                ft_build.c\
                ft_is.c\
                ft_parse.c\
                ft_printf.c\
                ft_set.c\
                ft_conv.c\
                ft_str.c

O_FILES = $(SOURCE_FILES:.c=.o)

.PHONY = all fclean clean re

all: $(NAME)

$(O_FILES):%.o: %.c
	@gcc $(SOURCE_FILES) -c $(CFLAGS)$< -o $@

$(NAME): $(O_FILES)
	@ar rc $(NAME) $(O_FILES)

clean:
	@rm -rf $(O_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all