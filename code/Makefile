# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aartiges <aartiges@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:10:29 by aartiges          #+#    #+#              #
#    Updated: 2022/09/29 02:03:21 by aartiges         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

################################################################################
##                       Compilation Environnement                            ##
################################################################################

NAME	:=	ft_containers
CC		:=	c++
CFLAGS	:=	-Wall -Werror -Wextra -std=c++98

################################################################################
##                               Présentation                                 ##
################################################################################

COLOR_NORM		:=	\033[0m
COLOR_RED		:=	\033[31m
COLOR_PURPLE	:=	\033[35m


################################################################################
##                             Sources Files                                  ##
################################################################################

# Main

MAIN_SRC			:=	main.cpp
MAIN_OBJ			:=	$(MAIN_SRC:.cpp=.o) main_std.o


# Tests

DIR_TESTING		:=	./bin
DIR_SRC_TEST	:=	./test
SRCS_TEST		:=	$(DIR_SRC_TEST)/map/test_map_general.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_begin.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_clear.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_count.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_empty.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_end.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_equal_range.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_erase.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_find.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_get_allocator.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_insert.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_key_comp.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_lower_bound.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_map.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_max_size.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_non_member_operators.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_non_member_swap.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_operator=.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_operator[].cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_rbegin.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_rend.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_size.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_swap.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_upper_bound.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/map/test_map_value_comp.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_compatible.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_empty.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_pop.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_push.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_size.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/stack/test_stack_top.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/test_equal.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/test_is_integral.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/test_iterator_traits.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/test_lexicographical_compare.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/test_make_pair_and_pair.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_general.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_assign.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_at.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_back.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_begin.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_capacity.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_clear.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_empty.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_end.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_erase.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_front.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_get_allocator.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_insert.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_max_size.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_non_member_operators.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_non_member_swap.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_operator=.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_operator[].cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_pop_back.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_push_back.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_rbegin.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_rend.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_reserve.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_resize.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_size.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_swap.cpp
SRCS_TEST		+=	$(DIR_SRC_TEST)/vector/test_vector_vector.cpp

TMP_TEST		:=	$(SRCS_TEST:.cpp=.cpp.xxx)

# Code

INCLUDES			:=	./includes

HEADERS				:=	$(INCLUDES)/algorithm.hpp
HEADERS				+=	$(INCLUDES)/containers/map/map.hpp
HEADERS				+=	$(INCLUDES)/containers/map/mapIterator.hpp
HEADERS				+=	$(INCLUDES)/containers/map/pair.hpp
HEADERS				+=	$(INCLUDES)/containers/map/tree.hpp
HEADERS				+=	$(INCLUDES)/containers/stack.hpp
HEADERS				+=	$(INCLUDES)/containers/vector/vector.hpp
HEADERS				+=	$(INCLUDES)/containers/vector/vectorIterator.hpp
HEADERS				+=	$(INCLUDES)/iterators/category.hpp
HEADERS				+=	$(INCLUDES)/iterators/iterators_traits.hpp
HEADERS				+=	$(INCLUDES)/iterators/reverse_iterator.hpp
HEADERS				+=	$(INCLUDES)/traits.hpp

# Get command for leaks

LEAKS				=	$(shell which valgrind >/dev/null; RETVAL=$$?; if [ $$RETVAL -eq 0 ]; then echo 'valgrind'; else echo 'leaks -q -atExit --'; fi)

# File That will content the times of exec

TIME_FILE			:=	./time


################################################################################
##                                 Rules                                      ##
################################################################################

all	:	$(NAME) $(HEADERS) Makefile

$(NAME)	:	$(MAIN_OBJ) $(HEADERS) Makefile
	$(CC) $(CFLAGS) -o $(NAME) main.o
	$(CC) $(CFLAGS) -o $(NAME)_std main_std.o

%.o : %.cpp  $(HEADERS) Makefile
	${CC} ${CFLAGS} -D NAMESPACE=ft -c $< -o $@

%_std.o : %.cpp  $(HEADERS) Makefile
	${CC} ${CFLAGS} -D NAMESPACE=std -c $< -o $@

# Execute all tests for a main file.cpp
%.cpp.xxx:
# Create variables for testing
	$(eval TEST_FILE		:= $(basename $@))
	$(eval TEST_NAME		:= $(notdir $(basename $(TEST_FILE))))
	$(eval TEST_REDIR		:= >_ft 2>_ft2)
	$(eval TEST_REDIR_STD	:= >_std 2>_std2)

	@printf "Testing of $(COLOR_PURPLE)$(TEST_NAME) $(COLOR_NORM)\n"
# Compiling with sanitizer and test
	@$(CC) $(CFLAGS) -fsanitize=address -D NAMESPACE=ft -o $(DIR_TESTING)/$(TEST_NAME)_ft $(TEST_FILE)
	@./$(DIR_TESTING)/$(TEST_NAME)_ft $(TEST_REDIR);RETVAL=$$?; if [ $$RETVAL -ne 0 ]; then echo "$(COLOR_RED)\tSANITIZER$(COLOR_NORM)"; fi
# Remove the file to stock time
	@rm -rf $(TIME_FILE)
# Compiling with the classic flags
	@$(CC) $(CFLAGS) -D NAMESPACE=ft  -o $(DIR_TESTING)/$(TEST_NAME)_ft  $(TEST_FILE)
	@$(CC)           -D NAMESPACE=std -o $(DIR_TESTING)/$(TEST_NAME)_std $(TEST_FILE)
	@./$(DIR_TESTING)/$(TEST_NAME)_std $(TEST_REDIR_STD)
	@./$(DIR_TESTING)/$(TEST_NAME)_ft  $(TEST_REDIR)
# Print times
	@printf 'std: '; head -n1 $(TIME_FILE)
	@printf ' ft: '; tail -n1 $(TIME_FILE)
	@diff _ft _std; RETVAL=$$?; if [ $$RETVAL -eq 0 ]; then echo "\tOK"; else echo "$(COLOR_RED)\tKO$(COLOR_NORM)"; fi
	@diff _ft2 _std2; RETVAL=$$?; if [ $$RETVAL -ne 0 ]; then echo "$(COLOR_RED)\tKO STDERR$(COLOR_NORM)"; fi
# Check leaks
	@$(LEAKS) ./$(DIR_TESTING)/$(TEST_NAME)_ft $(TEST_REDIR); RETVAL=$$?; if [ $$RETVAL -ne 0 ]; then echo "$(COLOR_RED)\tLEAK$(COLOR_NORM)"; fi

# Create the directory of binaries for tests
$(DIR_TESTING):
	@mkdir -p $(DIR_TESTING)

# Rule that send tests
test:	$(DIR_TESTING) $(TMP_TEST) cleantest

# Remove all files associated with tests
cleantest:
	@rm -rf $(DIR_TESTING) _ft _ft2 _std _std2 $(TIME_FILE)

clean: cleantest
	@rm -rf $(MAIN_OBJ)

fclean: clean
	@rm -rf $(NAME) $(NAME)_std

re	:	fclean all
