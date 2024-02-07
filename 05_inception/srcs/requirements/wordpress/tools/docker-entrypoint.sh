#!/bin/sh

set -e

if [ ! -f /var/www/html/index.php ]; then
  #www-data(소유자):www-data(그룹) 으로 /var/www/html 폴더 소유자, 그룹 변경
  #www-data는 일반적으로 웹 서버 프로세스(예: Apache, Nginx)가 사용하는 기본 사용자 및 그룹입니다.
  #-R : 해당 디렉토리부터 모든 하위 디렉토리 포함

  # drwxr-xr-x 2 www-data www-data 4096 Jan 30 09:20 html
  # drwxr-xr-x 2 root     root     4096 Jan 30 09:26 huipark

  # root:/var# chown -R www-data:www-data /var/www/huipark

  # drwxr-xr-x 2 www-data www-data 4096 Jan 30 09:20 html
  # drwxr-xr-x 2 www-data www-data 4096 Jan 30 09:26 huipark
  chown -R www-data:www-data /var/www/html

  # WP-CLI는 WordPress 사이트를 관리하기 위한 명령줄 도구로, 웹 브라우저를 사용하지 않고도 WordPress 사이트의 여러 측면을 관리할 수 있게 해줌. PHAR는 PHP에서 사용하는 아카이브 형식으로, 여러 PHP 파일을 하나의 파일로 묶어 배포 및 사용을 용이
  wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
  chmod +x wp-cli.phar
  mv wp-cli.phar /usr/local/bin/wp

  # WP-CLI에 WordPress 코어 파일을 다운로드
  wp core download --allow-root
  wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --allow-root
  wp core install --url=https://huipark.42.fr --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL  --allow-root
  wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD --role=author --allow-root
fi


# Docker 컨테이너는 일반적으로 하나의 프로세스(서비스)를 전경에서 실행하는 것을 목표. php-fpm7.4 -F 명령은 이러한 모델에 적합. 이는 PHP-FPM을 전경에서 실행하고, 로그 출력을 표준 출력으로 리디렉션하는 방식으로 작동.
# Systemd와의 호환성 문제: systemctl은 systemd 시스템과 상호작용하는 도구. 하지만 대부분의 Docker 이미지(특히 경량 이미지)는 systemd를 포함하지 않으며, 그렇기 때문에 systemctl 명령은 Docker 컨테이너 내에서 기대한 대로 작동하지 않음. 또한, systemd는 여러 프로세스를 관리하는데, 이는 Docker의 "하나의 컨테이너, 하나의 프로세스" 모델과 상충.

# php-fpm7.4로 실행시 백그라운드에서 실행이 됨
# -F 전경으로 실행
exec "php-fpm7.4" "-F"
# exec "systemctl start php7.4-fpm"
