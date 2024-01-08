
# create admin user
# grant admin user all privs
# add password to root
# create wordpress db
echo "
FLUSH PRIVILEGES;
CREATE USER $DB_USER@localhost IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON *.* TO $DB_USER@localhost IDENTIFIED BY '$DB_PASS';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';
CREATE DATABASE wordpress;
FLUSH PRIVILEGES;
" > setup.sql

# insert sql file into server for setup
# bootstrap allows for running sql commands without starting server
mysqld --bootstrap < setup.sql

# runs mariadb in the foreground
# & argument runs it in background
mysqld_safe