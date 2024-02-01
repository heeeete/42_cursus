all: setup up

setup:
	@mkdir -p /Users/huipark/data/wordpress
	@mkdir -p /Users/huipark/data/mariadb
	@echo "Data directory created."

up: setup
	@docker compose -f ./srcs/docker-compose.yml up -d --build
	@echo "Containers started."

down:
	@docker compose -f ./srcs/docker-compose.yml down
	@echo "Containers stopped."

clean:
	@docker compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@echo "Containers stopped and images removed."

fclean: clean
	@sudo rm -rf /Users/huipark/data
	@echo "Data directory removed."

re:
	make fclean
	make all

.PHONY: all setup up down clean fclean re
