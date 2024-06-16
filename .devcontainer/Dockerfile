FROM debian:bullseye

RUN groupadd --gid 1000 dev \
    && useradd -s /bin/bash --uid 1000 --gid 1000 -m dev \
    && apt-get update \
    && apt-get install -y --no-install-recommends \
    build-essential zip unzip \
    git openssh-client \
    python3 python3-pip \
    nodejs npm \
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/* \
    && npm install -g @bazel/bazelisk @bazel/ibazel \
    && npm cache clean --force \
    && python3 -m pip install -U --no-cache-dir platformio
