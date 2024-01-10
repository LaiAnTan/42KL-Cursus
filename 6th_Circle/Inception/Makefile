C_CYAN = \033[0;96m
C_GREEN = \033[0;92m
C_RESET = \033[0m

DOCKER_COMPOSE := ./srcs/docker-compose.yml

all: re

build:
	docker compose -f $(DOCKER_COMPOSE) build

up: build
	docker compose -f $(DOCKER_COMPOSE) up

down:
	docker compose -f $(DOCKER_COMPOSE) down

ps:
	docker ps

clean:
	docker system prune

fclean:
	@echo "$(C_CYAN)Stopping and deleting containers...$(C_RESET)"

	@-docker stop $(shell docker ps -qa > /dev/null) 2>/dev/null || true
	@-docker rm $(shell docker ps -qa > /dev/null) 2>/dev/null || true

	@echo "$(C_CYAN)Deleting images...$(C_RESET)"
	@-docker rmi $(shell docker images -qa > /dev/null) 2>/dev/null || true

	@echo "$(C_CYAN)Deleting volumes...$(C_RESET)"
	@-docker volume rm $(shell docker volume ls -q > /dev/null) 2>/dev/null || true

	@echo "$(C_RESET)$(C_CYAN)Deleting networks...$(C_RESET)"
	@-docker network rm $(shell docker network ls -q > /dev/null) 2>/dev/null || true

	@echo "$(C_RESET)$(C_GREEN)Done!$(C_RESET)\n"

re: down fclean up