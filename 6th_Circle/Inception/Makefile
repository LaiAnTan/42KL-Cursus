

all: re

build:
	docker compose build

up: build
	docker compose up -d

down:
	docker compose down

prune:
	docker system prune

re: up

# makefile does not currently work