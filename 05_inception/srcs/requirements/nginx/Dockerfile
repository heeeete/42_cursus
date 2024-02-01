FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y \
    nginx \
    openssl

COPY ./conf/default /etc/nginx/sites-available/
COPY ./tools/ssl-keygen.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/ssl-keygen.sh
RUN ssl-keygen.sh

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
