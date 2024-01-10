#!bin/bash

# create admin user (localhost and all hosts)
# grant admin user all privs (localhost and all hosts)
# add password to root
# create wordpress db
echo "
FLUSH PRIVILEGES;
CREATE USER IF NOT EXISTS $DB_USER@localhost IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON *.* TO $DB_USER@localhost IDENTIFIED BY '$DB_PASS' WITH GRANT OPTION;
CREATE USER IF NOT EXISTS $DB_USER@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON *.* TO $DB_USER@'%' IDENTIFIED BY '$DB_PASS' WITH GRANT OPTION;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
CREATE DATABASE IF NOT EXISTS $DB_NAME;
FLUSH PRIVILEGES;
" > setup.sql

# insert sql file into server for setup
# bootstrap allows for running sql commands without starting server
mysqld --bootstrap < setup.sql

# need to enable port 3306 and change bind address
# mariadb reads from these config files: /etc/my.cnf /etc/mysql/my.cnf ~/.my.cnf
sed -i 's/# port = 3306/port = 3306/' /etc/mysql/my.cnf
sed -i "s/127.0.0.1/0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

# runs mariadb in the foreground
# & argument runs it in background
mysqld_safe