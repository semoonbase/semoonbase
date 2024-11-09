FROM debian:slim

RUN apt-get update && apt-get install -y \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace

ARG USERNAME = dev
ARG USER_UID = 1000

RUN adduser --disabled-password --gecos "" --shell /bin/bash $USERNAME
RUN chown -R $USERNAME:$USERNAME /workspace

USER $USERNAME