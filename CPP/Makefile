ECHO		=	/bin/echo -e
DEFAULT		=	"\e[0m"
BOLD_T		=	"\e[1m"
DIM_T		=	"\e[2m"
UNDLN_T		=	"\e[4m"
BLACK_C		=	"\e[30m"
RED_C		=	"\e[31m"
GREEN_C		=	"\e[32m"
YELLO_C		=	"\e[33m"
BLUE_C		=	"\e[34m"
MAGEN_C		=	"\e[35m"
CYAN_C		=	"\e[36m"
WHITE_C		=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

COLOR_THEME	=	$(BLUE_C)
DEBUG_THEME	=	$(CYAN_C)
TESTS_THEME	=	$(RED_C)

NAME		=	a.out # Name of the executable
ROOT_PATH	=	./
SRC_NAME	=	src
INCL_NAME	=	inc
TESTS_NAME	=	tests
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
TESTS_PATH	=	$(ROOT_PATH)$(TESTS_NAME)

SRC			=	print.cpp # All your source files

CXX			=	g++
SRCS		=	$(SRC:%=$(SRC_PATH)/%) $(SRC_PATH)/main.cpp
OBJ			=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra -Werror -I $(INCL_PATH) -std=c++17
DEBUG_FLAGS	=	-g3 -gdwarf-4

all: message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____        _ _     _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| __ ) _   _(_) | __| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \| | | | | |/ _\` |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_) | |_| | | | (_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|____/ \__,_|_|_|\__,_|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	@make fclean -C $(TESTS_PATH) -s SRC="$(SRC)" COLOR_THEME="$(RED_C)"
	@$(RM) $(OBJ) && \
		$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.* && \
		$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"Valgrind files"$(DEFAULT)

fclean:	clean
	@$(RM) $(NAME) && \
		$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) $(BOLD_T)$(RED_C)"DELETED: "$(DEFAULT) $(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re: fclean all

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: all
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

tests_run: clean
	@make -C $(TESTS_PATH) -s \
		SRC="$(SRC)" \
		COLOR_THEME="$(TESTS_THEME)"
	@$(ECHO) $(TESTS_THEME)""
	@gcovr --exclude tests/

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "$(CXX) $(CXXFLAGS) -c "$<$(COLOR_THEME)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"$(CXX) $(CXXFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all message clean fclean re debug tests_run