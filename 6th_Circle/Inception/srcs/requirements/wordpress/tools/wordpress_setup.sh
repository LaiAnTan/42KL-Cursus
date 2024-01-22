#!bin/bash

# install wordpress cli
if [ ! -a "wp-cli.phar" ];
then
	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

	# make it so that we can run the exe with just 'wp'
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/local/bin/wp
fi

# install and config wordpress
if [ ! -d "/var/www/html/wordpress" ];
then

	mkdir /var/www/html/wordpress
	echo "directory created"
fi

if [ -z "$(ls -A /var/www/html/wordpress)" ];
then

	wp core download --path=/var/www/html/wordpress --allow-root
	echo "core downloaded"

	#dbhost is actually name of wordpress container
	wp core config --path=/var/www/html/wordpress --dbhost=mariadb --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASS --allow-root
	echo "wp-config created"

	chmod 644 /requirements/wordpress/wpf/wp-config.php

	wp core install --path=/var/www/html/wordpress --url=localhost --title="Gojo Satoru Is Not Dead" --admin_name=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL --allow-root
	echo "core installed"

	wp user create --path=/var/www/html/wordpress $WP_USER $WP_EMAIL --user_pass=$WP_PASS --role=author --allow-root

	wp install theme twentytwentytwo --activate --allow-root

fi

# config php-fpm
sed -i 's;listen = /run/php/php7.4-fpm.sock;listen = 9000;' /etc/php/7.4/fpm/pool.d/www.conf

mkdir -p /run/php

# start php fastcgi process manager
# -F means foreground
# -R means root
echo "Running php-fpm7.4"
php-fpm7.4 -F -R

# warning if php updates this breaks