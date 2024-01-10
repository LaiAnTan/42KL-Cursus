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
if [ ! -d "/requirements/wordpress/wpf" ];
then

	mkdir wpf
	echo "wpf created"
fi

if [ -z "$(ls -A /requirements/wordpress/wpf)" ];
then

	wp core download --path=/requirements/wordpress/wpf --allow-root
	echo "core downloaded"

	#dbhost is actually name of wordpress container
	wp core config --path=/requirements/wordpress/wpf --dbhost=mariadb --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASS --allow-root
	echo "wp-config created"

	chmod 644 /requirements/wordpress/wpf/wp-config.php

	wp core install --path=/requirements/wordpress/wpf --url=localhost --title="Gojo Satoru Is Not Dead" --admin_name=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL --allow-root
	echo "core installed"

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