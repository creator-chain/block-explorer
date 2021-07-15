FROM nginx:stable-alpine

# The following is mainly for doc purpose to show which ENV is supported
ENV WS_URL=

RUN apk add --no-cache bash

WORKDIR /usr/share/nginx/html
COPY env.sh .
COPY packages/apps/build/ .
COPY docker/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD ["/bin/bash", "-c", "/usr/share/nginx/html/env.sh && nginx -g \"daemon off;\""]
