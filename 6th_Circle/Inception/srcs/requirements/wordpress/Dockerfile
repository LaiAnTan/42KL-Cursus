FROM debian:bullseye

COPY . .

RUN apt-get update && apt-get install -y php-fpm php-mysql php-common wget

CMD ["/bin/bash", "/tools/wordpress_setup.sh"]

# ENTRYPOINT ["tail", "-f", "/dev/null"]