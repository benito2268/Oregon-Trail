GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
PURPLE=\033[0;35m
NC=\033[0;0m

run: bin/oregon.exe
	@./bin/oregon.exe

build_d: src/*.cpp src/glad.c
	@printf "${BLUE}[Starting Build Task]${NC}\n"
	@printf "=======================================================\n"
	@printf "${GREEN}[compiling ${PURPLE}main.cpp${GREEN}]${NC}\n"
	if g++ -Wall -g -c -std=c++20 src/main.cpp -I"include/" -o bin/main.obj; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi
	@printf "${NC}\n_________________\n"

	@printf "\n${GREEN}[compiling ${PURPLE}glad.c${GREEN}]${NC}\n"
	if gcc -Wall -g -c -std=c++20 src/glad.c -I"include/" -o bin/glad.obj; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi
	@printf "${NC}\n_________________\n"

	@printf "\n${GREEN}[compiling ${PURPLE}window.cpp${GREEN}]${NC}\n"
	if gcc -Wall -g -c -std=c++20 src/window.cpp -I"include/" -o bin/window.obj; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi
	@printf "${NC}\n_________________\n"

	@printf "\n${GREEN}[compiling ${PURPLE}engine.cpp${GREEN}]${NC}\n"
	if gcc -Wall -g -c src/engine.cpp -I"include/" -o bin/engine.obj; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi
	@printf "${NC}\n_________________\n"

	@printf "\n${GREEN}[compiling ${PURPLE}renderer.cpp${GREEN}]${NC}\n"
	if gcc -Wall -g -c src/renderer.cpp -I"include/" -o bin/renderer.obj; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi
	@printf "${NC}\n_________________\n"

	@printf "\n${GREEN}[linking object files]${NC}\n"
	if g++ bin/*.obj -o bin/oregon.exe -L"lib/debug" -lglfw3 -lopengl32 -lgdi32 -llibstdc++; then printf "${GREEN}[OK]"; else printf "${RED}[FAILED]${NC}"; fi

	@printf "${NC}\n=======================================================\n"
	@printf "${BLUE}[build finished]${NC}"

clean:
	rm bin/*.obj
	rm bin/*.exe
