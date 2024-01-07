set -e;

# working dir: srcs/requirements/nginx/

# for ssl cert
openssl req -subj "/C=MY/ST=Selangor/L=Subang/O=42 Kuala Lumpur/OU=tlai-an/CN=127.0.0.1/emailAddress=tanlaian2004@gmail.com" \
  -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /conf/nginx-selfsigned.key  \
  -out /conf/nginx-selfsigned.crt;

nginx -c /conf/nginx.conf -g 'daemon off;';