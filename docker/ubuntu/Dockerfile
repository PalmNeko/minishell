FROM ubuntu:22.04

# Installing
# cmake, g++, git はgoogleテストを導入するのに必要

RUN <<EOF
apt update -y
apt upgrade -y
apt install -y \
	gcc \
	valgrind \
	python3-pip \
	cmake \
	git
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
cp -r ../googlemock/include/gmock /usr/local/include/gmock
cp -r ../googletest/include/gtest /usr/local/include/gtest
cp lib/*.a /usr/local/lib/
pip install pytest

EOF

# User
ARG UID=10001
RUN adduser \
    --disabled-password \
    --gecos "" \
    --uid "${UID}" \
    appuser
USER appuser
WORKDIR /home/appuser
