FROM ubuntu:22.04

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN  apt-get update \
  && apt-get -y install build-essential cmake curl

RUN apt-get -y install qtbase5-dev

RUN  curl -L -o linuxdeploy https://github.com/linuxdeploy/linuxdeploy/releases/download/1-alpha-20240109-1/linuxdeploy-x86_64.AppImage \
  && chmod +x linuxdeploy \
  && mv linuxdeploy /usr/local/bin \
  && apt-get -y install file fuse

ARG USERNAME=bob
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN    groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME

