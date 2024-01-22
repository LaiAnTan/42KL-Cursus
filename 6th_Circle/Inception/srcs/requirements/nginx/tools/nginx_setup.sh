#!bin/bash

# working dir: srcs/requirements/nginx/

# for ssl cert
# -subj to specify details and makes it so that openssl req wont prompt
openssl req -subj "/C=$C/ST=$ST/L=$L/O=$O/OU=$OU/CN=$CN/emailAddress=$EMAIL_ADDRESS" \
  -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/ssl/private/nginx-selfsigned.key  \
  -out /etc/ssl/certs/nginx-selfsigned.crt;

# daemon off runs it in foreground
# -c specifies config to use (dont need if copied config into dir)
nginx -g 'daemon off;';