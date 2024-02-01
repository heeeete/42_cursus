#!/bin/sh

set -e

mkdir -p /etc/nginx/ssl

# -e: 파일이 있으면 참
if [ ! -e /etc/nginx/ssl/huipark.42.fr.crt ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/huipark.42.fr.key -out /etc/nginx/ssl/huipark.42.fr.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=HuiPark/CN=huipark.42.fr"
fi
# -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=HuiPark/CN=huipark.42.fr"

# Country Name (2 letter code) [XX]:​KR
# State or Province Name (full name) []:​Seoul
# Locality Name (eg, city) [Default City]:​MapoGu
# Organization Name (eg, company) [Default Company Ltd]:​Dejay
# Organizational Unit Name (eg, section) []:​Dejay
# Common Name (eg, your name or your server's hostname) []:dejay.com

