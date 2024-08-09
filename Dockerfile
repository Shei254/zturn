FROM alpine:3.20 as builder

RUN apk update --no-cache; \
    apk add --no-cache cmake make gcc musl-dev;

WORKDIR /usr/src/zturn
COPY . .

RUN cmake -B build -DCMAKE_BUILD_TYPE=Release; \
    cd build; \
    make -j2

FROM alpine:3.20 as app

RUN apk update --no-cache; \
    apk add --no-cache musl;

COPY --from=builder /usr/src/zturn/build/zturn /usr/local/bin/

ENTRYPOINT [ "/usr/local/bin/zturn" ]
