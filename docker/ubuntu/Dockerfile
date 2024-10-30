FROM ubuntu:22.04 AS base

RUN <<EOF
apt update -y
apt upgrade -y
apt install -y \
	gcc \
	valgrind \
	python3-pip \
	git
pip install pytest
EOF

# Installing
# cmake, g++, git はgoogleテストを導入するのに必要
FROM base as build

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

FROM base as final

RUN <<EOF
	apt install -y \
		nodejs
EOF

# User
ARG UID=10001
RUN adduser \
    --disabled-password \
    --gecos "" \
    --uid "${UID}" \
    appuser
USER appuser

COPY --from=build googletest/googlemock/include/gmock /usr/local/include/gmock
COPY --from=build googletest/googletest/include/gtest /usr/local/include/gtest
COPY --from=build googletest/build/lib/*.a /usr/local/lib/

WORKDIR /home/appuser
