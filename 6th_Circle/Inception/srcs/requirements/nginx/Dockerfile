FROM debian:bullseye

COPY . .

RUN apt-get update && apt-get install -y nginx openssl

CMD ["/bin/bash", "/tools/nginx_setup.sh"]

EXPOSE 443