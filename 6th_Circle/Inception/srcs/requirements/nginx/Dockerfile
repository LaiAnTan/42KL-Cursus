FROM debian:bullseye

COPY . .

RUN apt-get update && apt-get install -y nginx openssl

COPY /conf/nginx.conf /etc/nginx/

CMD ["/bin/bash", "/tools/nginx_setup.sh"]

EXPOSE 443