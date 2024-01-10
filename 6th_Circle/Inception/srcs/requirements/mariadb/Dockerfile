FROM debian:bullseye

COPY . .

RUN apt-get update && apt-get install -y mariadb-server

CMD ["/bin/bash", "/tools/mariadb_setup.sh"]