FROM ubuntu:22.04 AS base

RUN <<EOF
apt update -y
apt upgrade -y
apt install -y \
	gcc \
	valgrind \
	python3-pip \
	git \
	libreadline-dev
pip install pytest
EOF

# Installing
# cmake, g++, git はgoogleテストを導入するのに必要
FROM base AS build

RUN <<EOF
	apt install -y \
		cmake \
		g++
EOF

RUN git clone https://github.com/google/googletest.git && \
	cd googletest && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	cp -r ../googlemock/include/gmock /usr/local/include/gmock && \
	cp -r ../googletest/include/gtest /usr/local/include/gtest && \
	cp lib/*.a /usr/local/lib/

FROM base AS final

# User
ARG UID=10001
RUN adduser \
    --disabled-password \
    --gecos "" \
    --uid "${UID}" \
    minishell

COPY --from=build googletest/googlemock/include/gmock /usr/local/include/gmock
COPY --from=build googletest/googletest/include/gtest /usr/local/include/gtest
COPY --from=build googletest/build/lib/*.a /usr/local/lib/


# テスト用の環境
FROM final AS test

USER minishell
WORKDIR /home/minishell

# デバッグ用の環境
FROM final AS debug

ARG NORM_VERSION=3.3.51

RUN <<EOF
apt-get update -y
apt-get upgrade -y
apt-get install -y \
	lldb
pip install \
	norminette==${NORM_VERSION}
EOF
