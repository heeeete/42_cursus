FROM	debian:bullseye

RUN		apt-get update -y && \
		apt-get -y install \
		mariadb-server

COPY	./conf/my.cnf /etc/mysql/
COPY	./tools/docker-entrypoint.sh /usr/local/bin/

RUN		chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["docker-entrypoint.sh"]
