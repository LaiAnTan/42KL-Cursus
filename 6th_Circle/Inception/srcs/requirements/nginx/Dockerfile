FROM debian:bullseye

COPY . .

RUN apt-get update && apt-get install -y nginx openssl

RUN chmod +x ./tools/nginx_setup.sh

CMD ["/bin/bash", "/tools/nginx_setup.sh"]

EXPOSE 443