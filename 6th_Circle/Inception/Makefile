C_CYAN = \033[0;96m
C_GREEN = \033[0;92m
C_RESET = \033[0m

DOCKER_COMPOSE := ./srcs/docker-compose.yml

MOUNTPOINT = /home/laian/data
WORDPRESS_DB_DIR = /wordpress_database
WORDPRESS_FS_DIR = /wordpress_files

all: re

build:

	@echo "$(C_CYAN)Creating volume mountpoints...$(C_RESET)"

	@if [ ! -d $(MOUNTPOINT)$(WORDPRESS_DB_DIR) ]; then\
		mkdir -p $(MOUNTPOINT)$(WORDPRESS_DB_DIR);\
	fi
	@if [ ! -d $(MOUNTPOINT)$(WORDPRESS_FS_DIR) ]; then\
		mkdir -p $(MOUNTPOINT)$(WORDPRESS_FS_DIR);\
	fi

	@echo "$(C_CYAN)Building images...$(C_RESET)"

	docker compose -f $(DOCKER_COMPOSE) build

	@echo "$(C_GREEN)Done!$(C_RESET)"

up: build


	@echo "$(C_CYAN)Starting containers...$(C_RESET)"

	docker compose -f $(DOCKER_COMPOSE) up --detach

	@echo "$(C_GREEN)Done!$(C_RESET)"

down:
	docker compose -f $(DOCKER_COMPOSE) down

ps:
	docker ps

clean:
	docker system prune

fclean:
	@echo "$(C_CYAN)Stopping and deleting containers...$(C_RESET)"

	@-docker stop $(shell docker ps -qa) 2>/dev/null || true
	@-docker rm $(shell docker ps -qa) 2>/dev/null || true

	@echo "$(C_CYAN)Deleting images...$(C_RESET)"
	@-docker rmi $(shell docker images -qa) 2>/dev/null || true

	@echo "$(C_CYAN)Deleting volumes...$(C_RESET)"
	@-docker volume rm $(shell docker volume ls -q) 2>/dev/null || true

	@echo "$(C_RESET)$(C_CYAN)Deleting networks...$(C_RESET)"
	@-docker network rm $(shell docker network ls -q) 2>/dev/null || true

	@echo "$(C_RESET)$(C_GREEN)Done!$(C_RESET)\n"

re: down fclean up