FROM debian:bullseye

RUN apt-get update -y && \
    apt-get install -y \
    php7.4-fpm \
    php-mysql \
    mariadb-client \
    wget

# 아래 경로를 만들지 않고 실행시(php-fpm7.4 -F) 에러
# [30-Jan-2024 11:07:09] ERROR: Unable to create the PID file (/run/php/php7.4-fpm.pid).: No such file or directory (2)
# [30-Jan-2024 11:07:09] ERROR: FPM initialization failed
# 백그라운드로 php 실행시(php-fpm7.4) 종료법(killall php-fpm7.4)
RUN mkdir /run/php

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/docker-entrypoint.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/docker-entrypoint.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT [ "docker-entrypoint.sh" ]
